#pragma once

#include "ball.hpp"
#include "paddle.hpp"

bool is_interacting(const sf::FloatRect &e1, const sf::FloatRect &e2);
void handle_collision(ball &b, const paddle &p);
