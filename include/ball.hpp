#pragma once

#include <random>

#include "moving_entity.hpp"

class ball : moving_entity {
  sf::Texture texture;
  sf::Sprite sprite;
  inline static std::mt19937 mt{std::random_device{}()};

public:
  ball();
  void draw(sf::RenderWindow &window) override;
  void update() override;
};
