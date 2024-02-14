#include <iostream>
// my imports
#include "../include/utils.h"

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
int FONT_SIZE = 36;
float FPS = 60.0;

std::tuple<ALLEGRO_DISPLAY *, ALLEGRO_TIMER *, ALLEGRO_EVENT, ALLEGRO_EVENT_QUEUE *, ALLEGRO_TRANSFORM, ALLEGRO_TRANSFORM, ALLEGRO_FONT *> init()
{
  al_init();

  al_install_keyboard();
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

  return queue;
}

std::vector<ALLEGRO_BITMAP *> *load_bitmap()
{
  std::vector<ALLEGRO_BITMAP *> *sprites = new std::vector<ALLEGRO_BITMAP *>();

  for (int i = 1; i < 120; i++)
  {
    std::ostringstream path;
    path << "./earth_svg/" << std::setfill('0') << std::setw(4) << i << ".svg";
    // std::cout << path.str() << std::endl;
    ALLEGRO_BITMAP *earth = al_load_bitmap(path.str().c_str());
    sprites->push_back(earth);
  }

  return sprites;
}