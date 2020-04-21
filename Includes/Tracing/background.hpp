/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_BACKGROUND_HPP
#define EPIPOV_RAY_BACKGROUND_HPP

#include <vector>
#include <cstdint>
#include <Interfaces/IBackground.hpp>
#include "vector2.hpp"

namespace Tracing {
    class background : public Interfaces::IBackground {
        public:
            background();
            background(const background &bg);
            background(const Utils::vector2<unsigned int> &size, const std::uint8_t *pixel);
            ~background() override = default;

        public:
            background  &operator=(const background &bg);

        public:
            [[nodiscard]] Utils::vector2<unsigned int>    getSize() const;
            [[nodiscard]] std::vector<std::uint8_t>       getPixels() const;

        public:
            [[nodiscard]] Utils::color    getPixel(const Utils::vector3<float> &direction) const override;

        private:
            Utils::vector2<unsigned int>    _size;
            std::vector<std::uint8_t>       _pixels;
    };
}

#endif //EPIPOV_RAY_BACKGROUND_HPP
