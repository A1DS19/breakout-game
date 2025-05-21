#include <stdlib.h>

#include <SFML/Graphics.hpp>

#include "constants.hpp"

int main() {
  sf::RenderWindow game_window{
      sf::VideoMode({constants::window_w, constants::window_h}), "Breakout"};

  game_window.setFramerateLimit(constants::framerate);

  while (game_window.isOpen()) {
    while (const std::optional event = game_window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        game_window.close();
      }
    }

    game_window.clear(sf::Color::Black);
    game_window.display();
  }

  return EXIT_SUCCESS;
}
