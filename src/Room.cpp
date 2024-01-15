#include "Room.h"
#include <ncurses.h>

Room::Room(int w, int h) : width(w), height(h) {}

void Room::display() const {
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
        mvaddch(i, j, '#'); // Draw border
      } else {
      mvaddch(i, j, ' '); // Empty space
      }
    }
  }
}
bool Room::isInside(int x, int y) const {
// Check if the coordinates are within the room boundaries
  return x > 0 && x < width - 3 && y > 0 && y < height - 3;
}
