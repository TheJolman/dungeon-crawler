#include "Player.h"
#include <ncurses.h>

Player::Player(int startX, int startY) : x(startX), y(startY) {
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
