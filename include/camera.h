// my imports
#include "../include/utils.h"

// allegro imports
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

extern float CAMERA_SCALE;

void camera_update(ALLEGRO_TRANSFORM *camera, float *camera_position, float &x_camera_center, float &y_camera_center);

void calculate_camera_position(float *camera_position, float &x_camera_center, float &y_camera_center);

void camera_scale(ALLEGRO_EVENT *event);

void camera_scrolling(ALLEGRO_EVENT *event, float *x_camera_center, float *y_camera_center);