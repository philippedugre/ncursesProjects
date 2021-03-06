#include "main.h"

#define CURS_INVISIBLE 0
#define CURS_NORMAL 1
#define CURS_VISIBLE 2

using namespace std;

void printChar(Position p, char c)
{
	mvaddch(p.y, p.x, c);
}

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
	srand(time(NULL));

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
	curs_set(CURS_INVISIBLE);		

	Player p(pos);

	bool playing = true;
	while(playing && p.isAlive())
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
					if(p.getDirection() != DOWN)
						p.setDirection(UP);
					break;
				case KEY_DOWN:
					if(p.getDirection() != UP)
						p.setDirection(DOWN);
					break;
				case KEY_LEFT:
					if(p.getDirection() != RIGHT)
						p.setDirection(LEFT);
					break;
				case KEY_RIGHT:
					if(p.getDirection() != LEFT)
						p.setDirection(RIGHT);
					break;
			}
		}
		p.move();
		clear();
		for(int i=0; i < p.getLength(); i++)
			printChar(p[i], '#');
		printChar(p.getDot(), '@');

		refresh();
		usleep(100000);
	}
	
	clear();
	refresh();
	endwin();
	return 0;
}
