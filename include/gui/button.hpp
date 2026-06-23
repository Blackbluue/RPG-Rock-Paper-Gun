#pragma once

#include "gui/ui_element.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <functional>

struct ButtonTextures {
    const sf::Texture& normal_texture;
    const sf::Texture& selected_texture;
    const sf::Texture& pressed_texture;
};

class Button : public UIElement {
  public:
    typedef std::function<void()> Callback;

    /** Constructor for the Button class.
     *
     * The font and textures passed to the constructor are not owned by the
     * button, so it is the caller's responsibility to ensure that they remain
     * valid for the lifetime of the button.
     *
     * @param textures The textures for the different states of the button.
     * @param font The font to use for the button's text.
     * @param callback The callback function to call when the button is clicked.
     */
    Button(ButtonTextures textures, sf::Font& font, Callback callback);
    virtual ~Button() = default;

    /** Get the text of the button.
     *
     * The font that was passed to the constructor is used for the text. Once
     * the button is created, the font is not tracked by the button; the caller
     * is free to modify or switch out the font as needed, as long as they
     * maintain ownership of the font and ensure it remains valid for the
     * lifetime of the button.
     *
     * @return The text of the button.
     */
    sf::Text&   get_text() { return m_text; }
    /** Get the sprite of the button.
     *
     * The textures that were passed to the constructor are used for the sprite.
     * Note that the button will internally swap the textures based on the state
     * of the button (normal, selected, pressed). i.e do not manually change the
     * texture of the sprite.
     *
     * @return The sprite of the button.
     */
    sf::Sprite& get_sprite() { return m_sprite; }

    /** Buttons are always selectable.
     *
     * @return True, since buttons are always selectable.
     */
    virtual bool is_selectable() const override { return true; }
    /** Select the button.
     *
     * This changes the button's texture to the selected texture.
     */
    virtual void select() override;
    /** Deselect the button.
     *
     * This changes the button's texture to the normal texture.
     */
    virtual void deselect() override;

    /** Activate the button.
     *
     * This calls the button's callback function.
     */
    virtual void activate() override;

  private:
    /** Draw the button to the target.
     *
     * @param target The render target to draw to.
     * @param states The render states to use for drawing.
     */
    virtual void draw(
        sf::RenderTarget& target, sf::RenderStates states) const override;

    /** The textures for the states of the button. */
    const ButtonTextures m_textures;
    /** The sprite of the button. */
    sf::Sprite           m_sprite;
    /** The text displayed on the button. */
    sf::Text             m_text;
    /** The callback function to call when the button is clicked. */
    const Callback       m_callback;
};
