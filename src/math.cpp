// my imports
#include "../include/math.h"

double GRAVITATIONAL_CONSTANT = 0.9;

double distance(Body *b1, Body *b2)
{
  return sqrt(pow((b2->position.x - b1->position.x), 2) + pow((b2->position.y - b1->position.y), 2));
}

bool collision(Body *b1, Body *b2)
{
  return (b1->radius + b2->radius) >= distance(b1, b2);
}

double gravitational_force(Body *b1, Body *b2)
{
  return GRAVITATIONAL_CONSTANT * ((b1->mass * b2->mass) / (pow(distance(b1, b2), 2)));
}

std::pair<double, double> decompose_gravitational_force(Body *b1, Body *b2, double gravitational_force)
{
  double x_gravitatinal_force = gravitational_force * ((b1->position.x - b2->position.x) / distance(b1, b2));
  double y_gravitatinal_force = gravitational_force * ((b1->position.y - b2->position.y) / distance(b1, b2));

  return {x_gravitatinal_force, y_gravitatinal_force};
}

std::pair<double, double> decompose_acceleration(Body *b, double x_gravitatinal_force, double y_gravitatinal_force)
{
  double x_acceleration = x_gravitatinal_force / b->mass;
  double y_acceleration = y_gravitatinal_force / b->mass;

  return {x_acceleration, y_acceleration};
}