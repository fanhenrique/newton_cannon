// my imports
#include "rgb.h"

#ifndef BODY_H
#define BODY_H
class Body
{
public:
  float x, y;
  float radius;
  float mass;
  RGB color;
  float vx = 0.0, vy = 0.0;
  float ax = 0.0, ay = 0.0;

  Body();

  Body(float x, float y, float radius, float mass, RGB color);

  Body(float x, float y, float radius, float mass, float ax, float ay, RGB color);
};
#endif