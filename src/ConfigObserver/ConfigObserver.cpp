/*
** EPITECH PROJECT, 2025
** test
** File description:
** ConfigObserver
*/

#include "ConfigObserver.hpp"

ConfigObserver::ConfigObserver(ASubject &subject)
{
    _subject = std::make_unique<ASubject>(subject);
    _subject->subscribe(*this);
}
