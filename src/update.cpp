// my imports
#include "../include/update.h"

void update_projectile(Body *b1, Body *b2)
{
  float g_force = gravitational_force(b1, b2);

  auto [x_gravitational_force, y_gravitational_force] = decompose_gravitational_force(b1, b2, g_force);

  auto [x_acceleration, y_acceleration] = decompose_acceleration(b2, x_gravitational_force, y_gravitational_force);

  if (collision(b1, b2))
  {
    b2->acceleration.x = 0.0;
    b2->acceleration.y = 0.0;

    b2->velocity.x = 0.0;
    b2->velocity.y = 0.0;
  }
  else
  {
    b2->acceleration.x = x_acceleration;
    b2->acceleration.y = y_acceleration;

    b2->velocity.x += b2->acceleration.x;
    b2->velocity.y += b2->acceleration.y;

    b2->position.x += b2->velocity.x;
    b2->position.y += b2->velocity.y;
  }
}

void update_projectiles(Body *b1, std::vector<Projectile *> *projectiles)
{
  for (int i = 0; i < projectiles->size(); i++)
    update_projectile(b1, projectiles->at(i));
}