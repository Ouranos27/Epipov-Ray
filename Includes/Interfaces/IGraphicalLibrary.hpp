/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#ifndef EPIPOV_RAY_IGRAPHICALLIBRARY_HPP
    #define EPIPOV_RAY_IGRAPHICALLIBRARY_HPP

namespace Interfaces {
    class IGraphicalLibrary {

        public:
            virtual ~IGraphicalLibrary() = default;

        public:
            enum keys {
                ESC,
                NO_KEY_ENTERED
            };

        public:
            virtual void initWindow(const int &width,
                const int &height) = 0;
            virtual void closeWindow() = 0;
            virtual void refreshWindow() = 0;
            virtual void clear() = 0;
            virtual IGraphicalLibrary::keys getKey() = 0;
            virtual bool windowIsOpen() const = 0;
    };
}

#endif //EPIPOV_RAY_IGRAPHICALLIBRARY_HPP
