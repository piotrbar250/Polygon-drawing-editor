#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1152, 720), "SFML works!");

    sf::Vertex vertices[20];

    for(int i = 0; i < 20; i++)
    {
        vertices[i] = sf::Vertex(Vector2f(600 + i, 600));
        vertices[i].color = sf::Color::Red;
    }

    sf::RectangleShape rect(Vector2f(1,1));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(Vector2f(601, 600));

    int i = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(vertices, 1, sf::Points);
        window.draw(rect);
        window.display();
    }
    return 0;
}
