#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

enum class Screen {
    MainMenu,
};

class Context {
  public:
    Context(sf::RenderWindow *window);

    void render();

  private:
    sf::RenderWindow *m_window;
    sf::Texture m_bg_texture;
};
