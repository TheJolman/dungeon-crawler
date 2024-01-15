#include <ncurses.h>
#include "Player.h"
#include "Room.h"

int main() {
  initscr();
  noecho();
  curs_set(0);

  Room room(30, 20); // Create a room of size 30x20
  Player player(15, 10); // Place the player in the middle of the room

  int ch;
  while ((ch = getch()) != 'q') {
    clear();
    room.display(); // Display the room

    switch (ch) {
      case 'w': if (room.isInside(player.getX(), player.getY() - 1)) player.moveUp(); break;
      case 's': if (room.isInside(player.getX(), player.getY() + 1)) player.moveDown(); break;
      case 'a': if (room.isInside(player.getX() - 1, player.getY())) player.moveLeft(); break;
      case 'd': if (room.isInside(player.getX() + 1, player.getY())) player.moveRight(); break;
    }

    player.display(); // Display the player
    refresh();
  }

  endwin();
  return 0;
}
