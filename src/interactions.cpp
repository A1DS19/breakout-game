#include "interactions.hpp"

bool is_interacting(const sf::FloatRect &e1, const sf::FloatRect &e2) {
  std::optional<sf::FloatRect> intersection = e1.findIntersection(e2);
  return intersection ? true : false;
}

void handle_collision(ball &b, const paddle &p) {
  sf::FloatRect box_b = b.get_bounding_box(b.sprite);
  sf::FloatRect box_p = p.get_bounding_box(p.sprite);

  if (is_interacting(box_b, box_p)) {
    b.move_up();

    if (b.x(b.sprite) < p.x(p.sprite)) {
      b.move_left();
    } else {
      b.move_right();
    }
  }
}

void handle_collision(ball &b, brick &br) {
  sf::FloatRect box_b = b.get_bounding_box(b.sprite);
  sf::FloatRect box_br = br.get_bounding_box(br.sprite);

  if (is_interacting(box_b, box_br)) {
    br.destroy();
  }
}
