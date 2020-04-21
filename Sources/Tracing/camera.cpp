/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include <cmath>
#include "camera.hpp"
#include "params.hpp"

Tracing::camera::camera()
: _position(Utils::vector3<float>(0, 0, 0))
, _screenResolution(Utils::vector2<unsigned int>(Utils::params::DefaultScreenWith, Utils::params::DefaultScreenHeight))
, _camPos1(Utils::vector3<float>(1, 0, 0)), _camPos2(Utils::vector3<float>(0, 1, 0))
, _camPos3(Utils::vector3<float>(0, 0, 1)), _screenDistance(0), _dis(0.f, 1.f)
, _gen(std::random_device()())
{
    setScreen();
}

Utils::vector3<float> Tracing::camera::getPosition() const
{
    return _position;
}


Utils::vector2<unsigned int> Tracing::camera::getScreenResolution() const
{
    return _screenResolution;
}

Utils::ray Tracing::camera::setRay(const Utils::vector2<unsigned int> &position)
{
    float mx = _dis(_gen);
    float my = _dis(_gen);

    Utils::vector3<float> direction = (_screenCorner + _camPos1 * ((position.x + mx) / _screenResolution.x)
        * _screenSize.x - _camPos2 * ((position.y + my) / _screenResolution.y) * _screenSize.y - _position) * _screenDistance;
    direction.normalize();
    return Utils::ray(_position, direction);
}

void Tracing::camera::setScreen()
{
    _screenDistance = 1.f;
    _screenResolution = Utils::vector2<unsigned int>(Utils::params::DefaultScreenWith, Utils::params::DefaultScreenHeight);
    float screenWidth = 2.f * std::tan((Utils::params::DefaultChampsDeVue / 2.f) * static_cast<float>(M_PI) / 180.f) * _screenDistance;
    _screenSize = Utils::vector2<float>(screenWidth, screenWidth * _screenResolution.y / _screenResolution.x);
    _screenCorner = _position + _camPos3 * (-1.f) - _camPos1 * (_screenSize.x / 2.f) + _camPos2 * (_screenSize.y / 2.f);
}

void Tracing::camera::setMatrix(const Utils::vector3<float> &camPos1,
    const Utils::vector3<float> &camPos2, const Utils::vector3<float> &camPos3,
    const Utils::vector3<float> &pos)
{
    _camPos1 = camPos1;
    _camPos2 = camPos2;
    _camPos3 = camPos3;
    _position = pos;
    setScreen();
}
