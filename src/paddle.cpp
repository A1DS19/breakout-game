#include "paddle.hpp"

#include "SFML/Window/Keyboard.hpp"
#include "constants.hpp"

paddle::paddle(float x, float y)
    : texture("../assets/paddle.png"), sprite(texture) {
  sprite.setPosition({x, y});
}
void paddle::draw(sf::RenderWindow &window) { window.draw(sprite); }
void paddle::update() {
  auto pos = sprite.getPosition();
  float paddle_width = sprite.getGlobalBounds().size.x;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    if (pos.x - 10.0f > 0) {
      sprite.setPosition({pos.x - 10.0f, pos.y});
    } else {
      sprite.setPosition({0.0f, pos.y});
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    if (pos.x + paddle_width + 10.0f < constants::window_w) {
      sprite.setPosition({pos.x + 10.0f, pos.y});
    } else {
      sprite.setPosition({constants::window_w - paddle_width, pos.y});
    }
  }
}
