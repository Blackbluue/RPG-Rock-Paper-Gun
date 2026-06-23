#pragma once

#include "gui/ui_element.hpp"

#include <SFML/Graphics/Sprite.hpp>

class UISprite : public UIElement {
  public:
    /** Cannot construct a UISprite from an rvalue texture. */
    UISprite(const sf::Texture&& texture) = delete;
    /** Construct the sprite from a source texture.
     *
     * @param texture The texture to use for the sprite.
     */
    explicit UISprite(const sf::Texture& texture) : m_sprite(texture) {}
    /** Cannot construct a UISprite from an rvalue texture. */
    UISprite(
        const sf::Texture& texture, const sf::IntRect&& rectangle) = delete;
    /** Construct the sprite from a sub-rectangle of a source texture.
     *
     * @param texture The texture to use for the sprite.
     * @param rectangle The sub-rectangle of the texture to display.
     */
    UISprite(const sf::Texture& texture, const sf::IntRect& rectangle)
        : m_sprite(texture, rectangle) {}
    virtual ~UISprite() = default;

    /** UISprites are not selectable.
     *
     * @return False, since UISprites are not selectable.
     */
    virtual bool is_selectable() const override { return false; }
    /** Select the UISprite.
     *
     * This has no effect since UISprites are not selectable.
     */
    virtual void select() override {}
    /** Deselect the UISprite.
     *
     * This has no effect since UISprites are not selectable.
     */
    virtual void deselect() override {}

    /** Activate the UISprite.
     *
     * This has no effect since UISprites cannot be activated.
     */
    virtual void activate() override {}
    /** Deactivate the UISprite.
     *
     * This has no effect since UISprites cannot be deactivated.
     */
    virtual void deactivate() override {}

    /** Enable the UISprite.
     *
     * This has no effect since UISprites cannot be activated.
     */
    virtual void enable() override {}
    /** Disable the UISprite.
     *
     * This has no effect since UISprites cannot be activated.
     */
    virtual void disable() override {}

    /** Cannot set the texture from an rvalue. */
    void setTexture(
        const sf::Texture&& texture, bool resetRect = false) = delete;
    /**
     * Change the source texture of the sprite.
     *
     *  The texture argument refers to a texture that must exist as long as the
     * sprite uses it. Indeed, the sprite doesn't store its own copy of the
     * texture, but rather keeps a pointer to the one that you passed to this
     * function. If the source texture is destroyed and the sprite tries to use
     * it, the behavior is undefined. If resetRect is true, the TextureRect
     * property of the sprite is automatically adjusted to the size of the new
     * texture. If it is false, the texture rect is left unchanged.
     *
     * @param texture New texture
     * @param resetRect Should the texture rect be reset to the size of the new
     * texture?
     */
    void setTexture(const sf::Texture& texture, bool resetRect = false) {
        m_sprite.setTexture(texture, resetRect);
    }
    virtual void draw(
        sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform *= getTransform();
        target.draw(m_sprite, states);
    }

  private:
    sf::Sprite m_sprite;
};
