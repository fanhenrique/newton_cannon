#include <tuple>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <X11/Xlib.h>

// allegro imports
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

std::tuple<ALLEGRO_DISPLAY *, ALLEGRO_TIMER *, ALLEGRO_EVENT, ALLEGRO_EVENT_QUEUE *, ALLEGRO_TRANSFORM, ALLEGRO_TRANSFORM, ALLEGRO_FONT *> init();

void destroy(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_FONT *font);

ALLEGRO_EVENT_QUEUE *init_queue_event(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer);

std::vector<ALLEGRO_BITMAP *> *load_bitmap();