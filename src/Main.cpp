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
    return 0;
}

