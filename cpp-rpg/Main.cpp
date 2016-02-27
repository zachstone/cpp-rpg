#include <iostream>
#include <memory>

#include "SFML/Graphics.hpp"

#include "Player.hpp"
#include "Rational.hpp"
#include "Item.hpp"
#include "Unit.hpp"

typedef void (*eventHandler_t)(const std::unique_ptr<sf::RenderWindow> &);
typedef eventHandler_t eventHandlers_t[sf::Event::Count];

auto renderLoop(const std::unique_ptr<sf::RenderWindow> &pWindow, const eventHandlers_t &eventHandlers) {
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (pWindow->isOpen())
	{
		pWindow->clear();
		pWindow->draw(shape);
		pWindow->display();

		sf::Event event;
		while (pWindow->pollEvent(event))
		{
			if (eventHandlers[event.type]) {
				eventHandlers[event.type](pWindow);
			}
		}
	}
}

auto registerEventHandlers(eventHandlers_t &eventHandlers) {
	eventHandlers[sf::Event::Closed] = [](const auto &pWindow) { pWindow->close(); };
}

auto createWindow() {
	std::unique_ptr<sf::RenderWindow> pWindow(new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!"));
	pWindow->setFramerateLimit(60);
	return pWindow;
}

auto main() -> int {
	auto pWindow = createWindow();

	eventHandlers_t eventHandlers = { nullptr };
	registerEventHandlers(eventHandlers);
	
	renderLoop(pWindow, eventHandlers);

	return 0;
}

auto cmdOutput() {
  auto player = Player();
  auto item = Item("Magic Boots", 274, Position{ 78.3, 23.9 });
  player.levelUp();
  player.addItem(item);

  std::cout << player.getLevel()
            << std::endl
            << player.getName()
            << std::endl;

  player.step(Position{ 10.0, 5.0 });
  std::cout << player.getPosition().x << std::endl
            << player.getPosition().y << std::endl;

  std::cout << player.printInventory() << std::endl;

  auto p = rat64_t(1, 2);
  p += 5;
  std::cout << p.a() << " " << p.b() << std::endl;

  typedef struct { } Meter;
  typedef struct { } Second;
  typedef struct { } Kilogram;
  auto u = Unit<double, std::ratio<1, 1>, Meter, std::ratio<-1, 1>, Second, std::ratio<1, 1>, Kilogram>(1);
  auto u2 = Unit<double, std::ratio<1, 1>, Meter, std::ratio<1, 1>, Kilogram, std::ratio<-1, 1>, Second>(1);
  auto u3 = Unit<double, std::ratio<-1, 1>, Second, std::ratio<1, 1>, Meter, std::ratio<1, 1>, Kilogram>(1);
  auto u4 = Unit<double, std::ratio<-1, 1>, Second, std::ratio<1, 1>, Kilogram, std::ratio<1, 1>, Meter>(1);
  auto u5 = Unit<double, std::ratio<1, 1>, Kilogram, std::ratio<-1, 1>, Second, std::ratio<1, 1>, Meter>(1);
  auto u6 = Unit<double, std::ratio<1, 1>, Kilogram, std::ratio<1, 1>, Meter, std::ratio<-1, 1>, Second>(1);
  // auto v = Unit<double, std::ratio<-1, 1>, Second, std::ratio<1, 1>, Meter>(2);
  u += u;
  u += u2;
  u += u3;
  u += u4;
  u += u5;
  u += u6;
  u2 += u;
  u2 += u2;
  u2 += u3;
  u2 += u4;
  u2 += u5;
  u2 += u6;
  u3 += u;
  u3 += u2;
  u3 += u3;
  u3 += u4;
  u3 -= u5;
  u3 += u6;
  u4 += u;
  u4 += u2;
  u4 += u3;
  u4 += u4;
  u4 += u5;
  u4 += u6;
  u5 += u;
  u5 += u2;
  u5 += u3;
  u5 += u4;
  u5 += u5;
  u5 += u6;
  u6 += u;
  u6 += u2;
  u6 += u3;
  u6 += u4;
  u6 += u5;
  u6 += u6;
}
