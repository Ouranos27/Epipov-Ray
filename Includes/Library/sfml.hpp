/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** Created by philippe,
*/

#ifndef EPIPOV_RAY_SFML_HPP
    #define EPIPOV_RAY_SFML_HPP

    # include <SFML/Graphics.hpp>
    # include "color.hpp"
    # include "IGraphicalLibrary.hpp"


namespace Library {

    class sfml : public Interfaces::IGraphicalLibrary {

        public:
            sfml();
            sfml(const int &width, const int &height);
            sfml(const Library::sfml &sf);
            ~sfml() override;

        public:
            Library::sfml &operator=(const Library::sfml &sf);

        public:
            void initWindow(const int &width, const int &height) override ;
            void closeWindow() override ;
            void refreshWindow() override ;
            void clear() override ;
            IGraphicalLibrary::keys getKey() override ;
            [[nodiscard]] bool windowIsOpen() const override;

        public:
            [[nodiscard]] sf::RenderWindow *getWindow() const;
            [[nodiscard]] int getWidth() const;
            [[nodiscard]] int getHeight() const;

        public:
            void    setWindow(sf::RenderWindow *window);

        public:
            void    myPutPixel(unsigned int x, unsigned int y, const std::uint32_t &colorCode);
            void    drawer(const std::vector<Utils::color> &pixels);

        private:
            sf::RenderWindow    *_window;
            sf::Uint8           *_framebuffer;
            sf::Texture         _texture;
            sf::Sprite          _sprite;
            int                 _width;
            int                 _height;
    };
}

#endif //EPIPOV_RAY_SFML_HPP
