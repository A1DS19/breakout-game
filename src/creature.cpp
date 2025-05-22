#include "creature.hpp"

creature::creature(float x, float y) {
  velocity = {vx, vy};
  circle.setPosition({x, y});
  circle.setRadius(5.0f);
  circle.setFillColor(sf::Color::Red);
}
void creature::draw(sf::RenderWindow &window) { window.draw(circle); }
void creature::update() {
  vx = bd(mt) ? vx : -vx;
  vy = bd(mt) ? vy : -vy;

  circle.move({vx, vy});
}
