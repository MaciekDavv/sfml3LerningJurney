#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    window.setVerticalSyncEnabled(true);
    //sf::WindowHandle handle = window.getNativeHandle();

    sf::RectangleShape shape({400.f, 200.f});
    shape.setOrigin({200.f, 100.f});

    shape.setFillColor(sf::Color::Green);
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color::Blue);

    shape.setPosition({300.f, 200.f});
    shape.setRotation(sf::degrees(45.f));

    sf::View view(sf::FloatRect(sf::Vector2f({0.f, 0.f}), sf::Vector2f({800.f, 600.f})));
    window.setView(view);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto* kayPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (kayPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }
            } else if (event->is<sf::Event::Resized>()) {
                const auto size = window.getSize();
                float aspectRation = static_cast<float>(size.x) / size.y;
                view.setSize({800.f * aspectRation, 600.f});
                window.setView(view);
            }
        }
        window.clear(sf::Color(150.f, 12.f, 78.f));

        window.draw(shape);

        window.display();
    }
}