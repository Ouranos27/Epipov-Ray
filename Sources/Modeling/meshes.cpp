/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#include "meshes.hpp"

Modeling::meshes::meshes()
: _material()
{}

Modeling::material Modeling::meshes::getMaterial() const
{
    return _material;
}

