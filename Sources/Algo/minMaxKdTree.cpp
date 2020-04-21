/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#include <memory>
#include <Utils/params.hpp>
#include <iostream>
#include "Algo/minMaxKdTree.hpp"

Algo::KDNode::KDNode()
: _left(), _right(), _triangles()
{}

Algo::KDNode:: KDNode(std::vector<Modeling::triangle> const &triangles,
    std::size_t depth)
    : _box(triangles), _left(nullptr), _right(nullptr)
{
    std::size_t size = triangles.size();
    if (triangles.size() > Utils::params::KDTreeMin && depth) {
        std::vector<Modeling::triangle> tleft;
        std::vector<Modeling::triangle> tright;
        Utils::vector3<float> midpoint;
        for (std::size_t i = 0; i < size; ++i) {
            midpoint = midpoint + triangles[i].getMidPoint() / static_cast<float>(size);
        }
        std::size_t axis = _box.getLongestAxis();
        for (auto &triangle: triangles) {
            switch (axis) {
            case 0:
                triangle.getMidPoint().x > midpoint.x ? tright.push_back(triangle) : tleft.push_back(triangle);
                break;
            case 1:
                triangle.getMidPoint().y > midpoint.y ? tright.push_back(triangle) : tleft.push_back(triangle);
                break;
            case 2:
                triangle.getMidPoint().z > midpoint.z ? tright.push_back(triangle) : tleft.push_back(triangle);
                break;
            default:
                continue;
            }
        }
        _left = std::make_shared<KDNode>(tleft, depth - 1);
        _right = std::make_shared<KDNode>(tright, depth - 1);
    } else {
        _triangles = triangles;
    }
}

Modeling::intersection Algo::KDNode::intersected(const Utils::ray &ray)
{
    Modeling::intersection intersection = Modeling::intersection();
    if (!(_box.isIntersected(ray))) {
        return intersection;
    } else if (!_left && !_right) {
        Modeling::intersection inter;
        float min = -1;
        for (auto & _triangle : _triangles) {
            inter = _triangle.intersected(ray);
            if (inter._isIntersected) {
                if (min == -1 || inter._distance < min) {
                    min = inter._distance;
                    intersection = inter;
                }
            }
        }
        return intersection;
    } else {
        Modeling::intersection left = _left->intersected(ray);
        Modeling::intersection right = _right->intersected(ray);

        if (left._isIntersected && right._isIntersected)
            return left._distance < right._distance ? left : right;
        return left._isIntersected ? left : right._isIntersected ? right : intersection;
    }
}

/************ KDBox ************/

Algo::KDBox::KDBox()
: _x(), _y(), _z()
{}

Algo::KDBox::KDBox(const Algo::KDBox &box)
: _x(box.getX()), _y(box.getY()), _z(box.getZ())
{}

Algo::KDBox::KDBox(std::vector<Modeling::triangle> const &triangles)
{
    for (std::size_t i = 0; i < triangles.size(); i++) {
        if (i == 0) {
            _x = triangles.at(i).getMinMaxX();
            _y = triangles.at(i).getMinMaxY();
            _z = triangles.at(i).getMinMaxZ();
        } else {
            Utils::vector2<float> mx = triangles.at(i).getMinMaxX();
            Utils::vector2<float> my = triangles.at(i).getMinMaxY();
            Utils::vector2<float> mz = triangles.at(i).getMinMaxZ();
            if (mx.x < _x.x) _x.x = mx.x;
            if (mx.y > _x.y) _x.y = mx.y;
            if (my.x < _y.x) _y.x = my.x;
            if (my.y > _y.y) _y.y = my.y;
            if (mz.x < _z.x) _z.x = mz.x;
            if (mz.y > _z.y) _z.y = mz.y;
        }
    }
}

Algo::KDBox &Algo::KDBox::operator=(const Algo::KDBox &box)
{
    _x = box.getX();
    _y = box.getY();
    _z = box.getZ();
    return *this;
}

Utils::vector2<float> Algo::KDBox::getX() const
{
    return _x;
}

Utils::vector2<float> Algo::KDBox::getY() const
{
    return _y;
}

Utils::vector2<float> Algo::KDBox::getZ() const
{
    return _z;
}

bool Algo::KDBox::isIntersected(const Utils::ray &ray) const
{
    float tx1 = (_x.x - ray.getOrigin().x) / ray.getDirection().x;
    float tx2 = (_x.y - ray.getOrigin().x) / ray.getDirection().x;
    float ty1 = (_y.x - ray.getOrigin().y) / ray.getDirection().y;
    float ty2 = (_y.y - ray.getOrigin().y) / ray.getDirection().y;
    float tz1 = (_z.x - ray.getOrigin().z) / ray.getDirection().z;
    float tz2 = (_z.y - ray.getOrigin().z) / ray.getDirection().z;
    float tMin = std::max(std::max(std::min(tx1, tx2), std::min(ty1, ty2)), std::min(tz1, tz2));
    float tMax = std::min(std::min(std::max(tx1, tx2), std::max(ty1, ty2)), std::max(tz1, tz2));
    if (tMin <= tMax) {
        return !(tMin <= Utils::params::Epsilon &&
            tMax <= Utils::params::Epsilon);
    }
    return false;
}

std::size_t Algo::KDBox::getLongestAxis() const
{
    float x = _x.y - _x.x;
    float y = _y.y - _y.x;
    float z = _z.y - _z.x;
    float max = std::max(x, std::max(y, z));
    return max == x ? 0 : max == y ? 1 : 2;
}
