/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_MINMAXKDTREE_HPP
    # define EPIPOV_RAY_MINMAXKDTREE_HPP

    # include <memory>
    # include <vector>
    # include "triangle.hpp"

namespace Algo {

    class KDBox {
        public:
            KDBox();
            KDBox(const KDBox &box);
            explicit KDBox(std::vector<Modeling::triangle> const &triangles);
            ~KDBox() = default;

        public:
            KDBox   &operator=(const KDBox &box);

        public:
            [[nodiscard]] Utils::vector2<float>   getX() const;
            [[nodiscard]] Utils::vector2<float>   getY() const;
            [[nodiscard]] Utils::vector2<float>   getZ() const;

        public:
            bool        isIntersected(const Utils::ray &ray) const;
            [[nodiscard]] std::size_t getLongestAxis() const;

        private:
            Utils::vector2<float>   _x;
            Utils::vector2<float>   _y;
            Utils::vector2<float>   _z;
    };

    class KDNode {
        public:
            KDNode();
            KDNode(std::vector<Modeling::triangle> const &triangles, std::size_t depth);
            ~KDNode() = default;

        public:
            Modeling::intersection  intersected(const Utils::ray &ray);

        private:
            KDBox                   _box;
            std::shared_ptr<KDNode> _left;
            std::shared_ptr<KDNode> _right;
            std::vector<Modeling::triangle>   _triangles;
    };
}

#endif //EPIPOV_RAY_MINMAXKDTREE_HPP
