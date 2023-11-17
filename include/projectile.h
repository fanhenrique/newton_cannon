#include <queue>

// my imports
#include "body.h"

#ifndef PROJECTILE_H
#define PROJECTILE_H

class Projectile : public Body
{
public:
  std::queue<float> *trail;

  Projectile();

  Projectile(Point position, float radius, float mass, Point initial_velocity, RGBA color);
};
#endif