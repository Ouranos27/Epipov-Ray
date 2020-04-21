/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_INTERSECTION_HPP
#define EPIPOV_RAY_INTERSECTION_HPP

#include <string>
#include "vector3.hpp"
#include "material.hpp"

namespace Modeling {
    class intersection {
        public:
            intersection();
            intersection(bool isIntersected, const Utils::vector3<float> &intersectionPoint,
                const float &dist, const Utils::vector3<float> &normal, const material &material);
            ~intersection() = default;

        public:
            intersection    &operator=(const intersection &other) = default;

        public:
            std::string             _name;
            bool                    _isIntersected;
            material                _material;
            float                   _distance;
            Utils::vector3<float>   _intersectionPoint;
            Utils::vector3<float>   _normal;

    };
}

#endif //EPIPOV_RAY_INTERSECTION_HPP
