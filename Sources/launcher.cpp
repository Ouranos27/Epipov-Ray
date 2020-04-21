/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include <iostream>
#include "params.hpp"
#include "handler.hpp"
#include "IGraphicalLibrary.hpp"
#include "launcher.hpp"

launcher::launcher()
: _lib()
{}

launcher::launcher(const launcher &launch)
: _lib(launch.getLib())
{}

launcher & launcher::operator=(const launcher &launch)
{
    _lib = launch.getLib();
    return *this;
}

Library::sfml launcher::getLib() const
{
    return _lib;
}

void launcher::laudFromArgument(int ac, char **av)
{
    Loader::assimp  loader;
    Interfaces::IGraphicalLibrary::keys	key;

    if (ac < 2)
        exit(84);

    std::cout << "Loading scene " << av[1] << "..." << std::endl;
    if (!loader.loadFile(av[1]))
        throw std::runtime_error("Usage: ./Epipov-Ray scene.dae");

    auto   tracer = Tracing::tracer(loader);
    Utils::vector2<unsigned int> resolution = tracer.getResolution();
    Tracing::handler handler(tracer, resolution);

    handler.start();
    _lib.initWindow(resolution.x, resolution.y);
    while(_lib.windowIsOpen()) {
        key = _lib.getKey();
        std::vector<Utils::color> pixels = handler.getPixels();
        _lib.drawer(pixels);
        if (key == Interfaces::IGraphicalLibrary::ESC) {
            _lib.closeWindow();
            handler.stop();
            break;
        }
        //_lib.clear();
        //_lib.refreshWindow();
    }
}
