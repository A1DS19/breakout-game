#pragma once

#include "ball.hpp"
#include "entity.hpp"
#include "paddle.hpp"

bool is_interacting(const entity &e1, const entity &e2);
void handle_collision(ball &b, const paddle &p);
