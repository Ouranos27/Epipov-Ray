/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_RAY_HPP
#define EPIPOV_RAY_RAY_HPP

#include "vector3.hpp"

namespace Utils {
    class ray {
        public:
            ray();
            ray(const vector3<float> &origin, const vector3<float> &direction);
            ~ray() = default;

        public:
            ray &operator=(const ray &rayon);

        public:
            [[nodiscard]] vector3<float>  getOrigin() const;
            [[nodiscard]] vector3<float>  getDirection() const;

        public:
            void    setOrigin(const vector3<float> &origin);
            void    setDirection(const vector3<float> &direction);

        private:
            vector3<float>  _origin;
            vector3<float > _direction;
    };
}

#endif //EPIPOV_RAY_RAY_HPP
