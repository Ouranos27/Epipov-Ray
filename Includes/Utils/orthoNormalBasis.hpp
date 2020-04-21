/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_ORTHONORMALBASIS_HPP
    # define EPIPOV_RAY_ORTHONORMALBASIS_HPP

    # include "vector3.hpp"

namespace Utils {
    class orthoNormalBasis {
        public:
            orthoNormalBasis() : _x(), _y(), _z() {};
            orthoNormalBasis(const Utils::vector3<float> &x, const Utils::vector3<float> &y, const Utils::vector3<float> &z)
            : _x(x), _y(y), _z(z)
            {};
            ~orthoNormalBasis() = default;

        public:
            [[nodiscard]] constexpr const Utils::vector3<float> &getX() const noexcept { return _x; }
            [[nodiscard]] constexpr const Utils::vector3<float> &getY() const noexcept { return _y; }
            [[nodiscard]] constexpr const Utils::vector3<float> &getZ() const noexcept { return _z; }

            /**[[nodiscard]] Utils::vector3<float> transform(const Utils::vector3<float> &pos) const noexcept {
                return Utils::vector3<float>(_x * pos.x + _y * pos.y + _z * pos.z);
            }*/

            static orthoNormalBasis fromXY(const Utils::vector3<float> &x, const Utils::vector3<float> &y);
            static orthoNormalBasis fromYX(const Utils::vector3<float> &y, const Utils::vector3<float> &x);

            static orthoNormalBasis fromXZ(const Utils::vector3<float> &x, const Utils::vector3<float> &z);
            static orthoNormalBasis fromZX(const Utils::vector3<float> &z, const Utils::vector3<float> &x);

            static orthoNormalBasis fromYZ(const Utils::vector3<float> &y, const Utils::vector3<float> &z);
            static orthoNormalBasis fromZY(const Utils::vector3<float> &z, const Utils::vector3<float> &y);

            static orthoNormalBasis fromZ(const Utils::vector3<float> &z);

        private:
            Utils::vector3<float> _x;
            Utils::vector3<float> _y;
            Utils::vector3<float> _z;
    };
}

#endif //EPIPOV_RAY_ORTHONORMALBASIS_HPP
