#include <iostream>
// my imports
#include "../include/utils.h"

// external
int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
float CAMERA_SCALE = 1.0;
int FONT_SIZE = 36;

// internal
float CAMERA_SCALE_JUMP = 0.1;
float CAMERA_DIRECTION_JUMP = 7.0;
float FPS = 60.0;

std::tuple<ALLEGRO_DISPLAY *, ALLEGRO_TIMER *, ALLEGRO_EVENT, ALLEGRO_EVENT_QUEUE *, ALLEGRO_TRANSFORM, ALLEGRO_TRANSFORM, ALLEGRO_FONT *> init()
{
  al_init();

  al_install_keyboard();
  al_install_mouse();
  al_init_primitives_addon();
  al_init_image_addon();
  al_init_font_addon();
  al_init_ttf_addon();

  ALLEGRO_EVENT event;
  ALLEGRO_TRANSFORM camera;
  ALLEGRO_TRANSFORM camera_informations;
  al_identity_transform(&camera_informations);

  // resolution screen
  /*
    TODO
    - If there is one more screen, get the default screen resolution
    - Use default screen to set width and height
  */
  // ################################
  // Display *d = XOpenDisplay(NULL);
  // Screen *s = DefaultScreenOfDisplay(d);
  // ################################

  ALLEGRO_DISPLAY *display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

  al_set_window_position(display, 200, 200);
  al_set_window_title(display, "Newton cannon");

  ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
  ALLEGRO_EVENT_QUEUE *queue = init_queue_event(display, timer);
  ALLEGRO_FONT *font = al_load_ttf_font("./font/gomarice_no_continue.ttf", FONT_SIZE, 0);

  return {display, timer, event, queue, camera, camera_informations, font};
}

void destroy(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_FONT *font)
{
  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);
  al_destroy_font(font);
}

ALLEGRO_EVENT_QUEUE *init_queue_event(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer)
{
  ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

  al_register_event_source(queue, al_get_display_event_source(display));
  al_register_event_source(queue, al_get_timer_event_source(timer));
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_mouse_event_source());

  return queue;
}

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
    *x_camera_center += CAMERA_DIRECTION_JUMP;
  if (event->keyboard.keycode == ALLEGRO_KEY_LEFT)
    *x_camera_center -= CAMERA_DIRECTION_JUMP;
  if (event->keyboard.keycode == ALLEGRO_KEY_UP)
    *y_camera_center -= CAMERA_DIRECTION_JUMP;
  if (event->keyboard.keycode == ALLEGRO_KEY_DOWN)
    *y_camera_center += CAMERA_DIRECTION_JUMP;
}
