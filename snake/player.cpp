#include "player.h"
#include "partlist.h"

Player::Player(int x, int y):m_tail(x, y)
{
	m_position.x = x;
	m_position.y = y;
	m_dir = RIGHT;
	getmaxyx(stdscr, m_maxY, m_maxX);
}
Player::Player(int x, int y, int l):m_tail(x,y)
{
	m_position.x = x;
	m_position.y = y;
	m_dir = RIGHT;
	getmaxyx(stdscr, m_maxY, m_maxX);
}
Player::Player(Position pos):m_tail(pos)
{
	m_position = pos;
	m_dir = RIGHT;
	getmaxyx(stdscr, m_maxY, m_maxX);
}
Player::Player(Position pos, int l):m_tail(pos)
{
	m_position = pos;
	m_dir = RIGHT;
	getmaxyx(stdscr, m_maxY, m_maxX);
}

void Player::move()
{
	switch(m_dir)
	{
		case RIGHT:
			m_position.x++;
			if(m_position.x >= m_maxX)
			{
				die();
				m_position.x--;
			}
			break;
		case DOWN:
			m_position.y++;
			if(m_position.y >= m_maxX)
			{
				die();
				m_position.y--;
			}
			break;
		case LEFT:
			m_position.x--;
			if(m_position.x < 0)
			{
				die();
				m_position.x++;
			}
			break;
		case UP:
			m_position.y--;
			if(m_position.y < 0)
			{
				die();
				m_position.y++;
			}
			break;
	}
	for(int i = 0; i < m_tail.getSize();i++)
		if(m_tail[i].x == m_position.x && m_tail[i].y == m_position.y)
		{
			die();
			break;
		}
	m_tail.update(m_position);
}

void Player::setDirection(Direction dir)
{
	m_dir = dir;
}

void Player::die()
{
	m_isAlive = false;
}

const Position& Player::operator[](int index) const
{
	return m_tail[index];
}
