/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#include "background.hpp"

Tracing::background::background()
: _size(), _pixels()
{}

Tracing::background::background(const Tracing::background &bg)
: _size(bg.getSize()), _pixels(bg.getPixels())
{}

Tracing::background::background(const Utils::vector2<unsigned int> &size,
    const std::uint8_t *pixel)
    : _size(size), _pixels(pixel, pixel + (size.x * size.y * 4))
{}

Utils::color Tracing::background::getPixel(
    const Utils::vector3<float> &direction) const
{
    unsigned int u = std::lround(0.5f + (std::atan2(direction.y, direction.x) / (2.f * static_cast<float>(M_PI)))) * (_size.x - 1);
    unsigned int v = std::lround(0.5f - std::asin(direction.z) / static_cast<float>(M_PI)) * (_size.y - 1);
    unsigned int index = (u * 4) + (v * 4 * _size.x);
    return Utils::color(_pixels.at(index), _pixels.at(index + 1), _pixels.at(index + 2));
}

Utils::vector2<unsigned int> Tracing::background::getSize() const
{
    return _size;
}

std::vector<std::uint8_t> Tracing::background::getPixels() const
{
    return _pixels;
}

Tracing::background &Tracing::background::operator=(
    const Tracing::background &bg)
{
    _size = bg.getSize();
    _pixels = bg.getPixels();
    return *this;
}


