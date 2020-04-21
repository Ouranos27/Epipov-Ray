/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#include "light.hpp"

Utils::light::light()
: _color(0xffffffff), _intensity(1.f)
{}

Utils::color Utils::light::getColor() const
{
    return _color;
}

float Utils::light::getIntensity() const
{
    return _intensity;
}
