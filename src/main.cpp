#include <ncurses.h>
using namespace std;

int main(int argc, char** argv) 
{
  initscr();
  cbreak();
  noecho();

  WINDOW *win = newwin((LINES - 1) / 2, (COLS - 1) / 3, 1, 1);
  
  for (;;) {
    refresh();
    box(win, 0, 0);
    mvwprintw(win, 0, 1, "Quotes");

    wrefresh(win);

    if (getch() == 'q') break;
  }

  endwin();
  return 0;
}
