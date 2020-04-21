/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include <iostream>
#include "handler.hpp"

Tracing::handler::handler()
: _isRunning(false)
{}

Tracing::handler::handler(const Tracing::tracer &tracer,
    const Utils::vector2<unsigned int> &res)
    : _tracer(tracer), _resolution(res), _imageIdx(0), _sample(0), _isRunning(false)
{
    std::size_t size = res.x * res.y;
    _image.reserve(size);
    _image.resize(size, Utils::color(0x000000ff));
}

void Tracing::handler::start()
{
    std::size_t cores = std::thread::hardware_concurrency();
    _isRunning = true;
    while (cores--)
        _threads.emplace_back(std::thread(&Tracing::handler::execute, this));
    std::cout << "Handling over " << _threads.size() << " threads..." << std::endl;
}

void Tracing::handler::execute()
{
    std::size_t size = _resolution.y * _resolution.x;

    while (_isRunning) {
        std::size_t current = _imageIdx++;
        if (current >= size) {
            _imageIdx = _imageIdx % size;
            current %= size;
            if (current == 0) {
                _sample++;
                std::cout << "FRAME" << std::endl;
            }
        }
        Utils::color color = _tracer.raytracing(
            Utils::vector2<unsigned int>(current % _resolution.x,
                current / _resolution.x));
        float coef1 = _sample / (_sample + 1.f);
        float coef2 = (_sample == 0 ? 1 : 1.f / (_sample + 1.f));
        _mutex.lock();
        _image.at(current).setRed(_image.at(current).getRed() * coef1 + color.getRed() * coef2);
        _image.at(current).setGreen(_image.at(current).getGreen() * coef1 + color.getGreen() * coef2);
        _image.at(current).setBlue(_image.at(current).getBlue() * coef1 + color.getBlue() * coef2);
        _mutex.unlock();
    }
}

void Tracing::handler::stop()
{
    std::cout << "stopping threads..." << std::endl;
    _isRunning = false;
    for (auto &thread: _threads)
        thread.join();
    _threads.clear();
}

std::vector<Utils::color> Tracing::handler::getPixels() const
{
    return _image;
}

std::size_t Tracing::handler::getNbThreadsProcessed() const
{
    return _sample;
}
