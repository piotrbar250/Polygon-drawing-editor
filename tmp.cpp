#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1400, 700), "SFML works!");


    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);

    sf::RectangleShape rect(sf::Vector2f(200, 20));
    rect.move(sf::Vector2f(300, 300));
    rect.rotate(-30);
    shape.move(sf::Vector2f(100, 0));

    sf::Vertex point (sf::Vector2f(300, 300));
    point.color = sf::Color::Green;

    sf::Vertex vertices[20];

    for(int i = 0; i < 20; i++)
    {
        vertices[i] = sf::Vertex(Vector2f(600 + i, 600));
        vertices[i].color = sf::Color::Red;
    }

    int i = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == Event::MouseButtonPressed)
            {
                cout << event.mouseButton.x << " " << event.mouseButton.y << endl;
            }
            if(event.type == Event::KeyPressed)
            {
                cout << event.key.code << endl;
            }
        }

        window.clear();
        window.draw(shape);
        window.draw(rect);
        window.draw(vertices, 2, sf::Quads);
        window.display();
    }
    return 0;
}
