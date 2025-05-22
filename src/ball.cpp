#include "ball.hpp"

#include "constants.hpp"

ball::ball() : texture("../assets/ball.png"), sprite(texture) {
  std::uniform_int_distribution<int> dist(0.0f, constants::window_h);
  float rand_x = static_cast<float>(dist(mt));
  float rand_y = static_cast<float>(dist(mt));

  sprite.setPosition({rand_x, rand_y});
  velocity = {constants::ball_velocity, constants::ball_velocity};
}

void ball::draw(sf::RenderWindow &window) { window.draw(sprite); }

void ball::update() {
  sprite.move(velocity);

  if (x(sprite) < 0 || x(sprite) > constants::window_w) {
    velocity.x = -velocity.x;
  }

  if (y(sprite) < 0 || y(sprite) > constants::window_h) {
    velocity.y = -velocity.y;
  }
}
