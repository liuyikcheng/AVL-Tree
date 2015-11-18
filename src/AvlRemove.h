#ifndef AvlRemove_H
#define AvlRemove_H

#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

Node *avlRemove(Node **rootPtr, int value, int *heightChange);
Node *avlGetReplacer(Node **rootPtr, int *heightChange);

#endif // AvlRemove_H
