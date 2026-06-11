#include "gui/application.hpp"

// TODO: include adjustable window size
constexpr auto window_size = sf::Vector2u{1920, 1080};
constexpr auto window_title = "RPG: Rock Paper Gun!";

Application::Application()
    : m_window(sf::VideoMode(window_size), window_title), m_contexts(),
      m_current_context(nullptr) {
    m_contexts.emplace(Screen::MainMenu, Context(&m_window));
    m_current_context = &m_contexts.at(Screen::MainMenu);
}

void Application::run() {
    while (m_window.isOpen()) {
        while (const std::optional event = m_window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                m_window.close();
        }

        m_current_context->render();
    }
}
