#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>


int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Line Chart", sf::State::Windowed, settings);

    std::vector<int> dots{1, 3, 5, 2, 8, 4, 9, 23, 45, 2, 12, 83};
    auto dotsN{ dots.size() };
    auto dotsMax{ *std::max_element(dots.begin(), dots.end()) };

    sf::CircleShape dot;
    dot.setFillColor(sf::Color(245, 123, 12));

    sf::RectangleShape line;
    line.setFillColor(sf::Color(245, 123, 12));

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

        auto windowWidth = window.getView().getSize().x;
        auto windowHeight = window.getView().getSize().y;
        auto windowMin{ std::min(windowWidth, windowHeight) };

        auto spacex{ windowWidth / dotsN};
        auto scale{ 0.9f * windowHeight / dotsMax };
        auto radius{ 0.02f * windowMin };
        auto width{ radius * 2 };

        window.clear(sf::Color::Black);

        dot.setRadius(radius);
        dot.setOrigin( {radius, radius} );
        line.setOrigin( {0.f, width / 2} );

        float xOld;
        float yOld;

        for(size_t i = 0; i < dotsN; i++) {
            auto x{ (i + 0.5f) * spacex };
            auto y{ windowHeight - (dots[i] * scale) };
            dot.setPosition( {x, y} );
            window.draw(dot);
            if (i > 0) {
                auto dx{ xOld - x };
                auto dy{ yOld - y };
                auto angle{ std::atan2(dy, dx) };
                auto length{ static_cast<float>(std::sqrt(std::pow(dx, 2) + std::pow(dy, 2))) };
                line.setSize({ length, width } );
                line.setRotation(sf::radians(angle));
                line.setPosition({x, y});
                window.draw(line);
            }
            xOld = x;
            yOld = y;
        }
        window.display();
    }
}
