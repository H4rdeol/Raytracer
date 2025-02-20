/*
** EPITECH PROJECT, 2027
** Raytracer
** File description:
** Image.hpp
*/

#pragma once

#include <vector>

#include "Colors/Colors.hpp"

namespace Application {

    class Image {
        public:
            explicit Image(std::size_t nb_cols, std::size_t nb_rows);
            void updatePixel(const Color &color, std::size_t x, std::size_t y);
            [[nodiscard]] std::vector<Color> getPixels() const;
            ~Image() = default;
        private:
            std::size_t _nb_cols;
            std::size_t _nb_rows;
            std::vector<Color> _pixels;
    };
} // Application
