// my imports
#include "include/math.h"

float GRAVITATIONAL_CONSTANT = 0.9;

float distance(Body *b1, Body *b2)
{
  return sqrt(pow((b2->x - b1->x), 2) + pow((b2->y - b1->y), 2));
}

bool collision(Body *b1, Body *b2)
{
  return (b1->radius + b2->radius) >= distance(b1, b2);
}

float gravitational_force(Body *b1, Body *b2)
{
  return GRAVITATIONAL_CONSTANT * ((b1->mass * b2->mass) / (pow(distance(b1, b2), 2)));
}

std::pair<float, float> decompose_gravitational_force(Body *b1, Body *b2, float gravitational_force)
{
  float x_gravitatinal_force = gravitational_force * ((b1->x - b2->x) / distance(b1, b2));
  float y_gravitatinal_force = gravitational_force * ((b1->y - b2->y) / distance(b1, b2));

  return {x_gravitatinal_force, y_gravitatinal_force};
}

std::pair<float, float> decompose_acceleration(Body *b, float x_gravitatinal_force, float y_gravitatinal_force)
{
  float x_acceleration = x_gravitatinal_force / b->mass;
  float y_acceleration = y_gravitatinal_force / b->mass;

  return {x_acceleration, y_acceleration};
}