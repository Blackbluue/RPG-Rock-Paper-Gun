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
    /** The window for the application. */
    sf::RenderWindow                           m_window;
    /** The resource loader for the application. */
    ResourceLoader                             m_resource_loader;
    /** A map of contexts for each screen. */
    std::map<Screen, std::unique_ptr<Context>> m_contexts;
    /** The current context being displayed. */
    Context*                                   m_current_context;
};
