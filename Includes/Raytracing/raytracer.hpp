/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_RAYTRACER_HPP
    # define EPIPOV_RAY_RAYTRACER_HPP

    # include <SFML/Graphics.hpp>
    # include "sfml.hpp"

namespace Raytracing {

    class raytracer {
        public:
            raytracer();
            raytracer(const int &width, const int &height);
            ~raytracer() = default;

        public:
            raytracer &operator=(const raytracer &raytracer1);

        public:
            void    drawer();

        public:
            [[nodiscard]] Library::sfml getLib() const;

        private:
            Library::sfml _lib;
    };
}

#endif //EPIPOV_RAY_RAYTRACER_HPP
