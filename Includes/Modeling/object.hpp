/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_OBJECT_HPP
#define EPIPOV_RAY_OBJECT_HPP

#include <vector>
#include "minMaxKdTree.hpp"
#include "meshes.hpp"
#include "triangle.hpp"

namespace Modeling {
    class object : public meshes {
        public:
            object();
            object(std::vector<triangle> &triangles, const material &material, const std::string &name);
            ~object() override = default;

        public:
            Modeling::intersection intersected(const Utils::ray &ray) override;

        private:
            std::vector<triangle>   _triangles;
            Algo::KDNode            _tree;
    };
}

#endif //EPIPOV_RAY_OBJECT_HPP
