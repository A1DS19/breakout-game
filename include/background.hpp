#pragma once

#include "entity.hpp"

class background : public entity {
  sf::Texture texture;
  sf::Sprite sprite;

public:
  background(float x, float y);
  void draw(sf::RenderWindow &window) override;
  void update() override;
};
