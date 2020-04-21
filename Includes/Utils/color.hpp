/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_COLOR_HPP
    # define EPIPOV_RAY_COLOR_HPP

    # include <cstdint>
#include "vector3.hpp"

namespace Utils {

    union component {
        std::uint32_t hexcode;
        struct  s_rgba {
            std::uint8_t    r;
            std::uint8_t    g;
            std::uint8_t    b;
            std::uint8_t    a;
        }       rgba;
    };

    class color {
        public:
            color();
            explicit color(const component &cp);
            explicit color(const std::uint32_t &hexcode);
            color(const std::uint8_t &red, const std::uint8_t &green,
                const std::uint8_t &blue);
            explicit color(const Utils::vector3<float> &vec);
            ~color() = default;

        public:
            color &operator=(const color &other);
            const color &operator+=(const color &other);
            color operator*(float const &coef);

        public:
            [[nodiscard]] std::uint8_t    getRed() const;
            [[nodiscard]] std::uint8_t    getGreen() const;
            [[nodiscard]] std::uint8_t    getBlue() const;
            [[nodiscard]] std::uint8_t    getAlpha() const;

        public:
            void    setRed(const std::uint8_t &red);
            void    setGreen(const std::uint8_t &green);
            void    setBlue(const std::uint8_t &blue);
            void    setAlpha(const std::uint8_t &aplha);

        public:
            [[nodiscard]] component   getColor() const;

        private:
            component   _color;
    };
}

#endif //EPIPOV_RAY_COLOR_HPP
