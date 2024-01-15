#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
  Player(int x, int y);
  ~Player();
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
  void display() const;
  int getX() const;
  int getY() const;

private:
  int x, y;
  const char** figure;
  void drawFigure() const;
};

#endif // PLAYER_H
