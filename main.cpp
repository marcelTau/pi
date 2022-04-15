#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <math.h>
#include <iostream>

int total = 0;
int in_circle = 0;
const int R = 400;
const int CIRCLE_CENTER = R + 25;
const int SIZE = 2 * CIRCLE_CENTER;

void setPoints(int n, sf::RenderWindow& window)
{
    for (int i = 0; i < n; ++i) {
        sf::Color color = sf::Color::Red;
        int x = rand() % R * 2 + 25;
        int y = rand() % R * 2 + 25;

        if (pow((x - CIRCLE_CENTER), 2) + pow((y - CIRCLE_CENTER), 2) < pow(R, 2)) {
            in_circle++;
            color = sf::Color::Green;
        }

        sf::Vertex point(sf::Vector2f(10, 10), color);

        point.position = { (float)x, (float)y };
        window.draw(&point, 1, sf::Points);
        total++;
    }

    long double pi = 4 * ((long double)in_circle / (long double)total);
    printf("%.10Lf\n", pi);
}

int main()
{
    srand(time(NULL));

    sf::VideoMode mode(SIZE, SIZE);
    sf::RenderWindow window(mode, "Chip8");

    // rect
    sf::RectangleShape rect({ R * 2, R * 2 });
    rect.setPosition({ 25, 25 });
    rect.setOutlineColor(sf::Color::White);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineThickness(2.f);

    // circle
    sf::CircleShape circle;
    circle.setRadius(R);
    circle.setOutlineColor(sf::Color::White);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(2.f);
    circle.setOrigin({ R, R });
    circle.setPosition({ CIRCLE_CENTER, CIRCLE_CENTER });

    // initially clear screen to black
    window.clear(sf::Color::Black);

    while (window.isOpen()) {
        window.draw(rect);
        window.draw(circle);
        setPoints(100, window);
        window.display();
        usleep(10000);
    }
}
