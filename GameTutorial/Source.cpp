#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

int main()
{
    // Creation
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mario");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::RectangleShape rect;
    rect.setFillColor(sf::Color::Red);
    int mousePositionX = 0.f;
    int mousePositionY = 0.f;

    bool drawingActive = false;
    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        // Events
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || 
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
            {
                mousePositionX = event.mouseButton.x;
                mousePositionY = event.mouseButton.y;
                drawingActive = true;
                rect.setPosition(mousePositionX, mousePositionY);
                std::cout << " X : " << mousePositionX << " Y : "<< mousePositionY << std::endl;
            }

            if (event.type == sf::Event::MouseMoved)
            {
                if (drawingActive)
                {
                    int xSize = event.mouseMove.x - mousePositionX;
                    int ySize = event.mouseMove.y - mousePositionY;

                    rect.setSize(sf::Vector2f(xSize, ySize));
                }
            }

            if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                drawingActive = false;
            }
        }

        // Logic

        // Rendering
        window.clear();

        if (drawingActive)
        {
            window.draw(rect);
        }

        window.display();
    }

    // Clean up
    window.close();

    return 0;
}