#include <math.h>

// my imports
#include "body.h"

extern float GRAVITATIONAL_CONSTANT;

float distance(Body *b1, Body *b2);

bool collision(Body *b1, Body *b2);

float gravitational_force(Body *b1, Body *b2);

std::pair<float, float> decompose_gravitational_force(Body *b1, Body *b2, float gravitational_force);

std::pair<float, float> decompose_acceleration(Body *b, float x_gravitatinal_force, float y_gravitatinal_force);