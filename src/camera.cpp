// my imports
#include "../include/camera.h"

float CAMERA_SCALE_JUMP = 0.01;
float CAMERA_DIRECTION_JUMP = 5.5;
float CAMERA_SCALE = 1.0;

void camera_update(ALLEGRO_TRANSFORM *camera, float *camera_position, float &x_camera_center, float &y_camera_center)
{
  al_identity_transform(camera);
  al_scale_transform(camera, CAMERA_SCALE, CAMERA_SCALE);
  calculate_camera_position(camera_position, x_camera_center, y_camera_center);
  al_translate_transform(camera, -camera_position[0], -camera_position[1]);
  al_use_transform(camera);
}

void calculate_camera_position(float *camera_position, float &x_camera_center, float &y_camera_center)
{
  camera_position[0] = -(SCREEN_WIDTH / 2) + (x_camera_center * CAMERA_SCALE);
  camera_position[1] = -(SCREEN_HEIGHT / 2) + (y_camera_center * CAMERA_SCALE);
}

void camera_scale(ALLEGRO_EVENT *event)
{
  if (event->keyboard.keycode == ALLEGRO_KEY_Z)
    CAMERA_SCALE += CAMERA_SCALE_JUMP;
  if (event->keyboard.keycode == ALLEGRO_KEY_X)
    CAMERA_SCALE -= CAMERA_SCALE_JUMP;
  if (CAMERA_SCALE < CAMERA_SCALE_JUMP)
    CAMERA_SCALE = CAMERA_SCALE_JUMP;
}

void camera_scrolling(ALLEGRO_EVENT *event, float *x_camera_center, float *y_camera_center)
{
  if (event->keyboard.keycode == ALLEGRO_KEY_RIGHT)
    *x_camera_center += CAMERA_DIRECTION_JUMP / CAMERA_SCALE;
  if (event->keyboard.keycode == ALLEGRO_KEY_LEFT)
    *x_camera_center -= CAMERA_DIRECTION_JUMP / CAMERA_SCALE;
  if (event->keyboard.keycode == ALLEGRO_KEY_UP)
    *y_camera_center -= CAMERA_DIRECTION_JUMP / CAMERA_SCALE;
  if (event->keyboard.keycode == ALLEGRO_KEY_DOWN)
    *y_camera_center += CAMERA_DIRECTION_JUMP / CAMERA_SCALE;
}