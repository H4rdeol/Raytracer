/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Colors.hpp
*/

#pragma once

#include <cstdint>

namespace Application {
    class Color {
        public:
            Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255);
            ~Color() = default;

            [[nodiscard]] std::uint8_t red() const;
            [[nodiscard]] std::uint8_t green() const;
            [[nodiscard]] std::uint8_t blue() const;
            [[nodiscard]] std::uint8_t alpha() const;
        private:
            std::uint32_t _color;

    };
}
