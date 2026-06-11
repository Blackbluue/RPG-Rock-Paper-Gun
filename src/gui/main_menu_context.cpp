#include "gui/main_menu_context.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>

MainMenuContext::MainMenuContext(sf::RenderWindow *window) : Context(window) {
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

void MainMenuContext::render() {
    m_window->clear();
    sf::Sprite m_background_sprite(m_bg_texture);
    m_window->draw(m_background_sprite);
    m_window->display();
}
