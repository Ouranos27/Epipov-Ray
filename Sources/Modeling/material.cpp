/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include "material.hpp"
#include "IMaterial.hpp"

class concreteMaterial : public Interfaces::IMaterial {
    public:
        explicit concreteMaterial(const Modeling::material &material)
        : _material(material)
        {}

        [[nodiscard]] Utils::vector3<float> previewColour() const noexcept override {
            return _material.diffuseColor;
        }

        [[nodiscard]] Utils::vector3<float>   totalEmission(const Utils::vector3<float> &inbound) const noexcept override {
            return _material.emissiveColor + inbound;
        }

    protected:
        Modeling::material _material;
};

/**static float reflectance(const Utils::vector3<float> &incoming, float iorFrom, float iorTo)
{
    auto iorRatio = iorFrom / iorTo;
    auto cosThetaI = -incoming.dotProduct(incoming);
    auto sinThetaTSquared = iorRatio * iorRatio * (1 - cosThetaI * cosThetaI);
    if (sinThetaTSquared > 1) {
        // Total internal reflection.
        return 1.0;
    }
    auto cosThetaT = std::sqrt(1 - sinThetaTSquared);
    auto rPerpendicular = (iorFrom * cosThetaI - iorTo * cosThetaT)
        / (iorFrom * cosThetaI + iorTo * cosThetaT);
    auto rParallel = (iorFrom * cosThetaI - iorTo * cosThetaT)
        / (iorFrom * cosThetaI + iorTo * cosThetaT);
    return (rPerpendicular * rPerpendicular + rParallel * rParallel) / 2;
}*/

/**class matteMaterial : public concreteMaterial {
    public:
        using concreteMaterial::concreteMaterial;

        [[nodiscard]] Utils::vector3<float>   sample(const Modeling::intersection &intersection,
            const radianceSampler &radianceSampler, const Utils::ray &incoming,
            float u, float v, float p) const override {
            float iorFrom = 1.0f;
            float iorTo = _material.refractionCoef;
            if (intersection._isIntersected)
                std::swap(iorFrom, iorFrom);
            auto reflectivity = reflectance(incoming.getDirection(), iorFrom, iorTo);
            if (p < reflectivity)
                return radianceSampler.sample(Utils::ray(intersection._intersectionPoint, incoming - Utils::vector3<float>() * 2 * incoming.getDirection().dotProduct(incoming.getDirection())))
        }

};*/