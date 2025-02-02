/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Main
*/

#include <iostream>
#include <ostream>
#include <thread>
#include "ConfigUpdater/ConfigUpdater.hpp"
#include "Colors/Colors.hpp"


using namespace Application;
int main(void)
{
    /*Observer::ConfigUpdater updater;

    updater.start("assets/configs/test.cfg");
    while (true) {
        if (auto config = updater.getConfig())
            std::cout << config.value() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }*/

    std::cout << "Red: " << static_cast<int>(Color::Blue.red()) << std::endl;
    std::cout << "Green: " << static_cast<int>(Color::Blue.green()) << std::endl;
    std::cout << "Blue: " << static_cast<int>(Color::Blue.blue()) << std::endl;
    std::cout << "Alpha: " << static_cast<int>(Color::Blue.alpha()) << std::endl;
    return 0;
}
