// my imports
#include "include/update.h"

void update_projectile(Body *b1, Body *b2)
{
  float g_force = gravitational_force(b1, b2);

  auto [x_gravitational_force, y_gravitational_force] = decompose_gravitational_force(b1, b2, g_force);

  auto [x_acceleration, y_acceleration] = decompose_acceleration(b2, x_gravitational_force, y_gravitational_force);

  if (collision(b1, b2))
  {
    // b2->ax = 0.0;
    // b2->ay = 0.0;

    b2->vx = 0.0;
    b2->vy = 0.0;
  }
  else
  {
    b2->ax = x_acceleration;
    b2->ay = y_acceleration;

    b2->vx += b2->ax;
    b2->vy += b2->ay;

    b2->x += b2->vx;
    b2->y += b2->vy;
  }
}