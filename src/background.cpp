#include "background.hpp"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

background::background(float x, float y)
    : texture("/home/dev/projects/breakout-game/assets/background.jpg"),
      sprite(texture) {
  sprite.setPosition({x, y});
}

void background::draw(sf::RenderWindow &window) { window.draw(sprite); }

void background::update() {}
