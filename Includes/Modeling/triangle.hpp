/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_TRIANGLE_HPP
    # define EPIPOV_RAY_TRIANGLE_HPP

    # include "vertex.hpp"
    # include "meshes.hpp"

namespace Modeling {
    class triangle : public meshes {
        public:
            triangle();
            triangle(const triangle &triangle1) = default;
            triangle(const Utils::vertex &vertex1, const Utils::vertex &vertex2,
                const Utils::vertex &vertex3);
            triangle(const Utils::vertex &vertex1, const Utils::vertex &vertex2,
                const Utils::vertex &vertex3, const material &material);
            ~triangle() override = default;

        public:
            triangle   &operator=(const triangle &other);
            bool    operator==(const triangle &other) const;

        public:
            [[nodiscard]] Utils::vertex  const &getVertex1() const;
            [[nodiscard]] Utils::vertex  const &getVertex2() const;
            [[nodiscard]] Utils::vertex  const &getVertex3() const;
            [[nodiscard]] Utils::vector3<float>  const &getNormal() const;
            [[nodiscard]] Utils::vector3<float>  const &getEdge1() const;
            [[nodiscard]] Utils::vector3<float>  const &getEdge2() const;

        public:
            [[nodiscard]] Utils::vector2<float>  getMinMaxX() const;
            [[nodiscard]] Utils::vector2<float>  getMinMaxY() const;
            [[nodiscard]] Utils::vector2<float>  getMinMaxZ() const;
            [[nodiscard]] Utils::vector3<float>  getMidPoint() const;

        public:
            intersection intersected(const Utils::ray &ray) override;

        public:
            void    characteristicsGen();

        public:
            Utils::vertex   _vertex1;
            Utils::vertex   _vertex2;
            Utils::vertex   _vertex3;
            Utils::vector3<float>   _normal;
            Utils::vector3<float>   _edge1;
            Utils::vector3<float>   _edge2;
    };
}

#endif //EPIPOV_RAY_TRIANGLE_HPP
