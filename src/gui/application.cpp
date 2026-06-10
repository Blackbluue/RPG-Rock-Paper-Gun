#include "gui/application.h"
constexpr auto window_size = sf::Vector2u{800, 600};
constexpr auto window_title = "RPG: Rock Paper Gun!";

Application::Application()
    : m_window(sf::VideoMode(window_size), window_title) {
    sf::Font font;
    std::string fontPath = "resources/fonts/vampire_wars.ttf";

    if (fontPath.empty() || !font.openFromFile(fontPath)) {
        // TODO: handle missing font
    }
}

void Application::run() {
    while (m_window.isOpen()) {
        while (const std::optional event = m_window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                m_window.close();
        }

        render();
    }
}

void Application::render() {
    m_window.clear();
    m_window.setView(m_window.getDefaultView());
    m_window.display();
}
