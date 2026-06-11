#pragma once

#include "gui/context.hpp"

class MainMenuContext : public Context {
  public:
    /** Constructor for the MainMenuContext.
     *
     * The context does not take ownership of the window, so it is the caller's
     * responsibility to ensure that the window remains valid for the lifetime
     * of the context.
     *
     * @param window A pointer to the RenderWindow.
     */
    MainMenuContext(sf::RenderWindow *window);

    /** Render the context to the window. */
    void render() override;
};
