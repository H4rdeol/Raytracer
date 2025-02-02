/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Colors.cpp
*/

#include "Colors.hpp"

namespace Application {

    constexpr Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
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
        return (_color >> 16) & 0x000000ff;
    }

    std::uint8_t Color::blue() const
    {
        return (_color >> 8) & 0x000000ff;
    }

    std::uint8_t Color::alpha() const
    {
        return _color & 0x000000ff;
    }

    constexpr Color Color::Red(255, 0, 0);
    constexpr Color Color::Green(0, 255, 0);
    constexpr Color Color::Blue(0, 0, 255);
    constexpr Color Color::Yellow(255, 255, 0);
    constexpr Color Color::Magenta(255, 0, 255);
    constexpr Color Color::Cyan(0, 255, 255);
    constexpr Color Color::Black(0, 0, 0);
    constexpr Color Color::White(255, 255, 255);
    constexpr Color Color::Transparent(0, 0, 0, 0);
} // namespace Application
