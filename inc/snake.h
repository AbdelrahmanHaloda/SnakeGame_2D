#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>
#include <memory>
#include "SDL.h"

class Snake {
 public:

  // Snake Constructor 
  Snake(int grid_width, int grid_height)
    : grid_width(grid_width),
      grid_height(grid_height),
      head_x(grid_width / 2),
      head_y(grid_height / 2) {}

  // Snake Destructor
  ~Snake()
  {
    // std::cout<<"Snake Destructor\n";
  }
  
  // Enum Class Represent Snake Move Directions 
  enum class Direction { kUp, kDown, kLeft, kRight };

  void Update();

  void Reset();

  void GrowBody();

  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:

  std::shared_ptr<Snake> m_SnakeObj;

  void UpdateHead();

  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;

};

#endif