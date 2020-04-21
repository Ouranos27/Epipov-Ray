/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#ifndef EPIPOV_RAY_VERTEX_HPP
    # define EPIPOV_RAY_VERTEX_HPP

    # include "vector3.hpp"

namespace Utils {
    class vertex {
        public:
            vertex();
            explicit vertex(const vector3<float> &position);
            ~vertex() = default;

        public:
            vertex    &operator=(const vertex &other);
            bool    operator==(const vertex &other) const;

        public:
            [[nodiscard]] Utils::vector3<float>  const &getPosition() const;
            [[nodiscard]] vector3<float> const &getNormal() const;

        public:
            void    setPosition(const vector3<float> &position);
            void    setNormal(const vector3<float> &normal);

        private:
            Utils::vector3<float>  _position;
            Utils::vector3<float>  _normal;
    };
}

#endif //EPIPOV_RAY_VERTEX_HPP
