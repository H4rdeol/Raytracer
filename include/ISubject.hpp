/*
** EPITECH PROJECT, 2025
** test
** File description:
** ISubject
*/

#pragma once

#include "IObserver.hpp"
#include <memory>

namespace Observer {
    class ISubject {
        public:
            virtual ~ISubject() = default;
            virtual void subscribe(IObserver &observer) = 0;
            virtual void unsubscribe(std::shared_ptr<IObserver> &observer) = 0;
            virtual void notifyObservers(void) = 0;
    };
}
