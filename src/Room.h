#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <utility>

class Room {
public:
  Room(int width, int height);
  void display() const;
  bool isInside(int x, int y) const;
  void generateHazards();
  bool isHazard(int x, int y) const;
  bool isHealthPickup(int x, int y) const;
  int getHeight() const;
  int getWidth() const;

private:
  int width, height;
  std::vector<std::pair<int, int>> hazards;
  std::vector<std::pair<int, int>> healthPickups;
};

#endif // ROOM_H
