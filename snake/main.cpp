#include <ncurses.h>
#include <unistd.h>

using namespace std;

int main()
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	
	int sizeY, sizeX;
	getmaxyx(stdscr, sizeY, sizeX);
	WINDOW * menu = newwin(sizeY/2, sizeX/2, sizeY/4 , sizeX/4);
	
	getmaxyx(menu, sizeY, sizeX);
	int x = 0, y = 0;
	while(y < sizeY)
	{
		while(x < sizeX)
		{
			wmove(menu, y, x);
			wrefresh(menu);
			usleep(1000);
			x++;
		}
		x=0;
		y++;
	}
	delwin(menu);
	
	getmaxyx(stdscr, sizeY, sizeX);
	x = sizeX / 2;
	y = sizeY / 2;
		
	move(y, x);
	refresh();

	int key;
	nodelay(stdscr, TRUE);

	bool playing = true;
	while(playing)
	{
		if((key = getch()) == ERR)
		{
		}
		else
		{
			switch(key)
			{
				case 0x1B:			//ESC key 
					playing = false;
					break;
				case KEY_UP:
					y--;
					break;
				case KEY_DOWN:
					y++;
					break;
				case KEY_LEFT:
					x--;
					break;
				case KEY_RIGHT:
					x++;
					break;
			}
			move(y,x);
			refresh();
		}
	}

	endwin();
	return 0;
}
