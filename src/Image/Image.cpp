/*
** EPITECH PROJECT, 2027
** Raytracer
** File description:
** Image.cpp
*/

#include "Image.hpp"

#include <iostream>

namespace Application {
    Image::Image(const std::size_t nb_cols, const std::size_t nb_rows)
                : _nb_cols(nb_cols), _nb_rows(nb_rows)
    {
        for (std::size_t i = 0; i < nb_cols * nb_rows; i++)
            _pixels.push_back(Color::Black);
    }

    void Image::updatePixel(const Color &color, const std::size_t x, const std::size_t y)
    {
        if (y * _nb_cols + x < _nb_cols * _nb_rows)
            _pixels[y * _nb_cols + x] = color;
    }

    std::vector<Color> Image::getPixels() const
    {
        return _pixels;
    }

} // Application
