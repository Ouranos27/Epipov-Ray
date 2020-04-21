/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_LIGHT_HPP
#define EPIPOV_RAY_LIGHT_HPP

#include "vector3.hpp"
#include "color.hpp"

namespace Utils {
    class light {
        public:
            light();
            virtual ~light() = default;

        public:
            [[nodiscard]] color   getColor() const;
            [[nodiscard]] float   getIntensity() const;
            [[nodiscard]] virtual Utils::vector3<float>   getPosition() const = 0;

        protected:
            color   _color;
            float   _intensity;
    };
}

#endif //EPIPOV_RAY_LIGHT_HPP
