/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#include <Utils/params.hpp>
#include <utility>
#include <iostream>
#include "object.hpp"

Modeling::object::object()
: _triangles(), _tree()
{}

Modeling::object::object(std::vector<triangle> &triangles,
    const Modeling::material &material, const  std::string &name)
    : _triangles(triangles), _tree(_triangles, Utils::params::KDTreeDepth)
{
    this->_material = material;
    this->_name = name;
}

Modeling::intersection Modeling::object::intersected(const Utils::ray &ray)
{
    Modeling::intersection intersection = _tree.intersected(ray);

    intersection._material = _material;
    intersection._name = _name;
    return intersection;
}

