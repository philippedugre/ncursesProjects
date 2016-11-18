#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include "position.h"
#include "direction.h"
#include "partlist.h"

class Player
{
	const int DEFAULT_LENGTH = 2;
	Position m_position;
	Direction m_dir;
	PartList m_tail;
	int m_length;
	int m_maxX; int m_maxY;
	bool m_isAlive = true;

public:
	Player(int, int);
	Player(int,int,int);
	Player(Position);
	Player(Position, int);
	void move();
	void setDirection(Direction);
	void die();
	bool isAlive(){return m_isAlive;}
	Direction getDirection(){return m_dir;}
	Position getPosition(){return m_position;}
	const Position& operator[](int index) const;
	int getLength(){return m_tail.getSize();}
};


#endif
