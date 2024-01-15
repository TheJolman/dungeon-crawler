#include "Room.h"
#include <ncurses.h>
#include <cstdlib>
#include <algorithm>

Room::Room(int w, int h) : width(w), height(h) {}

int Room::getWidth() const {
  return width;
}

int Room::getHeight() const {
  return height;
}

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

void Room::generateHazards() {
  hazards.clear();
  healthPickups.clear();

  // Randomly place hazards and hp
  for (int i = 1; i < height - 1; ++i) {
    for (int j = 1; j < width - 1; ++j) {
      if (rand() % 20 == 0) { // 5% chance for hazard
        hazards.emplace_back(j, i);
      } else if (rand() % 30 == 0) { // 3% chance for hp
        healthPickups.emplace_back(j, i);
      }
    }
  }
}

bool Room::isHazard(int x, int y) const {
  return std::find(hazards.begin(), hazards.end(), std::make_pair(x, y)) != hazards.end();
}

bool Room::isHealthPickup(int x, int y) const {
  return std::find(healthPickups.begin(), hazards.end(), std::make_pair(x, y)) != healthPickups.end();
}

