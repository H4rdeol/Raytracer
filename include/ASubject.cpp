/*
** EPITECH PROJECT, 2025
** test
** File description:
** ASubject
*/

#include "ASubject.hpp"

void ASubject::subscribe(IObserver &observer)
{
    _list_observers.emplace_back(std::shared_ptr<IObserver>(&observer));
}

void ASubject::unsubscribe(std::shared_ptr<IObserver> &observer)
{
    _list_observers.erase(std::find(_list_observers.begin(), _list_observers.end(), observer));
}

