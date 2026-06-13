#include "gui/button.hpp"

Button::Button(ButtonTextures textures, sf::Font& font, Callback callback)
    : m_textures(textures),
      m_callback(callback),
      m_sprite(sf::Sprite(m_textures.normal_texture)),
      m_text(sf::Text(font, "")) {}

void Button::select() {
    UIElement::select();
    m_sprite.setTexture(m_textures.selected_texture);
}
void Button::deselect() {
    UIElement::deselect();
    m_sprite.setTexture(m_textures.normal_texture);
}

void Button::activate() {
    UIElement::activate();
    if (is_disabled()) {
        return;
    }
    m_callback();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_sprite, states);
    target.draw(m_text, states);
}
