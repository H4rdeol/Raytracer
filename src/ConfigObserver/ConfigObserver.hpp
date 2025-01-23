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

namespace Observer {
    class ConfigObserver final: public IObserver {
        public:
            ConfigObserver(ASubject &subject, const std::shared_ptr<IPC::NamePipe> pipe);
            ~ConfigObserver() final = default;
    
            void update(const std::string &data) final;
        private:
            std::shared_ptr<IPC::NamePipe> _pipe;
    };
}
