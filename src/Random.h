#ifndef Random_H
#define Random_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define seedRandomGenerator()   srand(time(NULL))
#define getRandomNum()          (rand() | (ransd() << 16))

#endif // Random_H
