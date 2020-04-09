/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include "sfml.hpp"

Library::sfml::sfml()
: _window(), _pixels(new sf::Uint8()), _width(), _height()
{
    _texture->create(0, 0);
}

Library::sfml::sfml(const Library::sfml &sf)
: _window(sf.getWindow()), _pixels(new sf::Uint8(sf.getWindow()->getSize().x* sf.getWindow()->getSize().y * 4)), _width(sf.getWidth()), _height(sf.getWidth())
{
    _texture->create(sf.getWindow()->getSize().x, sf.getWindow()->getSize().y);
}

Library::sfml::sfml(const int &width, const int &height)
: _window(new sf::RenderWindow(sf::VideoMode(width, height, sf::VideoMode::getDesktopMode().bitsPerPixel),
    "Epipov-Ray", sf::Style::Close | sf::Style::Resize)), _pixels(new sf::Uint8(width * height * 4)), _width(width), _height(height)
{
    _texture->create(width, height);
}

Library::sfml::~sfml()
= default;

Library::sfml	&Library::sfml::operator=(const sfml &sf)
{
    _window = sf.getWindow();
    _texture->create(sf.getWindow()->getSize().x, sf.getWindow()->getSize().y);
    _width = sf.getWidth();
    _height = sf.getHeight();
    return *this;
}

int Library::sfml::getWidth() const
{
    return _width;
}

int Library::sfml::getHeight() const
{
    return _height;
}

void Library::sfml::setWindow(sf::RenderWindow *window)
{
    _window = window;
}

void Library::sfml::initWindow(const int &width, const int &height)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow(sf::VideoMode(width, height
        , sf::VideoMode::getDesktopMode().bitsPerPixel),
        "Epipov-Ray", sf::Style::Close | sf::Style::Resize, settings);
}

void Library::sfml::refreshWindow()
{
    this->_window->display();
}

void Library::sfml::clear()
{
    this->_window->clear(sf::Color::Black);
}

void Library::sfml::closeWindow()
{
    this->_window->close();
}

static Interfaces::IGraphicalLibrary::keys	switchKeys(sf::Event &event)
{
    switch (event.key.code) {
    case sf::Keyboard::Escape :
        return Interfaces::IGraphicalLibrary::ESC;
    default:
        return Interfaces::IGraphicalLibrary::NO_KEY_ENTERED;
    }
}

Interfaces::IGraphicalLibrary::keys Library::sfml::getKey()
{
    IGraphicalLibrary::keys	key = IGraphicalLibrary::NO_KEY_ENTERED;
    sf::Event event{};

    if (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window->close();
        } else if (event.type == sf::Event::KeyPressed) {
            key = switchKeys(event);
        }
    }
    return key;
}

bool Library::sfml::windowIsOpen() const
{
    return _window->isOpen();
}

sf::RenderWindow *Library::sfml::getWindow() const
{
    return _window;
}

void Library::sfml::myPutPixel(const sf::Vector2i &pos, const sf::Color &color)
{
    _pixels[(_width * pos.y + pos.x) * 4] = color.r;
    _pixels[(_width * pos.y + pos.x) * 4 + 1] = color.g;
    _pixels[(_width * pos.y + pos.x) * 4 + 2] = color.b;
    _pixels[(_width * pos.y + pos.x) * 4 + 3] = color.a;
}

void Library::sfml::updateTexture()
{
    _texture->update(_pixels);
}

