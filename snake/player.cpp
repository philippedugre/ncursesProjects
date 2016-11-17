#include "player.h"


Player::Player(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
	m_length = DEFAULT_LENGTH;
	m_dir = RIGHT;
}
Player::Player(int x, int y, int l)
{
	m_position.x = x;
	m_position.y = y;
	m_length = l;
	m_dir = RIGHT;
}
Player::Player(Position pos)
{
	m_position = pos;
	m_length = DEFAULT_LENGTH;
	m_dir = RIGHT;
}
Player::Player(Position pos, int l)
{
	m_position = pos;
	m_length = l;
	m_dir = RIGHT;
}

void Player::move()
{
	switch(m_dir)
	{
		case RIGHT:
			m_position.x++;
			break;
		case DOWN:
			m_position.y++;
			break;
		case LEFT:
			m_position.x--;
			break;
		case UP:
			m_position.y--;
			break;
	}
}

void Player::setDirection(Direction dir)
{
	m_dir = dir;
}
