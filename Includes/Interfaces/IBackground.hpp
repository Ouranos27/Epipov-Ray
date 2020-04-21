/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#ifndef EPIPOV_RAY_IBACKGROUND_HPP
    # define EPIPOV_RAY_IBACKGROUND_HPP

    # include "color.hpp"
    # include "vector3.hpp"

namespace Interfaces {
    class IBackground {
        public:
            virtual ~IBackground() = default;

        public:
            virtual Utils::color    getPixel(const Utils::vector3<float> &direction) const = 0;
    };
}

#endif //EPIPOV_RAY_IBACKGROUND_HPP
