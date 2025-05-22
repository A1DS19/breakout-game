#pragma once

#include <SFML/Graphics.hpp>

class entity {
public:
  virtual void update() = 0;
  virtual void draw(sf::RenderWindow &window) = 0;
  virtual ~entity() = default;
};
