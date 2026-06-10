#pragma once

#include <SFML/Graphics.hpp>

class Application {
  public:
    Application();
    void run();

  private:
    void render();

    sf::RenderWindow m_window;
};
