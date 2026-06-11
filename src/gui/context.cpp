#include "gui/context.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>

Context::Context(sf::RenderWindow *window) : m_window(window), m_bg_texture() {
    std::string background_path = "resources/images/background.jpg";
    if (!m_bg_texture.loadFromFile(background_path)) {
        // TODO: handle missing background
    }

    // TODO: move loading of fonts to another class that handles resources
    sf::Font font;
    std::string font_path = "resources/fonts/vampire_wars.ttf";

    if (!font.openFromFile(font_path)) {
        // TODO: handle missing font
    }
}

void Context::render() {
    m_window->clear();
    sf::Sprite m_background_sprite(m_bg_texture);
    m_window->draw(m_background_sprite);
    m_window->display();
}
