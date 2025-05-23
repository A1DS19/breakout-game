#pragma once

#include <memory>

#include "entity.hpp"

class brick : public entity {
  std::shared_ptr<sf::Texture> texture;

public:
  sf::Sprite sprite;
  brick(std::shared_ptr<sf::Texture> tex, float x, float y);
  void draw(sf::RenderWindow &window) override;
  void update() override;
};
