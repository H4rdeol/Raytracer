/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Main
*/

#include <iostream>
#include "ConfigSubject/ConfigSubject.hpp"
#include "ConfigObserver/ConfigObserver.hpp"

int main(void)
{
    NamePipe pipe;
    NamePipe pipe2;
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Failed to fork" << std::endl;
        return 84;
    } else if (pid == 0) {
        ConfigSubject subject("assets/configs/test.cfg", pipe2);
        ConfigObserver observer(subject, pipe);
        subject.notifyObservers();
        _exit(0);
    } else {
        std::size_t refresh = 0;
    
        while (true) {
            std::optional<std::string> data = pipe.read();
            
            if (data) {
                std::cout << data.value() << std::endl;
                refresh++;
            }
            if (refresh > 3) {
                pipe2.write("finished");
                break;
            }
        }
    }
    return 0;
}

