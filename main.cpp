#include <iostream>
#include <vector>
#include <math.h>
#include <string>

// allegro imports
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

// my imports
#include "include/utils.h"
#include "include/body.h"
#include "include/draw.h"
#include "include/math.h"
#include "include/update.h"

using namespace std;

int main(int argc, char **argv)
{

  auto [display, timer, event, queue, camera, camera_informations, font] = init();

  bool redraw = true;
  bool start = false;

  float camera_position[2] = {0, 0};
  float x_camera_center = SCREEN_WIDTH / 2;
  float y_camera_center = SCREEN_HEIGHT / 2;

  cout << "window " << SCREEN_WIDTH << " " << SCREEN_HEIGHT << endl;

  Body *earth = new Body(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 200.0, 22000.0, RGBA(0.05, 0.6, 0.8, 1.0));
  vector<Body *> *projectiles = new vector<Body *>();

  // for (int i = 0; i < 1; i++)
  // {
  Body *projectile = new Body(earth->x, earth->y - earth->radius - 20, 10.0, 1.0, 12.5, 0.0, RGBA(0.5, 0.05, 0.05, 1.0));
  // projectiles->push_back(projectile);
  // }

  al_start_timer(timer);
  while (1)
  {
    al_wait_for_event(queue, &event);

    if (event.type == ALLEGRO_EVENT_TIMER)
      redraw = true;
    else if ((event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
      break;

    if ((event.keyboard.keycode == ALLEGRO_KEY_SPACE))
      start = !start;

    // camera scrolling with KEY_UP, KEY_DOWN, KEY_RIGHT and KEY_LEFT
    camera_scrolling(&event, &x_camera_center, &y_camera_center);
    // camera zoom with KEY_Z, KEY_X
    camera_scale(&event);

    if (redraw && al_is_event_queue_empty(queue))
    {
      // TODO desenhar a vetor gravidade  no projetil
      if (start)
        update_projectile(earth, projectile);

      camera_update(&camera, camera_position, x_camera_center, y_camera_center);

      al_clear_to_color(al_map_rgb(80, 80, 80));

      draw_filled_body(earth);

      draw_filled_body(projectile); // draw_projectiles(projectiles);

      draw_force_vector(projectile, projectile->ax, projectile->ay);
      draw_axios(camera_position);

      // draw central position camera
      draw_camera_cross(x_camera_center, y_camera_center);

      // draw acceleration, velocity and position
      draw_body_informations(font, &camera_informations, projectile);

      al_flip_display();

      redraw = false;
    }
  }

  destroy(display, timer, queue, font);

  return 0;
}