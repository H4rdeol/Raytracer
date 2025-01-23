/*
** EPITECH PROJECT, 2025
** test
** File description:
** IObserver
*/

#pragma once

#include <string>

namespace Observer {
    class IObserver {
        public:
            virtual ~IObserver() = default;
            virtual void update(const std::string &data) = 0;
    };
}
