//
// Created by Maciek Dawiec on 14/05/2025.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 4;
	sf::RenderWindow window(sf::VideoMode({800, 600}), "My window", sf::State::Windowed, settings);



	sf::ConvexShape shape;
	shape.setFillColor(sf::Color::Green);
	shape.setOutlineColor(sf::Color::Blue);
	shape.setPosition({400.f, 300.f});
	const size_t n = 8 * 6;
	float radius = 200.f;
	float angle = 360.f / n;
	shape.setPointCount(n);
	for (size_t i = 0; i < shape.getPointCount(); i++) {
		if (i % 6 > 1 ) {
			shape.setPoint(i, sf::Vector2f(radius, sf::degrees(i * angle - 90.f)));
		} else {
			shape.setPoint(i, sf::Vector2f(radius - 150.f, sf::degrees(i * angle - 90.f)));
		}
	}





	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			} else if (const auto *kayPressed = event->getIf<sf::Event::KeyPressed>()) {
				if (kayPressed->scancode == sf::Keyboard::Scancode::Escape) {
					window.close();
				}
			}
			window.clear(sf::Color::Black);
			window.draw(shape);
			window.display();
		}
	}
}
