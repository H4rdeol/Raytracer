/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Colors.cpp
*/

#include "Colors.hpp"

namespace Application {
    Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
    {
        _color = 0;

        (_color |= r) <<= 24;
        _color |= (((std::uint32_t) g) << 16);
        _color |= (((std::uint32_t) b) << 8);
        _color |= a;
    }

    std::uint8_t Color::red() const
    {
        return _color >> 24;
    }

    std::uint8_t Color::green() const
    {
        return (_color >> 16) & 255;
    }

    std::uint8_t Color::blue() const
    {
        return (_color >> 8) & 255;
    }

    std::uint8_t Color::alpha() const
    {
        return _color & 255;
    }
}
