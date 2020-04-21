/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#include "intersection.hpp"
#include "params.hpp"
#include "ray.hpp"
#include "tracer.hpp"

Tracing::tracer::tracer()
{}

Tracing::tracer::tracer(const Loader::assimp &loader)
: _loader(loader), _camera(loader.getCameraFromScene())
{
    _meshes = loader.getMeshesFromScene();
    _lights = loader.getLightsFromScene();
}

Utils::color Tracing::tracer::raytracing(
    const Utils::vector2<unsigned int> &pixel)
{
    Utils::color color = Utils::color();
    Utils::ray ray = _camera.setRay(pixel);
    Modeling::intersection inter = handleIntersection(ray);
    if (inter._isIntersected) {
        for (auto & _light : _lights) {
            Utils::vector3<float> lightDir = _light->getPosition() - inter._intersectionPoint;
            lightDir.normalize();
            Modeling::intersection interLight = handleIntersection(Utils::ray(inter._intersectionPoint, lightDir));
            if (!interLight._isIntersected ||
                interLight._distance > (_light->getPosition() - inter._intersectionPoint).normal()) {
                float angle = lightDir.angle(inter._normal);
                if (angle > 90.f) {
                    angle = 180.f - angle;
                }
                color += (Utils::color(inter._material.diffuseColor) * ((-1.f / 90.f) * angle + 1.f));
            }
        }
    }
    return color;
}

/**Utils::vector3<float> Tracing::tracer::pathtracing(
    const Utils::vector2<unsigned int> &pixel, const size_t &depth)
{
    Utils::color color = Utils::color();
    Utils::ray ray = _camera.setRay(pixel);
    Modeling::intersection inter = handleIntersection(ray);
    if (inter._isIntersected) {
        const float p = 1/(2*M_PI);

    }
    return color;
}*/

/**Utils::vector3<float> Tracing::tracer::radiance(std::mt19937 &rng,
    const Utils::ray &ray, int depth) const
{
    if (depth >= Utils::params::MaxDepth)
        return Utils::vector3<float>();
    int numUSamples = depth == 0 ? Utils::params::FirstBounceUSamples : 1;
    int numVSamples = depth == 0 ? Utils::params::FirstBounceVSamples : 1;
    Modeling::intersection inter = this->handleIntersection(ray);
    if (!inter._isIntersected)
        return inter._material.diffuseColor;
    Utils::vector3<float> result;

    std::uniform_real_distribution<> unit(0, 1.0);
    for (auto uSample = 0; uSample < numUSamples; ++uSample) {
        for (auto vSample = 0; vSample < numVSamples; ++vSample) {
            auto u = (uSample + unit(rng)) / numUSamples;
            auto v = (vSample + unit(rng)) / numVSamples;
            auto p = unit(rng);
            //result += material.sample(hit, ray, sampler, u, v, p);
        }
    }

    return Utils::vector3<float>();
}*/

Modeling::intersection Tracing::tracer::handleIntersection(const Utils::ray &ray) const
{
    Modeling::intersection rtn;
    float min = -1;

    for (const auto & mesh : _meshes) {
        Modeling::intersection inter = mesh->intersected(ray);
        if (inter._isIntersected) {
            if (min == -1 || inter._distance < min) {
                min = inter._distance;
                rtn = inter;
            }
        }
    }
    return rtn;
}

Utils::vector2<unsigned int> Tracing::tracer::getResolution() const
{
    return _camera.getScreenResolution();
}

void Tracing::tracer::setBackground(
    std::shared_ptr<Interfaces::IBackground> const &background)
{
    _background = background;
}