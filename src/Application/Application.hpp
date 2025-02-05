/*
** EPITECH PROJECT, 2025
** test
** File description:
** Application
*/

#pragma once

#include "Camera/Camera.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <memory>

namespace Application {
    class Application {
        public:
            Application(const std::string &path);
            Application() = delete;
            ~Application() = default;

            [[nodiscard]] bool isRunning() const;
            void refreshConfig();
            void run();
        public:
            const std::unique_ptr<Camera> camera;
        private:
            const short _bitPerPixels = 32;
            bool _isRunning = true;
            sf::Color _backGroundColor;
            sf::RenderWindow _window;
            glm::vec<2, unsigned int> _windowSize;
    };
}
