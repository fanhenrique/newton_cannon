// my imports
#include "../include/draw.h"

float MULTIPLY_WITH_THE_VECTOR = 5000.0;

float CAMERA_CROSS_SIZE = 15.0;

void draw_text(ALLEGRO_FONT *font, float x, float y, const char *text)
{
  al_draw_text(font, al_map_rgba_f(0.f, 0.f, 0.f, 1.f), x + 2, y + 2, 0, text);
  al_draw_text(font, al_map_rgba_f(1.f, 1.f, 1.f, 1.f), x, y, 0, text);
}

void draw_filled_body(Body *b)
{
  al_draw_filled_circle(b->position.x, b->position.y, b->radius, al_map_rgba_f(b->color.r, b->color.g, b->color.b, b->color.a));
}

void draw_camera_cross(float x_camera_center, float y_camera_center)
{
  float cross_size = CAMERA_CROSS_SIZE / CAMERA_SCALE;
  al_draw_line(x_camera_center - cross_size, y_camera_center, x_camera_center + cross_size, y_camera_center, al_map_rgb(200, 0, 0), 2 / CAMERA_SCALE);
  al_draw_line(x_camera_center, y_camera_center - cross_size, x_camera_center, y_camera_center + cross_size, al_map_rgb(200, 0, 0), 2 / CAMERA_SCALE);
}

void draw_axios(float *camera_position)
{
  float radius_end_point_axios = 5 / CAMERA_SCALE;
  // draw end point on the axios in the screen
  al_draw_filled_circle(camera_position[0] / CAMERA_SCALE, SCREEN_HEIGHT / 2, radius_end_point_axios, al_map_rgb(0, 100, 100));
  al_draw_filled_circle((camera_position[0] + SCREEN_WIDTH) / CAMERA_SCALE, SCREEN_HEIGHT / 2, radius_end_point_axios, al_map_rgb(0, 100, 100));
  al_draw_filled_circle(SCREEN_WIDTH / 2, camera_position[1] / CAMERA_SCALE, radius_end_point_axios, al_map_rgb(0, 100, 100));
  al_draw_filled_circle(SCREEN_WIDTH / 2, (camera_position[1] + SCREEN_HEIGHT) / CAMERA_SCALE, radius_end_point_axios, al_map_rgb(0, 100, 100));

  // axios x
  al_draw_line(camera_position[0] / CAMERA_SCALE, SCREEN_HEIGHT / 2, (camera_position[0] + SCREEN_WIDTH) / CAMERA_SCALE, SCREEN_HEIGHT / 2, al_map_rgb(186, 186, 186), 1 / CAMERA_SCALE);
  // axios y
  al_draw_line(SCREEN_WIDTH / 2, camera_position[1] / CAMERA_SCALE, SCREEN_WIDTH / 2, (camera_position[1] + SCREEN_HEIGHT) / CAMERA_SCALE, al_map_rgb(186, 186, 186), 1 / CAMERA_SCALE);
}

void draw_projectiles(std::vector<Projectile *> *projectiles)
{
  for (int i = 0; i < projectiles->size(); i++)
  {
    draw_filled_body(projectiles->at(i));
    draw_force_vector(projectiles->at(i), projectiles->at(i)->acceleration.x, projectiles->at(i)->acceleration.y);
  }
}

void draw_force_vector(Body *b, float x_force_vector, float y_force_vector)
{
  al_draw_line(b->position.x, b->position.y, (b->position.x + x_force_vector * MULTIPLY_WITH_THE_VECTOR), (b->position.y + y_force_vector * MULTIPLY_WITH_THE_VECTOR), al_map_rgba_f(b->color.r, b->color.g, b->color.b, b->color.a), 2);
}

void draw_trail(Body *b)
{
  // TODO
  // al_draw_line(b->x, b->y, b->old_x, b->old_y, al_map_rgba_f(b->color.r, b->color.g, b->color.b, b->color.a), 3);
}

void draw_body_informations(ALLEGRO_FONT *font, ALLEGRO_TRANSFORM *camera_informations, Body *b)
{
  al_translate_transform(camera_informations, 0, 0);
  al_use_transform(camera_informations);

  std::stringstream acceleration_string;
  std::stringstream x_acceleration_string;
  std::stringstream y_acceleration_string;
  acceleration_string << "Acceleration";
  x_acceleration_string << "x " << b->acceleration.x;
  y_acceleration_string << "y " << b->acceleration.y;
  draw_text(font, 0, 0, acceleration_string.str().c_str());
  draw_text(font, 0, 40, x_acceleration_string.str().c_str());
  draw_text(font, 0, 80, y_acceleration_string.str().c_str());

  std::stringstream velocity_string;
  std::stringstream x_velocity_string;
  std::stringstream y_velocity_string;
  velocity_string << "Velocity";
  x_velocity_string << "x " << b->velocity.x;
  y_velocity_string << "y " << b->velocity.y;
  draw_text(font, 0, 120, velocity_string.str().c_str());
  draw_text(font, 0, 160, x_velocity_string.str().c_str());
  draw_text(font, 0, 200, y_velocity_string.str().c_str());

  std::stringstream position_string;
  std::stringstream x_position_string;
  std::stringstream y_position_string;
  position_string << "Position";
  x_position_string << "x " << b->position.x;
  y_position_string << "y " << b->position.y;
  draw_text(font, 0, 240, position_string.str().c_str());
  draw_text(font, 0, 280, x_position_string.str().c_str());
  draw_text(font, 0, 320, y_position_string.str().c_str());
}
