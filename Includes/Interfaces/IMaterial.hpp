/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#ifndef EPIPOV_RAY_IMATERIAL_HPP
    # define EPIPOV_RAY_IMATERIAL_HPP

    # include <memory>
    # include "intersection.hpp"
    # include "material.hpp"
    # include "ray.hpp"

namespace Interfaces {
    class IMaterial {
        public:
            virtual ~IMaterial() = default;

            class radianceSampler {
                public:
                virtual ~radianceSampler() = default;

                [[nodiscard]] virtual Utils::vector3<float> sample(const Utils::ray &ray) const = 0;
            };

            [[nodiscard]] virtual Utils::vector3<float> sample(const Modeling::intersection &intersection, const Utils::ray &incoming,
                const radianceSampler &radianceSampler,
                float u, float v, float p) const = 0;

            [[nodiscard]] virtual Utils::vector3<float> previewColour() const noexcept = 0;

            [[nodiscard]] virtual Utils::vector3<float> totalEmission(const Utils::vector3<float> &inbound) const
            noexcept = 0;

            static std::unique_ptr<IMaterial> from(const Modeling::material &mat);
    };
}

#endif //EPIPOV_RAY_IMATERIAL_HPP
