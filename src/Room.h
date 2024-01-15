#ifndef ROOM_H
#define ROOM_H

class Room {
public:
  Room(int width, int height);
  void display() const;
  bool isInside(int x, int y) const;

private:
  int width, height;
};

#endif // ROOM_H
