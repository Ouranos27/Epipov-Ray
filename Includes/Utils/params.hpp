/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_PARAMS_HPP
    # define EPIPOV_RAY_PARAMS_HPP

    #include <cstdlib>

namespace Utils {
    struct params {
        static const unsigned int   DefaultScreenWith = 1080;
        static const unsigned int   DefaultScreenHeight = 720;
        static const unsigned int   DefaultChampsDeVue = 90;
        static constexpr float      Epsilon = 0.000001f;
        static constexpr float      MinDistance = 0.001f;
        static const std::size_t    KDTreeDepth = 20;
        static const std::size_t    KDTreeMin = 12;
        static const int            MaxDepth = 5;
        static const int            FirstBounceUSamples = 4;
        static const int            FirstBounceVSamples = 4;
        static const int            SamplesPerPixel = 40;
    };
}

#endif //EPIPOV_RAY_PARAMS_HPP
