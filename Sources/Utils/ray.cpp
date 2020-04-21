/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#include "ray.hpp"

Utils::ray::ray()
: _origin(), _direction()
{}

Utils::ray::ray(const Utils::vector3<float> &origin,
    const Utils::vector3<float> &direction)
    : _origin(origin), _direction(direction)
{}

Utils::ray &Utils::ray::operator=(const Utils::ray &rayon)
{
    _origin = rayon.getOrigin();
    _direction = rayon.getDirection();
    return *this;
}

Utils::vector3<float> Utils::ray::getOrigin() const
{
    return _origin;
}

Utils::vector3<float> Utils::ray::getDirection() const
{
    return _direction;
}

void Utils::ray::setOrigin(const Utils::vector3<float> &origin)
{
    _origin = origin;
}

void Utils::ray::setDirection(const Utils::vector3<float> &direction)
{
    _direction = direction;
}
