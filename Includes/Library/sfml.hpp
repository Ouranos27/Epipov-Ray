/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** Created by philippe,
*/

#ifndef EPIPOV_RAY_SFML_HPP
    #define EPIPOV_RAY_SFML_HPP

    # include <SFML/Graphics.hpp>
    # include "IGraphicalLibrary.hpp"


namespace Library {

    class sfml : public Interfaces::IGraphicalLibrary {

        public:
            sfml();
            sfml(const int &width, const int &height);
            sfml(const Library::sfml &sf);
            virtual ~sfml();

        public:
            Library::sfml &operator=(const Library::sfml &sf);

        public:
            virtual void initWindow(const int &width, const int &height);
            virtual void closeWindow();
            virtual void refreshWindow();
            virtual void clear();
            virtual IGraphicalLibrary::keys getKey();
            virtual bool windowIsOpen() const;

        public:
            sf::RenderWindow *getWindow() const;
            int getWidth() const;
            int getHeight() const;

        public:
            void    setWindow(sf::RenderWindow *window);

        public:
            void    myPutPixel(const sf::Vector2i &pos, const sf::Color &color);
            void    updateTexture();

        private:
            sf::RenderWindow *_window;
            sf::Uint8       *_pixels;
            sf::Texture     *_texture;
            int             _width;
            int             _height;
    };
}

#endif //EPIPOV_RAY_SFML_HPP
