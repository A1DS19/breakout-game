#include <stdlib.h>

#include <SFML/Graphics.hpp>

#include "SFML/Window/Keyboard.hpp"
#include "background.hpp"
#include "ball.hpp"
#include "constants.hpp"
#include "creature.hpp"

int main() {
  creature the_creature(constants::window_w / 2.0f, constants::window_h / 2.0f);
  ball the_ball;
  background the_background(0.0f, 0.0f);

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
    the_creature.update();
    the_ball.update();

    the_background.draw(game_window);
    the_creature.draw(game_window);
    the_ball.draw(game_window);

    game_window.display();
  }

  return EXIT_SUCCESS;
}
