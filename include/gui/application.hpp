#pragma once

#include "gui/context.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>

class Application {
  public:
    Application();
    void run();

  private:
    std::map<Screen, Context> m_contexts;
    Context *m_current_context;
    sf::RenderWindow m_window;
};
