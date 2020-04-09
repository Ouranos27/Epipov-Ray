/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include "IGraphicalLibrary.hpp"
#include "launcher.hpp"

launcher::launcher()
    : _raytracer()
{}

launcher::launcher(const int &width, const int &height)
    : _raytracer(width, height)
{}

launcher::launcher(const launcher &launch)
    : _raytracer(launch.getRaytracer())
{}

launcher & launcher::operator=(const launcher &launch)
{
    _raytracer = launch.getRaytracer();
    return *this;
}

Gui::gui launcher::getGui() const
{
    return _gui;
}

Raytracing::raytracer launcher::getRaytracer() const
{
    return _raytracer;
}

void launcher::start() {

    Interfaces::IGraphicalLibrary::keys	key;

    while(_raytracer.getLib().windowIsOpen()) {
        key = _raytracer.getLib().getKey();
        if (key == Interfaces::IGraphicalLibrary::ESC) {
            _raytracer.getLib().closeWindow();
            break;
        }
        _raytracer.getLib().clear();
        _raytracer.getLib().refreshWindow();
    }
}
