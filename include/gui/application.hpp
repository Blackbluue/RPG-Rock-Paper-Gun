#pragma once

#include "gui/context.hpp"
#include "gui/resource_loader.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <memory>

class Application final {
  public:
    /** Constructor for the Application. */
    Application();
    /** Run the application. */
    void run();

  private:
    /** A map of contexts for each screen. */
    std::map<Screen, std::shared_ptr<Context>> m_contexts;
    /** The resource loader for the application. */
    std::shared_ptr<ResourceLoader> m_resource_loader;
    /** The current context being displayed. */
    std::shared_ptr<Context> m_current_context;
    /** The window for the application. */
    sf::RenderWindow m_window;
};
