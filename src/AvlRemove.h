#ifndef AvlRemove_H
#define AvlRemove_H

#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

Node *avlRemove(Node **rootPtr, int value, int *heightChange);

#endif // AvlRemove_H
