//
// Created by Maciek Dawiec on 17/05/2025.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 12;
	sf::RenderWindow window(sf::VideoMode({800, 600}), "title", sf::State::Windowed, settings);


	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>()) {
				window.close();
			} else if (const auto* kayPressed = event->getIf<sf::Event::KeyPressed>()) {
				if (kayPressed->scancode == sf::Keyboard::Scancode::Escape) {
					window.close();
				}
			} else if (event->is<sf::Event::Resized>()) {
				sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
				window.setView(view);
			}
		}
		auto window_w   = window.getView().getSize().x;
		auto window_h   = window.getView().getSize().y;
		auto window_min = (window_w < window_h) ? window_w : window_h;
		///////////////////////////////

		window.clear(sf::Color::Black);

		window.draw();

		window.display();
		////////////////////////////////////
	}
}