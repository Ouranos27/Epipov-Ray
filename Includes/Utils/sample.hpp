/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_SAMPLE_HPP
#define EPIPOV_RAY_SAMPLE_HPP

#include "vector3.hpp"

[[nodiscard]] Utils::vector3<float>   coneSample(const Utils::vector3<float> &direction
    , float coneTheta, float u, float v) noexcept;

//[[nodiscard]] Utils::vector3<float> hemisphereSample(const OrthoNormalBasis &basis, float u,
//    float v) noexcept;

#endif //EPIPOV_RAY_SAMPLE_HPP
