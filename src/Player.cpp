#include "Player.h"
#include <ncurses.h>

Player::Player(int startX, int startY) : x(startX), y(startY), hp(3) {
  // Create a simple figure for the player
  figure = new const char*[3];
  figure[0] = " O "; // Head
  figure[1] = "/|\\"; // Arms
  figure[2] = "/ \\"; // Legs
}

Player::~Player() {
  delete[] figure;
}

void Player::moveUp() { --y; }
void Player::moveDown() { ++y; }
void Player::moveLeft() { --x; }
void Player::moveRight() { ++x; }

void Player::moveTo(int x, int y) {
  move(x, y);
}

void Player::display() const {
  drawFigure();
}

int Player::getX() const {
  return x;
}

int Player::getY() const {
  return y;
}

void Player::drawFigure() const {
  for (int i = 0; i < 3; ++i) {
    mvprintw(y + i, x, "%s", figure[i]);
  }
}

void Player::takeDamage() {
  if (hp > 0) --hp;
}

void Player::heal() {
  if (hp < 3) ++hp;
}

int Player::getHP() const {
  return hp;
}

bool Player::isAlive() const {
  return hp > 0;
}

