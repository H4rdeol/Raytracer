/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Main
*/

#include <SFML/Graphics.hpp>
#include <iostream>

int main(void)
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Raytracer");

    while (window.isOpen()) {
        window.clear();
        window.handleEvents([&window](const sf::Event::Closed &) { window.close(); });
        window.display();
    }
    return 0;
}
