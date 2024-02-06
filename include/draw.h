
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

// allegro imports
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

// my imports
#include "body.h"
#include "projectile.h"
#include "utils.h"

void draw_text(ALLEGRO_FONT *font, float x, float y, const char *text);

void draw_filled_body(Body *b);

void draw_camera_cross(float x_camera_center, float y_camera_center);

void draw_axios(float *camera_position);

void draw_projectiles(std::vector<Projectile *> *projectiles);

void draw_force_vector(Body *b, float x_force_vector, float y_force_vector);

void draw_trail(Body *b);

void draw_body_informations(ALLEGRO_FONT *font, ALLEGRO_TRANSFORM *camera_informations, Body *b);