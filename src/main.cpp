#include <SFML/Window.hpp>

int main() {
    constexpr auto window_size = sf::Vector2u{800, 600};
    constexpr auto window_title = "RPG: Rock Paper Gun!";

    sf::Window window(sf::VideoMode(window_size), window_title);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.display();
    }
}
