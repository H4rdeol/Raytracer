/*
** EPITECH PROJECT, 2025
** test
** File description:
** ConfigObserver
*/

#pragma once

#include "IObserver.hpp"
#include "ASubject.hpp"

#include <memory>

class ConfigObserver final: public IObserver {
    public:
        ConfigObserver(ASubject &subject);
        ~ConfigObserver() final = default;

    private:
        std::unique_ptr<ASubject> _subject;
};
