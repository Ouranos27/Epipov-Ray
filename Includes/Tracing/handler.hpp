/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#ifndef EPIPOV_RAY_HANDLER_HPP
    # define EPIPOV_RAY_HANDLER_HPP

    # include <vector>
    # include <thread>
    # include <mutex>
    # include <atomic>
    # include "tracer.hpp"

namespace Tracing {
    class handler {
        public:
            handler();
            handler(const Tracing::tracer &resolution, const Utils::vector2<unsigned int> &res);
            ~handler() = default;

        public:
            void                        start();
            void                        execute();
            void                        stop();
            [[nodiscard]] std::vector<Utils::color>   getPixels() const;
            [[nodiscard]] std::size_t                 getNbThreadsProcessed() const;

        private:
            Tracing::tracer                 _tracer;
            Utils::vector2<unsigned int>    _resolution;
            std::vector<std::thread>        _threads;
            std::mutex                      _mutex;
            std::atomic<std::size_t>        _imageIdx;
            std::vector<Utils::color>       _image;
            std::atomic<std::size_t>        _sample;
            bool                            _isRunning;
    };
}

#endif //EPIPOV_RAY_HANDLER_HPP
