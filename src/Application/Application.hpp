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
            explicit Application(const std::string &path);
            Application() = delete;
            ~Application() = default;

            [[nodiscard]] bool isRunning() const;
            void refreshConfig();
            void run();
        public:
            const std::unique_ptr<Camera> camera;
        private:
            void _convertImage();
        private:
            const short _bitPerPixels = 32;
            bool _isRunning = true;
            sf::RenderWindow _window;
            glm::vec<2, unsigned int> _windowSize{};
            sf::Texture _texture;
            sf::Sprite _sprite;
    };
}
