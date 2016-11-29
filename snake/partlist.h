#ifndef PARTLIST_H
#define PARTLIST_H

#include "position.h"

class PartList
{
	const int DEFAULT_SIZE = 8;
	const int DEFAULT_LENGTH = 2;
	Position* m_parts;
	int m_size;
	int m_nElements;
	int m_length;
	int m_ptr;
	void reallocate(int);
	void add(Position);
public:
	PartList();
	PartList(Position);
	PartList(int, int);
	~PartList();
	void upgrade();
	void update(Position);
	const Position& operator[](int index) const;
	int getSize(){return m_nElements;}
};

#endif
