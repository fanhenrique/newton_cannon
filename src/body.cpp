// my imports
#include "../include/body.h"
#include "../include/rgba.h"
#include "../include/point.h"

Body::Body() {}

Body::Body(Point position, float radius, float mass, RGBA color)
{
  this->position = position;
  this->radius = radius;
  this->mass = mass;
  this->color = color;
}

Body::Body(Point position, float radius, float mass, Point initial_velocity, RGBA color) : Body(position, radius, mass, color)
{
  this->velocity = initial_velocity;
}