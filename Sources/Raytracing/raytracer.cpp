/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#include "Raytracing/raytracer.hpp"

Raytracing::raytracer::raytracer()
: _lib()
{}

Raytracing::raytracer::raytracer(const int &width, const int &height)
: _lib(width, height)
{}

Raytracing::raytracer &Raytracing::raytracer::operator=(
    const Raytracing::raytracer &raytracer1)
{
    _lib = raytracer1.getLib();
    return *this;
}

Library::sfml Raytracing::raytracer::getLib() const
{
    return _lib;
}

void Raytracing::raytracer::drawer()
{
    unsigned int y = 0;

    while (y++ <  _lib.getWindow()->getSize().y) {
        unsigned int x = 0;
        while (x++ < _lib.getWindow()->getSize().x) {
            _lib.get
            _lib.updateTexture();
        }
    }
}
