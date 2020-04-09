/*
** EPITECH PROJECT, 2022
** Epipov-Ray
** File description:
** Created by philippe,
*/

#include "launcher.hpp"

int main()
{
    launcher *launch = new launcher(1080, 720);
    launch->start();
    /*} catch (const std::exception &exception) {
        std::runtime_error(exception.what());
    }*/
    return 0;
}
