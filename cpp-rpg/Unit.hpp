#pragma once

#include <ratio>

template <typename T, typename... U>
class Unit;

template <typename T>
class Unit<T> {
private:
	T value;
public:
	Unit(T value) : value(value) { }
	operator T() { return value; }
	T getValue() const { return value; }
	auto& operator+=(T other) {
		value += other;
		return *this;
	}
	auto& operator-=(T other) {
		value -= other;
		return *this;
	}
	auto& operator*=(T other) {
		value *= other;
		return *this;
	}
	auto& operator/=(T other) {
		value /= other;
		return *this;
	}
};

namespace {
	template<typename T>
	struct Sentinel { };

	template <typename T, typename U, typename... Rest>
	class Unit<T, Sentinel<U>, Rest...> {
	private:
		T value;
	public:
		explicit Unit(T value) : value(value) { }
		operator T() { return value; }
		T getValue() const { return value; }
	};
}


template <typename T, intmax_t N, intmax_t D, typename U, typename... Rest>
class Unit<T, std::ratio<N, D>, U, Rest...> {
private:
	T value;
public:
	explicit Unit(T value) : value(value) { }
	T getValue() const { return value; }

	template <typename... Rest2>
	auto& operator+=(const Unit<T, std::ratio<N, D>, U, Rest2...> &other) {
		Unit<T, Rest...> thisBase(value);
		Unit<T, Rest2...> otherBase(other.getValue());
		thisBase += otherBase;
		value = thisBase.getValue();
		return *this;
	}
	template <intmax_t N2, intmax_t D2, typename U2, typename... Rest2>
	auto& operator+=(const Unit<T, std::ratio<N2, D2>, U2, Rest2...> &other) {
		Unit<T, Rest2..., Sentinel<Unit<T, std::ratio<N, D>, U, Rest...>>, std::ratio<N2, D2>, U2> otherNext(other.getValue());
		return operator+=(otherNext);
	}
	template <typename Other, typename... Rest2>
	auto& operator+=(const Unit<T, Sentinel<Other>, Rest2...> &other) {
		Unit<T, Rest2...> otherNext(other.getValue());
		return operator+=(otherNext);
	}
	auto& operator+=(const Unit<T> &other) {
		static_assert(false, "Cannot add dimensionless units to dimensioned units!");
	}
	template <intmax_t N2, intmax_t D2, typename... Rest2>
	auto& operator+=(const Unit<T, std::ratio<N2, D2>, U, Rest2...> &other) {
		static_assert(false, "Cannot add units with different exponents!");
	}
	template <typename... Rest2>
	auto& operator+=(const Unit<T, Sentinel<Unit<T, std::ratio<N, D>, U, Rest...>>, Rest2...> &other) {
		static_assert(false, "Cannot add different units!");
	}

	template <typename... Rest2>
	auto& operator-=(const Unit<T, std::ratio<N, D>, U, Rest2...> &other) {
		Unit<T, Rest...> thisBase(value);
		Unit<T, Rest2...> otherBase(other.getValue());
		thisBase -= otherBase;
		value = thisBase.getValue();
		return *this;
	}
	template <intmax_t N2, intmax_t D2, typename U2, typename... Rest2>
	auto& operator-=(const Unit<T, std::ratio<N2, D2>, U2, Rest2...> &other) {
		Unit<T, Rest2..., Sentinel<Unit<T, std::ratio<N, D>, U, Rest...>>, std::ratio<N2, D2>, U2> otherNext(other.getValue());
		return operator-=(otherNext);
	}
	template <typename Other, typename... Rest2>
	auto& operator-=(const Unit<T, Sentinel<Other>, Rest2...> &other) {
		Unit<T, Rest2...> otherNext(other.getValue());
		return operator-=(otherNext);
	}
	auto& operator-=(const Unit<T> &other) {
		static_assert(false, "Cannot subtract dimensionless units from dimensioned units!");
	}
	template <intmax_t N2, intmax_t D2, typename... Rest2>
	auto& operator-=(const Unit<T, std::ratio<N2, D2>, U, Rest2...> &other) {
		static_assert(false, "Cannot subtract units with different exponents!");
	}
	template <typename... Rest2>
	auto& operator-=(const Unit<T, Sentinel<Unit<T, std::ratio<N, D>, U, Rest...>>, Rest2...> &other) {
		static_assert(false, "Cannot subtract different units!");
	}

	auto& operator*=(T other) {
		value *= other;
		return *this;
	}
	auto& operator/=(T other) {
		value /= other;
		return *this;
	}
};

namespace {
	template<typename R, typename U, typename T, typename... Rest>
	auto prependUnit(Unit<T, Rest...> unit) {
		return Unit<T, R, U, Rest...>(unit.getValue());
	}
}

template<typename T, intmax_t N, intmax_t D, typename U, typename... Rest, typename... Rest2>
auto operator*(Unit<T, std::ratio<N, D>, U, Rest...> a, Unit<T, std::ratio<-N, D>, U, Rest2...> b) {
	Unit<T, Rest...> aNext(a.getValue());
	Unit<T, Rest2...> bNext(b.getValue());
	return aNext * bNext;
}
template<typename T, intmax_t N, intmax_t N2, intmax_t D, intmax_t D2, typename U, typename... Rest, typename... Rest2>
auto operator*(Unit<T, std::ratio<N, D>, U, Rest...> a, Unit<T, std::ratio<N2, D2>, U, Rest2...> b) {
	Unit<T, Rest...> aNext(a.getValue());
	Unit<T, Rest2...> bNext(b.getValue());
	auto nextProduct = aNext * bNext;
	return prependUnit<std::ratio_add<std::ratio<N, D>, std::ratio<N2, D2>>, U>(nextProduct);
}
/*
template <typename T, typename... Rest>
class Unit<T, Rest...> {
	// Condition can't be satisfied since Unit<T> is a better resolution, but false triggers the
	// assert even if the template is never instantiated...
	static_assert(0 == sizeof...(Rest), "Cannot operate on non-matching units!");
};*/