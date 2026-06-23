#include "gui/resource_loader.hpp"

#include <filesystem>

ResourceLoader::ResourceLoader() : m_textures(), m_fonts() {
    // TODO: Use config file to load resources instead of hardcoding them here
    load_texture("resources/images/background.png");
    load_font("resources/fonts/vampire_wars.ttf");
}

void ResourceLoader::load_texture(const std::string& name) {
    sf::Texture texture = sf::Texture();
    if (!texture.loadFromFile(name)) {
        throw std::runtime_error("Failed to load texture: " + name);
    }
    m_textures[std::filesystem::path(name).stem().string()] = texture;
}

void ResourceLoader::load_font(const std::string& name) {
    sf::Font font = sf::Font();
    if (!font.openFromFile(name)) {
        throw std::runtime_error("Failed to load font: " + name);
    }
    m_fonts[std::filesystem::path(name).stem().string()] = font;
}

sf::Texture& ResourceLoader::get_texture(const std::string& name) {
    if (m_textures.contains(name)) {
        return m_textures.at(name);
    } else {
        throw std::runtime_error("Texture not found: " + name);
    }
}

sf::Font& ResourceLoader::get_font(const std::string& name) {
    if (m_fonts.contains(name)) {
        return m_fonts.at(name);
    } else {
        throw std::runtime_error("Font not found: " + name);
    }
}
