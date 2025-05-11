#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>



int main()
{
    std::vector<int> data{56, 81, 24, 55, 11};
    auto dataN{ data.size() };
    auto dataMax{ *std::max_element(data.begin(), data.end()) };

    sf::RenderWindow window(sf::VideoMode({800, 600}), "title");

    sf::RectangleShape bar;
    bar.setFillColor(sf::Color::White);

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

        float size{ 0.6f * windowWidth / dataN };
        float scale{ 0.9f * windowHeight / dataMax };
        float space{ windowWidth / dataN };

        window.clear(sf::Color::Black);

        bar.setOrigin( {size / 2.f, 0.f} );
        bar.setScale( {1.f, -1.f} );
        for (size_t i = 0; i < dataN; i++) {
            bar.setSize( {size, data[i] * scale} );
            bar.setPosition( {(i + 0.5f) * space, windowHeight} );
            window.draw(bar);
        }


        window.display();
    }
}