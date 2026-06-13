#include "gui/main_menu_context.hpp"

#include "gui/resource_loader.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>

MainMenuContext::MainMenuContext(
    sf::RenderWindow* window, std::shared_ptr<ResourceLoader> resource_loader)
    : Context(window, resource_loader) {
    m_bg_texture = *m_resource_loader->get_texture("background");
    std::shared_ptr<sf::Font> font =
        m_resource_loader->get_font("vampire_wars");
    if (!font) {
        // TODO: handle missing font
    }
}

void MainMenuContext::render() {
    m_window->clear();
    sf::Sprite m_background_sprite(m_bg_texture);
    m_window->draw(m_background_sprite);
    m_window->display();
}
