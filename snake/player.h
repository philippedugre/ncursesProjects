#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include "position.h"
#include "direction.h"

class Player
{
	const int DEFAULT_LENGTH = 2;
	Position m_position;
	Direction m_dir;
	int m_length;
public:
	Player(int, int);
	Player(int,int,int);
	Player(Position);
	Player(Position, int);
	void move();
	void setDirection(Direction);
	Direction getDirection(){return m_dir;}
	Position getPosition(){return m_position;}
	int getLength(){return m_length;}
};


#endif
