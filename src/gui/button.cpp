#include "gui/button.hpp"

Button::Button(ButtonTextures textures, sf::Font& font, Callback callback)
    : m_textures(textures),
      m_callback(callback),
      m_disabled(false),
      m_selected(false),
      m_sprite(sf::Sprite(m_textures.normal_texture)),
      m_text(sf::Text(font, "")) {}

void Button::select() {
    m_sprite.setTexture(m_textures.selected_texture);
    m_selected = true;
}
void Button::deselect() {
    m_sprite.setTexture(m_textures.normal_texture);
    m_selected = false;
}

void Button::activate() const {
    if (!m_disabled) {
        m_callback();
    }
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_sprite, states);
    target.draw(m_text, states);
}
