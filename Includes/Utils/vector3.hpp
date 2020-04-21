/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_VECTOR3_HPP
    # define EPIPOV_RAY_VECTOR3_HPP

    # include <cmath>
    # include "vector2.hpp"

namespace Utils {
    template <class T>
    struct vector3 : public vector2<T> {
        public:
            vector3() : z(0) {
                this->x = 0;
                this->y = 0;
            };
            /**vector3(const vector3 &other) : z(other.z){
                this->x = other.x;
                this->y = other.y;
            };*/
            vector3(const T &mx, const T &my, const T &mz) noexcept : z(mz) {
                this->x = mx;
                this->y = my;
            }
            virtual ~vector3() = default;;

        public:
            bool    operator==(const vector3 &other) const {
                return this->x == other.x && this->y == other.y && this->z == other.z;
            }

            bool    operator!=(const vector3 &other) const {
                return this->x != other.x || this->y != other.y || this->z != other.z;
            }

        public:
            vector3 operator+(const vector3 &other) const {
                return vector3(this->x + other.x, this->y + other.y, this->z + other.z);
            }

            vector3 operator-(const vector3 &other) const {
                return vector3(this->x - other.x, this->y - other.y, this->z - other.z);
            }

            vector3 operator*(T const &other) const {
                return vector3(this->x * other, this->y * other, this->z * other);
            }

            vector3 operator/(T const &other) const {
                return vector3(this->x / other, this->y / other, this->z / other);
            }

            /*** functions members ***/
        public:
            void    normalize() {
                float normal = std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2) + std::pow(z, 2));
                this->x = this->x / normal;
                this->y = this->y / normal;
                z = z / normal;
            };

            T   dotProduct(const vector3<T> &other) const {
                return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
            }

            vector3<T>   crossProduct(const vector3<T> &other) const {
                return vector3<T>((this->y * other.z) - (this->z * other.y),
                    (this->z * other.x) - (this->x * other.z),
                    (this->x * other.y) - (this->y * other.x));
            }

            T angle(const vector3<T> &other) const {
                return std::acos(
                    this->dotProduct(other) / (normal() * other.normal())) * 180.f /
                    static_cast<float>(M_PI);
            }

            T normal() const {
                return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2) + std::pow(z, 2));
            }

        public:
            T z;
    };

    template <class T>
    std::ostream& operator<<(std::ostream& out, const vector3<T>& v) {
        out << "(" << v.x << ", " << v.y << ", " << v.Z << ")";
        return out;
    }
}

#endif //EPIPOV_RAY_VECTOR3_HPP
