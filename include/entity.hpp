#pragma once

#include <SFML/Graphics.hpp>

class entity {
public:
  virtual void update() = 0;
  virtual void draw(sf::RenderWindow &window) = 0;
  sf::FloatRect get_bounding_box(const sf::Sprite &sprite) const noexcept;
  sf::Vector2f get_center(const sf::Sprite &sprite) const noexcept;
  float x(const sf::Sprite &sprite) const noexcept;
  float y(const sf::Sprite &sprite) const noexcept;
  virtual ~entity() = default;
};
