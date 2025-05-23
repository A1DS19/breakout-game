#include "entity.hpp"

sf::FloatRect
entity::get_bounding_box(const sf::Sprite &sprite) const noexcept {
  return sprite.getGlobalBounds();
}
sf::Vector2f entity::get_center(const sf::Sprite &sprite) const noexcept {
  auto box = get_bounding_box(sprite);
  return box.getCenter();
}
float entity::x(const sf::Sprite &sprite) const noexcept {
  return sprite.getPosition().x;
}
float entity::y(const sf::Sprite &sprite) const noexcept {
  return sprite.getPosition().y;
}
float entity::left(const sf::Sprite &sprite) const noexcept {
  return x(sprite) - get_bounding_box(sprite).size.x / 2.0f;
}
float entity::right(const sf::Sprite &sprite) const noexcept {
  return x(sprite) + get_bounding_box(sprite).size.x / 2.0f;
}
float entity::top(const sf::Sprite &sprite) const noexcept {
  return y(sprite) - get_bounding_box(sprite).size.y / 2.0f;
}
float entity::bottom(const sf::Sprite &sprite) const noexcept {
  return y(sprite) + get_bounding_box(sprite).size.y / 2.0f;
}
