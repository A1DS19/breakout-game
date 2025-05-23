#include "brick.hpp"

brick::brick(std::shared_ptr<sf::Texture> tex, float x, float y)
    : texture(tex), sprite(*tex) {
  auto lb = sprite.getLocalBounds();
  sprite.setOrigin(get_center(sprite));
  sprite.setPosition({x, y});
}
void brick::draw(sf::RenderWindow &window) { window.draw(sprite); }
void brick::update() {}
void brick::destroy() noexcept { destroyed = true; }
float brick::left() const noexcept {
  return x(sprite) - get_bounding_box(sprite).size.x / 2.0f;
}
float brick::right() const noexcept {
  return x(sprite) + get_bounding_box(sprite).size.x / 2.0f;
}
float brick::top() const noexcept {
  return y(sprite) - get_bounding_box(sprite).size.y / 2.0f;
}
float brick::bottom() const noexcept {
  return y(sprite) + get_bounding_box(sprite).size.y / 2.0f;
}
bool brick::is_destroyed() const noexcept { return destroyed; }
