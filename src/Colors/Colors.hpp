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
            constexpr Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255)
                : _color(static_cast<uint32_t>((r << 24) | (g << 16) | (b << 8) | a))
            {}
            constexpr explicit Color(const std::uint32_t color) : _color(color)
            {}
            constexpr Color() = default;
            Color(const Color &color) = default;
            ~Color() = default;

            Color &operator=(const Color &other) = default;
            Color &operator+=(const Color &other);
            Color operator*(const double d) const;
            [[nodiscard]] std::uint8_t red() const;
            [[nodiscard]] std::uint8_t green() const;
            [[nodiscard]] std::uint8_t blue() const;
            [[nodiscard]] std::uint8_t alpha() const;
            [[nodiscard]] std::uint32_t getColorInt() const;
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
