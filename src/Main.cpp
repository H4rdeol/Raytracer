/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Main
*/

#include <iostream>
#include "ConfigUpdater/ConfigUpdater.hpp"

int main(void)
{
    Observer::ConfigUpdater updater;
    updater.start("assets/configs/test.cfg");
    while (true) {
        if (auto config = updater.getConfig())
            std::cout << config.value() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}
