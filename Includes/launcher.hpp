/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#ifndef EPIPOV_RAY_LAUNCHER_HPP
    # define EPIPOV_RAY_LAUNCHER_HPP

    # include "tracer.hpp"

class launcher {
    public:
        launcher();
        launcher(const launcher &launch);
        ~launcher() = default;

    public:
        launcher &operator=(const launcher &launch);

    public:
        [[nodiscard]] Library::sfml   getLib() const;

    public:
        void    laudFromArgument(int ac, char **av);

    private:
        Library::sfml   _lib;
};

#endif //EPIPOV_RAY_LAUNCHER_HPP
