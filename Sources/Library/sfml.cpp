/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include <iostream>
#include "sfml.hpp"

Library::sfml::sfml()
: _window(), _framebuffer(), _texture(), _sprite() ,_width(), _height()
{}

Library::sfml::sfml(const Library::sfml &sf)
: _window(sf.getWindow()), _framebuffer(new sf::Uint8(sf.getWindow()->getSize().x * sf.getWindow()->getSize().y * 4)), _width(sf.getWidth()), _height(sf.getWidth())
{
    _texture.create(_window->getSize().x, _window->getSize().y);
    _sprite.setTexture(_texture);
}

Library::sfml::sfml(const int &width, const int &height)
: _window(new sf::RenderWindow(sf::VideoMode(width, height),
    "Epipov-Ray")), _framebuffer(new sf::Uint8[_window->getSize().x * _window->getSize().y * 4]), _width(width), _height(height)
{
    _window->setFramerateLimit(1);
    _texture.create(_window->getSize().x, _window->getSize().y);
    _sprite.setTexture(_texture);
    std::fill_n(_framebuffer, _window->getSize().x * _window->getSize().y * 4, 0xff);
}

Library::sfml::~sfml()
= default;

Library::sfml	&Library::sfml::operator=(const sfml &sf)
{
    _window = sf.getWindow();
    _framebuffer = new sf::Uint8(_window->getSize().x * _window->getSize().y * 4);
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

    _window = new sf::RenderWindow(sf::VideoMode(width, height
        , sf::VideoMode::getDesktopMode().bitsPerPixel),
        "Epipov-Ray", sf::Style::Close | sf::Style::Resize, settings);
    _framebuffer = new sf::Uint8[_window->getSize().x * _window->getSize().y * 4];
    _width = width;
    _height = height;
    _window->setFramerateLimit(1);
    _texture.create(_window->getSize().x, _window->getSize().y);
    _sprite.setTexture(_texture);
    std::fill_n(_framebuffer, _window->getSize().x * _window->getSize().y * 4, 0xffffff);
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
    sf::Event event{};

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            return Interfaces::IGraphicalLibrary::ESC;
        } else if (event.type == sf::Event::KeyPressed) {
            return switchKeys(event);
        }
    }
    return Interfaces::IGraphicalLibrary::NO_KEY_ENTERED;
}

bool Library::sfml::windowIsOpen() const
{
    return _window->isOpen();
}

sf::RenderWindow *Library::sfml::getWindow() const
{
    return _window;
}

void Library::sfml::myPutPixel(const unsigned int x, const unsigned int y, const std::uint32_t &colorCode)
{
    sf::Color color(colorCode);

    _framebuffer[(_width * y + x) * 4] = color.r;
    _framebuffer[(_width * y + x) * 4 + 1] = color.g;
    _framebuffer[(_width * y + x) * 4 + 2] = color.b;
    _framebuffer[(_width * y + x) * 4 + 3] = color.a;
}

void Library::sfml::drawer(const std::vector<Utils::color> &pixels)
{
    std::size_t i = 0;

    for (auto const &pixel : pixels) {
        Utils::component const &colorComponent = pixel.getColor();
        _framebuffer[i] = colorComponent.rgba.r;
        _framebuffer[i + 1] = colorComponent.rgba.g;
        _framebuffer[i + 2] = colorComponent.rgba.b;
        i += 4;
    }
    _texture.update(_framebuffer);
    _window->clear();
    _window->draw(_sprite);
    _window->display();
    //std::cout << "displayed" << std::endl;
}

