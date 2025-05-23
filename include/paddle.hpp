#pragma once

#include "moving_entity.hpp"

class paddle : public moving_entity {
  sf::Texture texture;

public:
  sf::Sprite sprite;
  paddle(float x, float y);
  void draw(sf::RenderWindow &window) override;
  void update() override;
};
