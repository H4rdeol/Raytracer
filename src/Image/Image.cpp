/*
** EPITECH PROJECT, 2027
** Raytracer
** File description:
** Image.cpp
*/

#include "Image.hpp"
#include "Colors/Colors.hpp"
#include "Interval/Interval.hpp"
#include <cstdint>

namespace Application {
    Image::Image(const std::size_t nb_cols, const std::size_t nb_rows)
                : _nb_cols(nb_cols), _nb_rows(nb_rows)
    {
        for (std::size_t i = 0; i < nb_cols * nb_rows; i++)
            _pixels.push_back(Color::Black);
    }

    void Image::updatePixel(const glm::vec3 &color, const std::size_t x, const std::size_t y)
    {
        static const Maths::Interval intensity(0.000, 0.999);
        std::uint8_t rbyte = std::uint8_t(256 * intensity.clamp(color.x));
        std::uint8_t gbyte = std::uint8_t(256 * intensity.clamp(color.y));
        std::uint8_t bbyte = std::uint8_t(256 * intensity.clamp(color.z));

        Color trueColor{rbyte, gbyte, bbyte};
        if (y * _nb_cols + x < _nb_cols * _nb_rows)
            _pixels[y * _nb_cols + x] = trueColor;
    }

    std::vector<Color> Image::getPixels() const
    {
        return _pixels;
    }

} // Application
