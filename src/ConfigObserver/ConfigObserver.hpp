/*
** EPITECH PROJECT, 2025
** test
** File description:
** ConfigObserver
*/

#pragma once

#include "IObserver.hpp"
#include "ASubject.hpp"
#include "NamePipe/NamePipe.hpp"

#include <iostream>

class ConfigObserver final: public IObserver {
    public:
        ConfigObserver(ASubject &subject, NamePipe &pipe);
        ~ConfigObserver() final = default;

        void update(const std::string &data) final;
    private:
        std::shared_ptr<NamePipe> _pipe;
};
