#pragma once

#include <memory>

#include "entity.hpp"

class brick : public entity {
  std::shared_ptr<sf::Texture> texture;
  bool destroyed = false;

public:
  sf::Sprite sprite;
  brick(std::shared_ptr<sf::Texture> tex, float x, float y);
  void draw(sf::RenderWindow &window) override;
  void update() override;
  void destroy() noexcept;
  bool is_destroyed() const noexcept;
};
