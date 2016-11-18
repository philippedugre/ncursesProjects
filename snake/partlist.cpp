#include "partlist.h"

PartList::PartList(Position p)
{
	m_nElements = 1;
	m_length = DEFAULT_LENGTH;
	m_ptr = 0;
	m_size= DEFAULT_SIZE ;
	m_parts = new Position[m_size];
	m_parts[m_ptr] = p;
}

PartList::PartList(int x, int y)
{
	Position p;
	p.x = x;
	p.y = y;
	m_nElements = 1;
	m_length = DEFAULT_LENGTH;
	m_ptr = 0;
	m_size= DEFAULT_SIZE ;
	m_parts = new Position[m_size];
	m_parts[m_ptr] = p;
}

PartList::~PartList()
{
	delete[] m_parts;
}

void PartList::add(Position p)
{
	m_nElements++;
	if(m_nElements > m_size)
		reallocate(m_size*2);
	m_parts[(m_ptr + m_nElements - 1) % m_size] = p;
}	

void PartList::reallocate(int size)
{
 	Position* newArray = new Position[size];
	for(int i = 0; i < m_nElements; i++)
		newArray[i] = m_parts[(m_ptr + i) % m_size];
	delete[] m_parts;
	m_parts = newArray;
	m_size = size;
	m_ptr = 0;
}

void PartList::upgrade()
{
	m_length++;	
}

void PartList::update(Position p)
{
	if(m_length > m_nElements)
		add(p);
	else
	{
		m_ptr++; m_ptr %= m_size;
		m_parts[(m_ptr + m_nElements - 1) % m_size] = p;
	}
}

const Position& PartList::operator[](int index) const
{
	return m_parts[(m_ptr + index) % m_size];
}

