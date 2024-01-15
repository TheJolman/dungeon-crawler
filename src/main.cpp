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
  while (player.isAlive() && (ch = getch()) != 'q') {
    clear();

    // display health bar
    mvprintw(31, 0, "HP: ");
    for (int i = 0; i < player.getHP(); ++i) {
      addch('@');
    }

    // Movement and collision logic
    int prevX = player.getX(), prevY = player.getY();
    switch (ch) {
      case 'w': player.moveUp(); break;
      case 's': player.moveDown(); break;
      case 'a': player.moveLeft(); break;
      case 'd': player.moveRight(); break;
    }

    // Check for room boundaries and doorways
    if (!room.isInside(player.getX(), player.getY())) {
      if (player.getY() == 0 || player.getY() == room.getHeight() - 1) { // Doorways
        room.generateHazards(); // Generate a new room
        player.moveTo(15, 10); // Reset player position
      } else {
        player.moveTo(prevX, prevY); // Revert movement
      }
    }

    // Check for hazards and health pickups
    if (room.isHazard(player.getX(), player.getY())) {
      player.takeDamage();
    } else if (room.isHealthPickup(player.getX(), player.getY())) {
      player.heal();
    }

    room.display();
    player.display();
    refresh();
  }

  if (!player.isAlive()) {
    mvprintw(room.getHeight() / 2, room.getWidth() / 2, "Game Over");
    refresh();
    getch();
  }

  endwin();
  return 0;
}
