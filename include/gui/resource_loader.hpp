#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <memory>
#include <string>

class ResourceLoader final {
  public:
    /** Constructor for the ResourceLoader. */
    ResourceLoader();

    /**
     * @brief Get the texture object
     *
     * If the texture is not found, an exception is thrown.
     *
     * @param name The name of the texture.
     * @return std::shared_ptr<sf::Texture> A shared pointer to the texture.
     */
    std::shared_ptr<sf::Texture> get_texture(const std::string &name);

    /**
     * @brief Get the font object
     *
     * If the font is not found, an exception is thrown.
     *
     * @param name The name of the font.
     * @return std::shared_ptr<sf::Font> A shared pointer to the font.
     */
    std::shared_ptr<sf::Font> get_font(const std::string &name);

  private:
    /**
     * @brief Load a texture from a file and store it in the textures map.
     *
     * @param name The name of the texture file.
     */
    void load_texture(const std::string &name);

    /**
     * @brief Load a font from a file and store it in the fonts map.
     *
     * @param name The name of the font file.
     */
    void load_font(const std::string &name);

    /** The loaded textures. */
    std::map<std::string, std::shared_ptr<sf::Texture>> m_textures;
    /** The loaded fonts. */
    std::map<std::string, std::shared_ptr<sf::Font>> m_fonts;
};
