/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include <algorithm>

#include "color.hpp"

Utils::color::color()
{
    _color.hexcode = 0x00000000;
}

Utils::color::color(const Utils::component &cp)
: _color(cp)
{}

Utils::color::color(const std::uint32_t &hexcode)
{
    _color.hexcode = hexcode;
}

Utils::color::color(const Utils::vector3<float> &vec)
{
    _color.rgba.r = vec.x * 255;
    _color.rgba.g = vec.y * 255;
    _color.rgba.b = vec.z * 255;
    _color.rgba.a = 0;
}

Utils::color::color(const std::uint8_t &red, const std::uint8_t &green,
    const std::uint8_t &blue)
{
    _color.rgba.r = red;
    _color.rgba.g = green;
    _color.rgba.b = blue;
    _color.rgba.a = 0;
}

Utils::color &Utils::color::operator=(const Utils::color &other)
{
    _color.hexcode = _color.hexcode;
    _color.rgba.r = other.getRed();
    _color.rgba.g = other.getGreen();
    _color.rgba.b = other.getBlue();
    _color.rgba.a = other.getAlpha();
    return *this;
}

const Utils::color &Utils::color::operator+=(
    const Utils::color &other)
{
    _color.rgba.r = std::min(_color.rgba.r + other._color.rgba.r, 255);
    _color.rgba.g = std::min(_color.rgba.g + other._color.rgba.g, 255);
    _color.rgba.b = std::min(_color.rgba.b + other._color.rgba.b, 255);
    return *this;
}

Utils::color  Utils::color::operator*(float const &coef)
{
    Utils::color rtn;
    rtn._color.rgba.r = std::min(_color.rgba.r * coef, 255.f);
    rtn._color.rgba.g = std::min(_color.rgba.g * coef, 255.f);
    rtn._color.rgba.b = std::min(_color.rgba.b * coef, 255.f);
    return rtn;
}

std::uint8_t Utils::color::getRed() const
{
    return _color.rgba.r;
}

std::uint8_t Utils::color::getGreen() const
{
    return _color.rgba.g;
}

std::uint8_t Utils::color::getBlue() const
{
    return _color.rgba.b;
}

std::uint8_t Utils::color::getAlpha() const
{
    return _color.rgba.a;
}

void Utils::color::setRed(const std::uint8_t &red)
{
    _color.rgba.r = red;
}

void Utils::color::setGreen(const std::uint8_t &green)
{
    _color.rgba.g = green;
}

void Utils::color::setBlue(const std::uint8_t &blue)
{
    _color.rgba.b = blue;
}

void Utils::color::setAlpha(const std::uint8_t &aplha)
{
    _color.rgba.a = aplha;
}

Utils::component Utils::color::getColor() const
{
    return _color;
}
