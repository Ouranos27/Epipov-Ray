/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_CAMERA_HPP
    # define EPIPOV_RAY_CAMERA_HPP

#include <random>
# include "vector3.hpp"
    # include "vector2.hpp"
    # include "ray.hpp"

namespace Tracing {
    class camera {
        public:
            camera();
            ~camera() = default;

        public:
            camera  &operator=(const camera &cam) = default;

        public:
            [[nodiscard]] Utils::vector3<float>  getPosition() const;
            [[nodiscard]] Utils::vector2<unsigned int> getScreenResolution() const;

        public:
            Utils::ray  setRay(const Utils::vector2<unsigned int> &position);
            void        setScreen();

        public:
            void    setMatrix(const Utils::vector3<float> &screenPos1,
                const Utils::vector3<float> &screenPos2,
                const Utils::vector3<float> &screenPos3,
                const Utils::vector3<float> &pos);

        private:
            Utils::vector3<float>           _position;
            Utils::vector2<float>           _screenSize;
            Utils::vector2<unsigned int>    _screenResolution;
            Utils::vector3<float>           _screenCorner;
            Utils::vector3<float>           _camPos1;
            Utils::vector3<float>           _camPos2;
            Utils::vector3<float>           _camPos3;
            float                           _screenDistance{};
            std::uniform_real_distribution<float>   _dis;
            std::mt19937                    _gen;
    };
}

#endif //EPIPOV_RAY_CAMERA_HPP