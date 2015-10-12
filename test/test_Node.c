#include "unity.h"
#include "Node.h"
#include "Rotation.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_nodes(void)
{
  int arr[] = {60, 30, 110, 20, 80, 150, 70, 90, 130, 100};
  Node *root ;
  root = createNode(60);
  
  
  root = nodeTree(arr, arrSize);
}
