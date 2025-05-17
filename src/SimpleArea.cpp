//
// Created by Maciek Dawiec on 17/05/2025.
//
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>
#include <ranges>

#include <cmath>


// main program
int main()
{
    std::vector<int> numbers = {2, 4, 3, 6, 7, 5};
    const auto numbersSize { numbers.size() };
    const auto numbersMax = *std::ranges::max_element(numbers);

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Title", sf::State::Windowed, settings);

    sf::CircleShape dot;
    dot.setFillColor(sf::Color(0, 170, 255));

    sf::RectangleShape line;
    line.setFillColor(sf::Color(0, 170, 255));

    sf::ConvexShape area;
    area.setPointCount(4);
    area.setFillColor(sf::Color(0, 127, 191));

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
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

            auto window_w   = window.getView().getSize().x;
            auto window_h   = window.getView().getSize().y;
            const auto window_min = std::min(window_w, window_h);

            const auto space  = window_w / (numbersSize - 1);
            const auto scale  = 0.9f * window_h / numbersMax;
            auto radius = 0.02f * window_min;
            auto width  = radius * 2;

            window.clear(sf::Color(64, 64, 64));

            dot .setRadius(radius);
            dot .setOrigin({radius, radius});
            line.setOrigin({0.f, width / 2});
            float x_old;
            float y_old;
            for (int i = 0;  i < numbersSize;  i++)
            {
                const auto x = i * space;
                const auto y = window_h - (numbers.at(i) * scale);
                if (i > 0)
                {
                    area.setPoint(0, {x_old, window_h});
                    area.setPoint(1, {x_old, y_old});
                    area.setPoint(2, {x, y});
                    area.setPoint(3, {x, window_h});
                    window.draw(area);
                }
                x_old = x;
                y_old = y;
            }
            for (int i = 0;  i < numbersSize;  i++) {
                float x = i * space;
                float y = window_h - (numbers.at(i) * scale);
                dot.setPosition({x, y});
                window.draw(dot);
                if (i > 0)
                {
                    float dx     = x_old - x;
                    float dy     = y_old - y;
                    float angle  = std::atan2(dy, dx);
                    float length = std::sqrt(dx*dx + dy*dy);
                    line.setSize({length, width});
                    line.setRotation(sf::radians(angle));
                    line.setPosition({x, y});
                    window.draw(line);
                }
                x_old = x;
                y_old = y;
            }
            window.display();
        }
    }
    return 0;
}