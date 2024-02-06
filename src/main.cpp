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
#include "../include/utils.h"
#include "../include/body.h"
#include "../include/projectile.h"
#include "../include/draw.h"
#include "../include/math.h"
#include "../include/update.h"

using namespace std;

int main(int argc, char **argv)
{

  auto [display, timer, event, queue, camera, camera_informations, font] = init();

  ALLEGRO_BITMAP *atmo_sprite = al_load_bitmap("./images/atmo.png");
  ALLEGRO_BITMAP *earth_sprite = al_load_bitmap("./images/earth.png");
  ALLEGRO_BITMAP *space_sprite = al_load_bitmap("./images/space.png");

  bool redraw = true;
  bool start = false;

  float camera_position[2] = {0, 0};
  float x_camera_center = SCREEN_WIDTH / 2;
  float y_camera_center = SCREEN_HEIGHT / 2;

  cout << "window " << SCREEN_WIDTH << " " << SCREEN_HEIGHT << endl;

  Body *earth = new Body({SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f}, 270.0, 22000.0, {0.05, 0.6, 0.8, 1.0});

  // TODO spin earth
  // vector<ALLEGRO_BITMAP *> *earth_sprites = load_bitmap();

  vector<Projectile *> *projectiles = new vector<Projectile *>();
  // for (int i = 0; i < 1; i++)
  // {
  Projectile *p0 = new Projectile({earth->position.x, earth->position.y - earth->radius - 120}, 20.0, 1.0, {-7.8, 0.0}, {0.8, 0.8, 0.05, 1.0});
  Projectile *p1 = new Projectile({earth->position.x, earth->position.y - earth->radius - 120}, 20.0, 1.0, {7.8, 0.0}, {0.5, 0.8, 0.7, 1.0});
  Projectile *p2 = new Projectile({earth->position.x, earth->position.y - earth->radius - 120}, 20.0, 1.0, {-7.5, 0.0}, {0.5, 0.3, 0.5, 1.0});
  Projectile *p3 = new Projectile({earth->position.x, earth->position.y - earth->radius - 120}, 20.0, 1.0, {7.7, 0.0}, {0.8, 0.8, 0.05, 1.0});
  Projectile *p4 = new Projectile({earth->position.x, earth->position.y - earth->radius - 120}, 20.0, 1.0, {-8.0, 0.0}, {0.9, 0.8, 0.7, 1.0});
  Projectile *p5 = new Projectile({earth->position.x, earth->position.y - earth->radius - 120}, 20.0, 1.0, {7.4, 0.0}, {0.6, 0.2, 0.5, 1.0});
  projectiles->push_back(p0);
  projectiles->push_back(p1);
  projectiles->push_back(p2);
  projectiles->push_back(p3);
  projectiles->push_back(p4);
  projectiles->push_back(p5);
  // }
  // cout << earth_sprites->size() << endl;

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

    // for (vector<ALLEGRO_BITMAP *>::iterator it = earth_sprites->begin(); it != earth_sprites->end(); it++)
    // for (int i = 0; i < 10; i++)
    //   al_draw_scaled_bitmap(earth_sprites->at(i), 0, 0, al_get_bitmap_width(earth_sprites->at(i)), al_get_bitmap_height(earth_sprites->at(i)), (SCREEN_WIDTH - SCREEN_HEIGHT) / 2, 0, SCREEN_HEIGHT, SCREEN_HEIGHT, 0);

    if (redraw && al_is_event_queue_empty(queue))
    {

      if (start)
        update_projectiles(earth, projectiles);

      al_clear_to_color(al_map_rgb(255, 255, 255));
      al_draw_scaled_bitmap(space_sprite, 0, 0, al_get_bitmap_width(space_sprite), al_get_bitmap_height(space_sprite), 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

      camera_update(&camera, camera_position, x_camera_center, y_camera_center);

      draw_filled_body(earth);

      al_draw_scaled_bitmap(atmo_sprite, 0, 0, al_get_bitmap_width(atmo_sprite), al_get_bitmap_height(atmo_sprite), (SCREEN_WIDTH - SCREEN_HEIGHT) / 2, 0, SCREEN_HEIGHT, SCREEN_HEIGHT, 0);
      al_draw_scaled_bitmap(earth_sprite, 0, 0, al_get_bitmap_width(earth_sprite), al_get_bitmap_height(earth_sprite), (SCREEN_WIDTH - SCREEN_HEIGHT) / 2, 0, SCREEN_HEIGHT, SCREEN_HEIGHT, 0);

      draw_projectiles(projectiles);

      draw_axios(camera_position);

      // draw central position camera
      draw_camera_cross(x_camera_center, y_camera_center);

      // draw acceleration, velocity and position
      draw_body_informations(font, &camera_informations, p0);

      al_flip_display();

      redraw = false;
    }
  }

  // for (vector<ALLEGRO_BITMAP *>::iterator it = earth_sprites->begin(); it != earth_sprites->end(); it++)
  // {
  //   al_destroy_bitmap(*it);
  // }
  destroy(display, timer, queue, font);

  return 0;
}