#include "gui/application.hpp"

#include "gui/main_menu_context.hpp"

// TODO: include adjustable window size
constexpr auto window_size  = sf::Vector2u{1920, 1080};
constexpr auto window_title = "RPG: Rock Paper Gun!";

Application::Application()
    : m_window(sf::VideoMode(window_size), window_title),
      m_resource_loader(),
      m_contexts(),
      m_current_context(nullptr) {
    auto main_menu_context =
        std::make_unique<MainMenuContext>(m_window, m_resource_loader);
    m_current_context = main_menu_context.get();
    m_contexts.emplace(Screen::MainMenu, std::move(main_menu_context));
}

void Application::run() {
    while (m_window.isOpen()) {
        while (const std::optional event = m_window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) m_window.close();
        }

        m_current_context->render();
    }
}
