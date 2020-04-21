/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include "sphere.hpp"
#include "params.hpp"

Modeling::sphere::sphere()
: _centre(0, 0, 0), _radius(0)
{}

Modeling::sphere::sphere(const Utils::vector3<float> &centre,
    const float &radius)
    : _centre(centre), _radius(radius)
{}

Modeling::sphere::sphere(const Utils::vector3<float> &centre,
    const float &radius, const material &material)
    : _centre(centre), _radius(radius)
{
    this->_material = material;
}

Modeling::sphere &Modeling::sphere::operator=(const Modeling::sphere &sp)
{
    _centre = sp.getCentre();
    _radius = sp.getRadius();
    return *this;
}

Utils::vector3<float> Modeling::sphere::getCentre() const
{
    return _centre;
}

float Modeling::sphere::getRadius() const
{
    return _radius;
}

Modeling::intersection Modeling::sphere::intersected(const Utils::ray &ray)
{
    auto op = _centre - ray.getOrigin();
    auto radiusSquared = _radius * _radius;
    auto b = op.dotProduct(ray.getDirection());
    auto determinant = b * b - op.dotProduct(op) + radiusSquared;
    if (determinant < 0)
        return Modeling::intersection();
    determinant = std::sqrt(determinant);
    auto minusT = b - determinant;
    auto plusT = b + determinant;
    if (minusT < Utils::params::Epsilon && plusT < Utils::params::Epsilon)
        return Modeling::intersection();
    auto t = minusT > Utils::params::Epsilon ? minusT : plusT;
    auto hitPosition = ray.getOrigin() + ray.getDirection() * t;
    auto normal = hitPosition - _centre;
    bool inside = normal.dotProduct(ray.getDirection()) > 0;
    if (inside)
        normal = normal * -1;
    return Modeling::intersection(inside, hitPosition, t, normal, _material);
}

