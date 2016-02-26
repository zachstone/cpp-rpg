#pragma once

#include <cmath>
#include <stdint.h>
#include <assert.h>

template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}

template <typename T> T abs(T val) {
  return sgn(val) * val;
}

// Assumes a and b are non-negative
template <typename T> T gcd(T a, T b) {
  if (a > b) {
    return gcd(b, a);
  }
  if (T(0) == a) {
    if (T(0) == b) {
      return T(1);
    }
    return b;
  }
  return gcd(b % a, a);
}

template <int width>
class Rational;

template <>
class Rational<64> {
  int32_t a_;
  int32_t b_;
  void reduce() {
    int32_t d = gcd(abs(a_), abs(b_));
    a_ /= sgn(b_) * d;
    b_ /= sgn(b_) * d;
  }
public:
  Rational(int32_t a, int32_t b = 1) : a_(a), b_(b) {
    assert(b_);
    reduce();
  }
  int32_t a(void) const {
    return a_;
  }
  int32_t b(void) const {
    return b_;
  }

  operator int32_t() const { return a_ / b_; }
  Rational<64>& operator+=(const Rational<64> &q) {
    a_ = a_ * q.b() + q.a() * b_;
    b_ *= q.b();
    reduce();
    return *this;
  }
  Rational<64>& operator-=(const Rational<64> &q) {
    a_ = a_ * q.b() - q.a() * b_;
    b_ *= q.b();
    reduce();
    return *this;
  }
  Rational<64>& operator*=(const Rational<64> &q) {
    a_ *= q.a();
    b_ *= q.b();
    reduce();
    return *this;
  }
  Rational<64>& operator/=(const Rational<64> &q) {
    a_ *= q.b();
    b_ *= q.a();
    reduce();
    return *this;
  }
};

template<int width>
Rational<width> operator+(Rational<width> p, const Rational<width> &q) {
  p += q;
  return p;
}
template<int width>
Rational<width> operator-(Rational<width> p, const Rational<width> &q) {
  p -= q;
  return p;
}
template<int width>
Rational<width> operator*(Rational<width> p, const Rational<width> &q) {
  p *= q;
  return p;
}
template<int width>
Rational<width> operator/(Rational<width> p, const Rational<width> &q) {
  p /= q;
  return p;
}
template<int width>
Rational<width> operator==(const Rational<width> &p, const Rational<width> &q) {
  return p.a() == q.a() && p.b() == q.b();
}

typedef Rational<64> rat64_t;
