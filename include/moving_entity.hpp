#pragma once

#include <SFML/Graphics.hpp>

#include "entity.hpp"

class moving_entity : public entity {
protected:
  sf::Vector2f velocity;
};
