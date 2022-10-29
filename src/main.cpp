#include <ncurses.h>
#include <string>

int main(int argc, char** argv) 
{
  initscr();

  cbreak();
  noecho();

  WINDOW *status_win = newwin(3, (COLS - 1) / 3, 0, 0);
  box(status_win, 0, 0);

  WINDOW *quotes = newwin((LINES) / 2, (COLS) / 3, 3, 0);
  box(quotes, 0, 0);

  WINDOW *chart_win = newwin(2 * (LINES) / 3, 2 * (COLS) / 3, 0, (COLS) / 3);
  box(chart_win, 0, 0);

  WINDOW *console = newwin((LINES) / 3, 2 * (COLS) / 3, 2 * (LINES) / 3, (COLS) / 3);
  box(console, 0, 0);

  mvwprintw(quotes, 0, 1, "Quotes - Watchlist");
  mvwprintw(status_win, 0, 1, "Status");
  mvwprintw(chart_win, 0, 1, "Charts");
  mvwprintw(console, 0, 1, "Console");

  mvwprintw(status_win, 1, 1, "Establishing connection...");
  refresh();

  wmove(console, 1, 4);
  refresh();
  wrefresh(console);

  std::string cons_line ("$> ");
  cons_line.resize(2 * COLS / 3 - 2, ' ');
  int cons_line_length = 3;
  mvwprintw(console, 1, 1, "%s", cons_line.c_str());
  wmove(console, 1, 1 + cons_line_length);

  for (;;) {
    wrefresh(quotes);
    wrefresh(chart_win);
    wrefresh(status_win);
    wrefresh(console);

    int c = getch();
    if (c == 'q') break;
    if (c == KEY_BACKSPACE || c == 127) {
      if (cons_line_length > 3) {
        cons_line[cons_line_length - 1] = ' ';
        cons_line_length--;
      }
    }
    else {
      cons_line[cons_line_length] = c;
      cons_line_length++;
    }

    mvwprintw(console, 1, 1, "%s", cons_line.c_str());
    wmove(console, 1, 1 + cons_line_length);

    refresh();
  }

  endwin();
  return 0;
}
