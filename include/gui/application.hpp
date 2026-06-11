#pragma once

#include "gui/context.hpp"
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
    /** The current context being displayed. */
    std::shared_ptr<Context> m_current_context;
    /** The window for the application. */
    sf::RenderWindow m_window;
};
