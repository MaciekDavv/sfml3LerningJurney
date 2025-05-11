#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

sf::RectangleShape createRectangleToGrid(float originX, float originY)
{
    sf::RectangleShape rectangle({200.f, 100.f});
    rectangle.setOrigin({originX, originY});
    return rectangle;
}

int main()
{
    //namespace ranges = std::ranges;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    auto topLeft = createRectangleToGrid(0.f, 0.f);
    auto topRight = createRectangleToGrid(200.f, 0.f);
    auto bottomLeft = createRectangleToGrid(0.f, 100.f);
    auto bottomRighat = createRectangleToGrid(200.f, 100.f);
    auto top = createRectangleToGrid(100.f, 0.f);
    auto right = createRectangleToGrid(200.f, 50.f);
    auto left = createRectangleToGrid(0.f, 50.f);
    auto bottom = createRectangleToGrid(100.f, 100.f);
    auto center = createRectangleToGrid(100.f, 50.f);

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
        
        float windowHeight = static_cast<float>(window.getSize().y);
        float windowWidth = static_cast<float>(window.getSize().x);

        topRight.setPosition({windowWidth, 0.f});
        bottomLeft.setPosition({0.f, windowHeight});
        bottomRighat.setPosition({windowWidth, windowHeight});
        top.setPosition({windowWidth / 2.f, 0.f});
        right.setPosition({windowWidth, windowHeight / 2.f});
        left.setPosition({0, windowHeight / 2.f});
        bottom.setPosition({windowWidth / 2.f, windowHeight});
        center.setPosition({windowWidth / 2.f, windowHeight / 2.f});
        
        window.clear(sf::Color::Black);

        window.draw(topLeft);
        window.draw(topRight);
        window.draw(bottomLeft);
        window.draw(bottomRighat);
        window.draw(top);
        window.draw(right);
        window.draw(left);
        window.draw(bottom);
        window.draw(center);

        window.display();
    }
}