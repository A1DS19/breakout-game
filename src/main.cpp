#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <vector>

#include "SFML/Window/Keyboard.hpp"
#include "background.hpp"
#include "ball.hpp"
#include "brick.hpp"
#include "constants.hpp"
#include "interactions.hpp"
#include "paddle.hpp"

int main() {
  ball the_ball;
  background the_background(0.0f, 0.0f);
  paddle the_paddle(constants::window_w / 2.0f, constants::window_h - 20.0f);

  std::vector<brick> bricks;
  auto brickTexture = std::make_shared<sf::Texture>();
  if (!brickTexture->loadFromFile("../assets/brick.png")) {
    throw std::runtime_error("could not load brick texture");
  }

  for (int i = 0; i < constants::brick_columns; ++i) {
    for (int j = 0; j < constants::brick_rows; ++j) {
      float x = constants::brick_offset + (i + 1) * constants::brick_width;
      float y = (j + 1) * constants::brick_height;

      bricks.emplace_back(brickTexture, x, y);
    }
  }

  sf::RenderWindow game_window{
      sf::VideoMode({constants::window_w, constants::window_h}), "Breakout"};

  game_window.setFramerateLimit(constants::framerate);

  while (game_window.isOpen()) {
    while (const std::optional event = game_window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        game_window.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
      game_window.close();
      break;
    }

    game_window.clear(sf::Color::Black);

    the_background.update();
    the_ball.update();
    the_paddle.update();
    for (auto &brick : bricks) {
      brick.update();
    }

    handle_collision(the_ball, the_paddle);
    for (auto &brick : bricks) {
      handle_collision(the_ball, brick);
    }

    bricks.erase(
        std::remove_if(std::begin(bricks), std::end(bricks),
                       [](const brick &b) { return b.is_destroyed(); }),
        std::end(bricks));

    the_background.draw(game_window);
    the_ball.draw(game_window);
    the_paddle.draw(game_window);
    for (auto &brick : bricks) {
      brick.draw(game_window);
    }

    game_window.display();
  }

  return EXIT_SUCCESS;
}
