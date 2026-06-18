#pragma once

#include "gui/context.hpp"
#include "gui/resource_loader.hpp"

class MainMenuContext : public Context {
  public:
    /** Constructor for the MainMenuContext.
     *
     * The context does not take ownership of the window, so it is the caller's
     * responsibility to ensure that the window remains valid for the lifetime
     * of the context.
     *
     * @param window A reference to the RenderWindow.
     * @param resource_loader A reference to the ResourceLoader.
     */
    MainMenuContext(sf::RenderWindow& window, ResourceLoader& resource_loader);

    /** Render the context to the window. */
    void render() override;
};
