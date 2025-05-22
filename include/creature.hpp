#pragma once

#include <SFML/Graphics.hpp>
#include <random>

class creature {
  inline static std::mt19937 mt{std::random_device{}()};
  inline static std::bernoulli_distribution bd{0.5f};

  float vx{4.0f};
  float vy{4.0f};
  sf::Vector2f velocity;

  sf::CircleShape circle;

public:
  creature(float x, float y);
  void draw(sf::RenderWindow &window);
  void update();
};
