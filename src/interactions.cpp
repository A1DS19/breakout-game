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

// maybe add paddle if it was touched by ball then it can
// destroy
void handle_collision(ball &b, brick &br) {
  sf::FloatRect box_b = b.get_bounding_box(b.sprite);
  sf::FloatRect box_br = br.get_bounding_box(br.sprite);

  if (is_interacting(box_b, box_br)) {
    br.destroy();

    float left_overlap = b.right(b.sprite) - br.left(br.sprite);
    float right_overlap = br.right(br.sprite) - b.left(b.sprite);
    float top_overlap = b.bottom(b.sprite) - br.top(br.sprite);
    float bottom_overlap = br.bottom(br.sprite) - b.top(b.sprite);

    bool from_left = std::abs(left_overlap) < std::abs(right_overlap);
    bool from_top = std::abs(top_overlap) < std::abs(bottom_overlap);

    float min_x_overlap = from_left ? left_overlap : right_overlap;
    float min_y_overlap = from_top ? top_overlap : bottom_overlap;

    if (std::abs(min_x_overlap) < std::abs(min_y_overlap)) {
      if (from_left) {
        b.move_left();
      } else {
        b.move_right();
      }
    } else {
      if (from_top) {
        b.move_up();
      } else {
        b.move_down();
      }
    }
  }
}
