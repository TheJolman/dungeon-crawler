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
  void takeDamage();
  void heal();
  bool isAlive() const;
  int getHP() const;
  void moveTo(int x, int y);

private:
  int x, y;
  const char** figure;
  int hp;
  void drawFigure() const;
};

#endif // PLAYER_H
