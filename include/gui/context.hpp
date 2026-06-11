#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

enum class Screen {
    MainMenu,
};

class Context {
  public:
    /** Constructor for the context.
     *
     * The context does not take ownership of the window, so it is the caller's
     * responsibility to ensure that the window remains valid for the lifetime
     * of the context.
     *
     * @param window A pointer to the RenderWindow.
     */
    Context(sf::RenderWindow *window) : m_window(window), m_bg_texture() {}
    virtual ~Context() = default;

    /** Render the context to the window. */
    virtual void render() = 0;

  protected:
    /** The window that the context will render to. */
    sf::RenderWindow *m_window;
    /** The background texture for the context. */
    sf::Texture m_bg_texture;
};
