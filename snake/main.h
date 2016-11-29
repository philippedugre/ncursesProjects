#ifndef MAIN_H
#define MAIN_H

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "partlist.h"

void printChar(Position, char);

void initncurses();

int main();


#endif
