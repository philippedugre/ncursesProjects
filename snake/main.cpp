#include <ncurses.h>
#include <unistd.h>
#include "player.h"
#include "main.h"

using namespace std;

void initncurses()
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
}

int main()
{
	initncurses();

	Position winSize;	
	getmaxyx(stdscr,winSize.y, winSize.x);
	WINDOW * menu = newwin(winSize.y/2, winSize.x/2, winSize.y/4 , winSize.x/4);
	
	getmaxyx(menu, winSize.y, winSize.x);
	
	Position pos;
	pos.x=0; pos.y=0;

	while(pos.y < winSize.y)
	{
		while(pos.x < winSize.x)
		{
			wmove(menu, pos.y, pos.x);
			wrefresh(menu);
			usleep(1000);
			pos.x++;
		}
		pos.x=0;
		pos.y++;
	}
	delwin(menu);
	
	getmaxyx(stdscr, winSize.y, winSize.x);
	pos.x = winSize.x / 2;
	pos.y = winSize.y / 2;
		
	move(pos.y, pos.x);
	refresh();

	int key;
	nodelay(stdscr, TRUE);

	Player p(pos);

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
					p.setDirection(UP);
					break;
				case KEY_DOWN:
					p.setDirection(DOWN);
					break;
				case KEY_LEFT:
					p.setDirection(LEFT);
					break;
				case KEY_RIGHT:
					p.setDirection(RIGHT);
					break;
			}
		}
		p.move();
		move(p.getPosition().y, p.getPosition().x);
		refresh();
		usleep(100000);
	}

	endwin();
	return 0;
}
