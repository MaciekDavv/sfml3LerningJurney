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

    sf::CircleShape circle(200.f, 60);
    circle.setFillColor(sf::Color(245, 123, 12));
    circle.setOutlineColor(sf::Color(200, 100, 100));
    circle.setOutlineThickness(30.f);
    circle.setOrigin( {circle.getRadius(), circle.getRadius()} );
    circle.setPosition( {window.getSize().x / 2.f, window.getSize().y / 2.f} );
    // circle.setScale( {1.5f, -1.f} );
    // circle.setRotation(sf::degrees(45.f));

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
        float windowWidth = static_cast<float>(window.getSize().x);
        float windowHeight = static_cast<float>(window.getSize().y);
///////////////////////////////

        window.clear(sf::Color::Black);

        window.draw(circle);

        window.display();
////////////////////////////////////
    }
}