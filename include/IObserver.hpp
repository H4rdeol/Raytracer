/*
** EPITECH PROJECT, 2025
** test
** File description:
** IObserver
*/

#pragma once

#include <any>

class IObserver {
    public:
        virtual ~IObserver() = default;
        virtual void update(const std::any &data) = 0;
};
