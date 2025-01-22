/*
** EPITECH PROJECT, 2025
** test
** File description:
** ASubject
*/

#pragma once

#include "ISubject.hpp"
#include <vector>
#include <algorithm>

class ASubject: public ISubject {
    public:
        virtual ~ASubject() = default;
        virtual void subscribe(IObserver &observer) override;
        virtual void unsubscribe(std::shared_ptr<IObserver> &observer) override;

    protected:
        std::vector<std::shared_ptr<IObserver>> _list_observers;
};
