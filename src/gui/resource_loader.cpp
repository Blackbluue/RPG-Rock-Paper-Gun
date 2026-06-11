#include "gui/resource_loader.hpp"
#include <filesystem>

ResourceLoader::ResourceLoader() : m_textures(), m_fonts() {
    load_texture("resources/images/background.jpg");
    load_font("resources/fonts/vampire_wars.ttf");
}

void ResourceLoader::load_texture(const std::string &name) {
    auto texture{std::make_shared<sf::Texture>()};
    if (!texture->loadFromFile(name)) {
        throw std::runtime_error("Failed to load texture: " + name);
    }
    m_textures[std::filesystem::path(name).stem().string()] = texture;
}

void ResourceLoader::load_font(const std::string &name) {
    auto font{std::make_shared<sf::Font>()};
    if (!font->openFromFile(name)) {
        throw std::runtime_error("Failed to load font: " + name);
    }
    m_fonts[std::filesystem::path(name).stem().string()] = font;
}

std::shared_ptr<sf::Texture>
ResourceLoader::get_texture(const std::string &name) {
    if (m_textures.contains(name)) {
        return m_textures.at(name);
    } else {
        throw std::runtime_error("Texture not found: " + name);
    }
}

std::shared_ptr<sf::Font> ResourceLoader::get_font(const std::string &name) {
    if (m_fonts.contains(name)) {
        return m_fonts.at(name);
    } else {
        throw std::runtime_error("Font not found: " + name);
    }
}
