/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_MATERIAL_HPP
    # define EPIPOV_RAY_MATERIAL_HPP

/**#include "ray.hpp"
#include "intersection.hpp"*/

#include "vector3.hpp"

namespace Modeling {
    class material {
        public:
            material(): name(std::string("")), specularExponent(96)
                , refractionCoef(1.f), opacity(1.f), illumination(0)
                , ambiantColor(Utils::vector3<float>(.75, .75, .75))
                , diffuseColor(Utils::vector3<float>(0, 1, 0))
                , specularColor(Utils::vector3<float>(.5, .5, .5))
                , emissiveColor(Utils::vector3<float>(0, 0, 0)) {};
            material(const material &mat) = default;
            virtual ~material() = default;

        public:
            material &operator=(const material &mat) = default;

        /**public:
            class radianceSampler {
                public:
                    virtual ~radianceSampler() = default;

                public:
                    [[nodiscard]] virtual Utils::vector3<float> sample(const Utils::ray &ray) const = 0;
                    [[nodiscard]] virtual Utils::vector3<float> sample(const Modeling::intersection &inter,
                        const Utils::ray &incoming, const radianceSampler &radianceSampler,
                        float u, float v, float p) const = 0;
                    [[nodiscard]] virtual Utils::vector3<float>   previewColor() const noexcept = 0;
                    [[nodiscard]] virtual Utils::vector3<float>   totalEmission(const Utils::vector3<float> &inbound) const noexcept = 0;

                    static std::unique_ptr<Modeling::material> from(const material &mat);
            };*/

        public:
            std::string             name;
            float                   specularExponent;
            float                   refractionCoef;
            float                   opacity;
            std::size_t             illumination;
            Utils::vector3<float>   ambiantColor;
            Utils::vector3<float>   diffuseColor;
            Utils::vector3<float>   specularColor;
            Utils::vector3<float>   emissiveColor;
    };
}

#endif //EPIPOV_RAY_MATERIAL_HPP
