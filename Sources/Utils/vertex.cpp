/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include "vertex.hpp"

Utils::vertex::vertex()
: _position(), _normal()
{}

Utils::vertex::vertex(const Utils::vector3<float> &position)
: _position(position), _normal()
{}

Utils::vertex &Utils::vertex::operator=(const Utils::vertex &other)
{
    _position = other.getPosition();
    _normal = other.getNormal();
    return *this;
}

Utils::vector3<float> const &Utils::vertex::getPosition() const
{
    return _position;
}

Utils::vector3<float> const &Utils::vertex::getNormal() const
{
    return _normal;
}

bool Utils::vertex::operator==(const Utils::vertex &other) const
{
    return _position == other.getPosition() && _normal == other.getNormal();
}

void Utils::vertex::setPosition(const Utils::vector3<float> &position)
{
    _position = position;
}

void Utils::vertex::setNormal(const Utils::vector3<float> &normal)
{
    _normal = normal;
}