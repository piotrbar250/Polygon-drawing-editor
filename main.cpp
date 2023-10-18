// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <cmath>
// using namespace sf;
// using namespace std;

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(1152, 720), "Polygon editor");

//     Vertex nodes[20];
//     int n;

//     bool segmentOn = false;

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//             if (event.type == sf::Event::MouseButtonPressed)
//             {
//                 cout << "hello" << endl;
//                 // nodes[n++] = Vertex(Vector2f(event.mouseButton.x, event.mouseButton.y));
//                 nodes[0] = Vertex(Vector2f(event.mouseButton.x, event.mouseButton.y));
//                 segmentOn = true;
                


//                 // if(!segmentOn)
//                 //     segmentOn = true;
//                 // else
//                 // {
//                 //     segmentOn = false;

//                 // }
//             }
//         }

//         window.clear();

//         if(segmentOn)
//         {
//             nodes[1] = Vector2f(Mouse::getPosition(window));
//             cout << nodes[1].position.x << " " << nodes[1].position.y << endl;
            
//             float x1 = nodes[0].position.x;
//             float y1 = nodes[0].position.y;

//             float x2 = nodes[1].position.x;
//             float y2 = nodes[1].position.y;

//             float len = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
//             float angle_rad = atan2(y1-y2, x2-x1);
//             float angle_deg = angle_rad * 180.0 / M_PI;

//             RectangleShape segment(Vector2f(len, 5));
//             segment.setPosition(Vector2f(x1, y1));
//             segment.rotate(-angle_deg);
//             segment.setFillColor(Color(235, 222, 52));
//             window.draw(segment);
//         }   
//         for(int i = 0; i < n; i++)
//         {
//             CircleShape node(5);
//             node.setFillColor(Color::Green);
//             node.setPosition(nodes[i].position.x, nodes[i].position.y);
//             window.draw(node);
//         }

//         // for(int i = 0; i < 1; i++)
//         // {
//         //     window.draw(&nodes[i], 1, sf::Points);
//         // }

        
//         window.display();
//     }
//     return 0;
// }

#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    // Create a window with a resolution of 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "Draw Circle on Button Press");

    std::vector<sf::CircleShape> circles;

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Check for mouse button press
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Create a circle with radius 5
                    sf::CircleShape circle(5);
                    circle.setFillColor(sf::Color::Green);

                    // Set the position of the circle to the mouse button press position
                    circle.setPosition(event.mouseButton.x - 5, event.mouseButton.y - 5);

                    // Add the circle to the list of circles
                    circles.push_back(circle);
                }
            }
        }

        // Clear the window
        window.clear();

        // Draw all the circles
        for (const auto& circle : circles)
        {
            window.draw(circle);
        }

        // Display the contents of the window
        window.display();
    }

    return 0;
}
