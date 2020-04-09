/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#ifndef EPIPOV_RAY_LAUNCHER_HPP
    # define EPIPOV_RAY_LAUNCHER_HPP

    # include "raytracer.hpp"

class launcher {
    public:
        launcher();
        launcher(const int &width, const int &height);
        launcher(const launcher &launch);
        ~launcher() = default;

    public:
        launcher &operator=(const launcher &launch);

    public:
        [[nodiscard]] Raytracing::raytracer getRaytracer() const;

    public:
        void start();

    private:
        Raytracing::raytracer _raytracer;
};

#endif //EPIPOV_RAY_LAUNCHER_HPP
