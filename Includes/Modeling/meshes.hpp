/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#ifndef EPIPOV_RAY_MESHES_HPP
    #   define EPIPOV_RAY_MESHES_HPP

    # include <string>
    # include "intersection.hpp"
    # include "ray.hpp"
    # include "vector3.hpp"
    # include "material.hpp"

namespace Modeling {
    class meshes {
        public:
            meshes();
            virtual ~meshes() = default;

        public:
            virtual Modeling::intersection intersected(const Utils::ray &ray) = 0;
            [[nodiscard]] material    getMaterial() const;

        protected:
            material    _material;
            std::string _name;
    };
}

#endif //EPIPOV_RAY_MESHES_HPP
