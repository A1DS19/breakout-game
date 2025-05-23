#pragma once

#include <random>

#include "moving_entity.hpp"

class ball : public moving_entity {
  sf::Texture texture;
  inline static std::mt19937 mt{std::random_device{}()};

public:
  sf::Sprite sprite;
  ball();
  void draw(sf::RenderWindow &window) override;
  void update() override;
  void move_up() noexcept;
  void move_left() noexcept;
  void move_right() noexcept;
};
