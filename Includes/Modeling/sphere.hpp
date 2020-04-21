/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_SPHERE_HPP
    # define EPIPOV_RAY_SPHERE_HPP

    # include "vector3.hpp"
    # include "intersection.hpp"
    # include "ray.hpp"
    # include "meshes.hpp"

namespace Modeling {
    class sphere : public meshes {
        public:
            sphere();
            sphere(const sphere &sp) = default;
            sphere(const Utils::vector3<float> &centre, const float &radius);
            sphere(const Utils::vector3<float> &centre, const float &radius, const material &material);
            ~sphere() override = default;

        public:
            sphere  &operator=(const sphere &sp);

        public:
            [[nodiscard]] Utils::vector3<float>   getCentre() const;
            [[nodiscard]] float                   getRadius() const;

        public:
            Modeling::intersection  intersected(const Utils::ray &ray) override;

        private:
            Utils::vector3<float>   _centre;
            float                   _radius;
    };
}

#endif //EPIPOV_RAY_SPHERE_HPP
