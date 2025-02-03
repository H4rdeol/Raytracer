/*
** EPITECH PROJECT, 2025
** test
** File description:
** Application
*/

#pragma once

#include "Camera/Camera.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace Application {
    class Application {
        public:
            Application(const Camera &camera);
            Application() = delete;
            ~Application() = default;

            [[nodiscard]] bool isRunning() const;
        public:
            const std::unique_ptr<Camera> camera;
        private:
            bool _isRunning = true;
            sf::RenderWindow _window;
    };
}
