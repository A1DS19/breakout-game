#include "brick.hpp"

brick::brick(std::shared_ptr<sf::Texture> tex, float x, float y)
    : texture(tex), sprite(*tex) {
  auto lb = sprite.getLocalBounds();
  sprite.setOrigin(get_center(sprite));
  sprite.setPosition({x, y});
}
void brick::draw(sf::RenderWindow &window) { window.draw(sprite); }
void brick::update() {}
