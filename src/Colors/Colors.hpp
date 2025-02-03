/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Colors.hpp
*/

#pragma once

#include <cstdint>
#include <ostream>

namespace Application {
    class Color {
        public:
            constexpr Color() = default;
            constexpr Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255);
            constexpr explicit Color(const std::uint32_t color);
            ~Color() = default;

            [[nodiscard]] std::uint8_t red() const;
            [[nodiscard]] std::uint8_t green() const;
            [[nodiscard]] std::uint8_t blue() const;
            [[nodiscard]] std::uint8_t alpha() const;

        public:
            static const Color Red;
            static const Color Green;
            static const Color Blue;
            static const Color Black;
            static const Color White;
            static const Color Yellow;
            static const Color Magenta;
            static const Color Cyan;
            static const Color Transparent;
        private:
            std::uint32_t _color;

    };

    std::ostream &operator<<(std::ostream &out, const Color &color);
}
