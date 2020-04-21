/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include <Utils/params.hpp>
#include "triangle.hpp"

Modeling::triangle::triangle()
: _vertex1(), _vertex2(), _vertex3(), _normal(), _edge1(), _edge2()
{}

Modeling::triangle::triangle(const Utils::vertex &vertex1,
    const Utils::vertex &vertex2, const Utils::vertex &vertex3)
    : _vertex1(vertex1), _vertex2(vertex2), _vertex3(vertex3)
{
    this->characteristicsGen();
}

Modeling::triangle::triangle(const Utils::vertex &vertex1,
    const Utils::vertex &vertex2, const Utils::vertex &vertex3,
    const Modeling::material &material)
    : _vertex1(vertex1), _vertex2(vertex2), _vertex3(vertex3)
{
    this->_material = material;
    this->characteristicsGen();
}

Modeling::triangle &Modeling::triangle::operator=(
    const Modeling::triangle &other)
{
    _vertex1 = other.getVertex1();
    _vertex2 = other.getVertex2();
    _vertex3 = other.getVertex3();
    _normal = other.getNormal();
    _edge1 = other.getEdge1();
    _edge2 = other.getEdge2();
    return *this;
}

bool Modeling::triangle::operator==(const Modeling::triangle &other) const
{
    return _vertex1 == other.getVertex1() && _vertex2 == other.getVertex2()
    && _vertex3 == other.getVertex3();
}

Utils::vertex const &Modeling::triangle::getVertex1() const
{
    return _vertex1;
}

Utils::vertex const &Modeling::triangle::getVertex2() const
{
    return _vertex2;
}

Utils::vertex const &Modeling::triangle::getVertex3() const
{
    return _vertex3;
}

Utils::vector3<float> const &Modeling::triangle::getNormal() const
{
    return _normal;
}

Utils::vector3<float> const &Modeling::triangle::getEdge1() const
{
    return _edge1;
}

Utils::vector3<float> const &Modeling::triangle::getEdge2() const
{
    return _edge2;
}

Utils::vector2<float> Modeling::triangle::getMinMaxX() const
{
    return Utils::vector2<float>(
        std::min(_vertex1.getPosition().x, std::min(_vertex2.getPosition().x, _vertex3.getPosition().x)),
        std::max(_vertex1.getPosition().x, std::max(_vertex2.getPosition().x, _vertex3.getPosition().x)));
}

Utils::vector2<float> Modeling::triangle::getMinMaxY() const
{
    return Utils::vector2<float>(
        std::min(_vertex1.getPosition().y, std::min(_vertex2.getPosition().y, _vertex3.getPosition().y)),
        std::max(_vertex1.getPosition().y, std::max(_vertex2.getPosition().y, _vertex3.getPosition().y)));
}

Utils::vector2<float> Modeling::triangle::getMinMaxZ() const
{
    return Utils::vector2<float>(
        std::min(_vertex1.getPosition().z, std::min(_vertex2.getPosition().z, _vertex3.getPosition().z)),
        std::max(_vertex1.getPosition().z, std::max(_vertex2.getPosition().z, _vertex3.getPosition().z)));
}

Utils::vector3<float> Modeling::triangle::getMidPoint() const
{
    return Utils::vector3<float>((getMinMaxX().x + getMinMaxX().y) / 2.f,
            (getMinMaxY().x + getMinMaxY().y) / 2.f,
            (getMinMaxZ().x + getMinMaxZ().y) / 2.f);
}

Modeling::intersection Modeling::triangle::intersected(const Utils::ray &ray)
{
    Modeling::intersection returnValue;

    Utils::vector3<float> temp = ray.getDirection().crossProduct(_edge2);
    float   a = _edge1.dotProduct(temp);
    if (a > -Utils::params::Epsilon && a < Utils::params::Epsilon)
        return returnValue;

    Utils::vector3<float> temp2 = ray.getOrigin() - _vertex1.getPosition();
    float b = temp2.dotProduct(temp) / a;
    if (b < 0.f || b > 1.f)
        return returnValue;

    Utils::vector3<float> temp3 = temp2.crossProduct(_edge1);
    float c = ray.getDirection().dotProduct(temp3) / a;
    if (c < 0.f || b + c > 1.f)
        return returnValue;

    float d = _edge2.dotProduct(temp3) / a;
    if (d < Utils::params::MinDistance)
        return returnValue;

    returnValue._isIntersected = true;
    returnValue._intersectionPoint = ray.getOrigin() + ray.getDirection() * d;
    returnValue._distance = d;
    if (_vertex1.getNormal() != Utils::vector3<float>())
        returnValue._normal = _vertex1.getNormal() * (1 - b - c)
            + _vertex2.getNormal() * b + _vertex3.getNormal() * c;
    else
        returnValue._normal = _normal;
    returnValue._material = _material;
    return returnValue;
}

void Modeling::triangle::characteristicsGen()
{
    _edge1 = _vertex2.getPosition() - _vertex1.getPosition();
    _edge2 = _vertex3.getPosition() - _vertex1.getPosition();
    _normal = _edge1.crossProduct(_edge2);
    _normal.normalize();
}
