/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include "pointLight.hpp"

Utils::pointLight::pointLight()
: _position()
{}

Utils::pointLight::pointLight(const Utils::pointLight &pl)
: _position(pl.getPosition())
{}

Utils::pointLight::pointLight(const Utils::vector3<float> &pos)
: _position(pos)
{}

Utils::pointLight::pointLight(const Utils::vector3<float> &pos,
    const Utils::color &color)
    : _position(pos)
{
    this->_color = color;
}

Utils::vector3<float> Utils::pointLight::getPosition() const
{
    return _position;
}
