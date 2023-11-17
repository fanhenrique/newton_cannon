// my imports
#include "../include/projectile.h"

Projectile::Projectile() {}

Projectile::Projectile(Point position, float radius, float mass, Point initial_velocity, RGBA color) : Body(position, radius, mass, initial_velocity, color)
{
  // TODO implemet projectile trail
  //  this->trail = new std::queue<float>();
}