#include "gui/main_menu_context.hpp"

// #include <SFML/Graphics/Font.hpp>

MainMenuContext::MainMenuContext(
    sf::RenderWindow& window, ResourceLoader& resource_loader)
    : Context(window, resource_loader), m_bg_sprite(nullptr) {
    sf::Texture& bg_texture = m_resource_loader.get_texture("background");
    m_bg_sprite             = std::make_shared<UISprite>(bg_texture);
    m_base_canvas.pack(m_bg_sprite);
    // sf::Font& font = m_resource_loader.get_font("vampire_wars");
}

void MainMenuContext::render() {
    m_window.clear();
    m_window.draw(m_base_canvas);
    m_window.display();
}
