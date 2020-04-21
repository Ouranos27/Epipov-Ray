/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_TRACER_HPP
    # define EPIPOV_RAY_TRACER_HPP

    # include <SFML/Graphics.hpp>
    # include <memory>
    # include "assimp.hpp"
    # include "light.hpp"
    # include "meshes.hpp"
    # include "color.hpp"
    # include "vector2.hpp"
    # include "sfml.hpp"
    # include "camera.hpp"
    # include "background.hpp"

namespace Tracing {

    class tracer {
        public:
            tracer();
            explicit tracer(const Loader::assimp &loader);
            ~tracer() = default;

        public:
            tracer &operator=(const tracer &raytracer1) = default;

        public:
            [[nodiscard]] Utils::vector2<unsigned int>    getResolution() const;

        public:
            Utils::color    raytracing(const Utils::vector2<unsigned int> &pixel);
            Utils::color    pathtracing(const Utils::vector2<unsigned int> &pixel, const size_t &depth);
            Utils::vector3<float>   radiance(std::mt19937 &rng, const Utils::ray &ray, int depth) const;
            void            setBackground(std::shared_ptr<Interfaces::IBackground> const &background);

        public:
            [[nodiscard]] Modeling::intersection    handleIntersection(const Utils::ray &ray) const;

        private:
            Loader::assimp          _loader;
            camera                  _camera;
            std::vector<std::shared_ptr<Modeling::meshes>>  _meshes;
            std::vector<std::shared_ptr<Utils::light>>  _lights;
            std::shared_ptr<Interfaces::IBackground>              _background;
    };
}

#endif //EPIPOV_RAY_TRACER_HPP
