/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include "intersection.hpp"

Modeling::intersection::intersection()
: _name(std::string("")), _isIntersected(false), _material(), _distance(-1), _intersectionPoint(), _normal()
{}

Modeling::intersection::intersection(bool isIntersected,
    const Utils::vector3<float> &intersectionPoint, const float &dist,
    const Utils::vector3<float> &normal, const Modeling::material &material)
    : _isIntersected(isIntersected), _material(material),
    _distance(dist), _intersectionPoint(intersectionPoint), _normal(normal)
{}
