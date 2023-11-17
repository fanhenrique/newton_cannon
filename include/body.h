// my imports
#include "rgba.h"
#include "point.h"

#ifndef BODY_H
#define BODY_H
class Body
{
public:
  Point position;
  float radius;
  float mass;
  RGBA color;
  Point velocity;     // float vx = 0.0, vy = 0.0;
  Point acceleration; // float ax = 0.0, ay = 0.0;

  Body();

  Body(Point position, float radius, float mass, RGBA color);

  Body(Point position, float radius, float mass, Point initial_velocity, RGBA color);
};
#endif