// my imports
#include "include/body.h"

Body::Body() {}

Body::Body(float x, float y, float radius, float mass, RGB color)
{
  this->x = x;
  this->y = y;
  this->radius = radius;
  this->mass = mass;
  this->color = color;
}

Body::Body(float x, float y, float radius, float mass, float ax, float ay, RGB color) : Body(x, y, radius, mass, color)
{
  this->ax = ax;
  this->ay = ay;
}