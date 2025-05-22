#include "creature.hpp"

#include "constants.hpp"

creature::creature(float x, float y) {
  velocity = {vx, vy};
  circle.setRadius(5.0f);
  circle.setOrigin({circle.getRadius(), circle.getRadius()});
  circle.setPosition({x, y});
  circle.setFillColor(sf::Color::Red);
}
void creature::draw(sf::RenderWindow &window) { window.draw(circle); }
void creature::update() {
  // Randomly flip direction
  vx = bd(mt) ? vx : -vx;
  vy = bd(mt) ? vy : -vy;

  // Move first
  circle.move({vx, vy});

  // Then get new position
  sf::Vector2f pos = circle.getPosition();
  float radius = circle.getRadius();

  float min_x = radius;
  float max_x = constants::window_w - radius;
  float min_y = radius;
  float max_y = constants::window_h - radius;

  // Clamp + bounce logic
  if (pos.x < min_x) {
    pos.x = min_x;
    vx = -vx;
  } else if (pos.x > max_x) {
    pos.x = max_x;
    vx = -vx;
  }

  if (pos.y < min_y) {
    pos.y = min_y;
    vy = -vy;
  } else if (pos.y > max_y) {
    pos.y = max_y;
    vy = -vy;
  }

  // Apply corrected position
  circle.setPosition(pos);
}
