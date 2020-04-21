/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_VECTOR2_HPP
    # define EPIPOV_RAY_VECTOR2_HPP

    # include <ostream>

namespace Utils {
    template <class T>
    struct vector2 {
        public:
            vector2(): x(0), y(0) {};
            vector2(const vector2<T> &other) : x(other.x), y(other.y) {};
            vector2(const T &mx, const T &my): x(mx), y(my) {};
            virtual ~vector2() = default;

        public:
            bool    operator==(const vector2<T> &other) const {
                return (x == other.x && y == other.y);
            }

            bool    operator!=(const vector2<T> &other) const {
                return (x != other.x && y != other.y);
            }

        public:
            vector2<T>  operator+(const vector2<T> &other) const {
                return vector2<T>(x + other.x, y + other.y);
            }

            vector2<T>  operator-(const vector2<T> &other) const {
                return vector2<T>(x - other.x, y - other.y);
            }

            vector2<T>  operator*(T const &other) const {
                return vector2<T>(x * other, y * other);
            }

            vector2<T>  operator/(T const &other) const {
                return vector2<T>(x / other, y / other);
            }

        public:
            T   x;
            T   y;
    };

    template <class T>
    std::ostream& operator<<(std::ostream& out, const vector2<T>& v) {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
}

#endif //EPIPOV_RAY_VECTOR2_HPP
