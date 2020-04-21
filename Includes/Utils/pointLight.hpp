/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_POINTLIGHT_HPP
    # define EPIPOV_RAY_POINTLIGHT_HPP

    # include "light.hpp"

namespace Utils {
    class pointLight : public light {
        public:
            pointLight();
            pointLight(const pointLight &pointLight);
            explicit pointLight(const vector3<float> &pos);
            pointLight(const vector3<float> &pos, const Utils::color &color);
            ~pointLight() override = default;

        public:
            [[nodiscard]] Utils::vector3<float>   getPosition() const override;

        private:
            Utils::vector3<float>   _position;
    };
}

#endif //EPIPOV_RAY_POINTLIGHT_HPP
