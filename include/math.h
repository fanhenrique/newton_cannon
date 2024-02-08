#include <math.h>

// my imports
#include "body.h"

double distance(Body *b1, Body *b2);

bool collision(Body *b1, Body *b2);

double gravitational_force(Body *b1, Body *b2);

std::pair<double, double> decompose_gravitational_force(Body *b1, Body *b2, double gravitational_force);

std::pair<double, double> decompose_acceleration(Body *b, double x_gravitatinal_force, double y_gravitatinal_force);