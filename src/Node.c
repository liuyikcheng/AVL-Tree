#include "Node.h"
#include <stdio.h>
#include <stdlib.h>


Node *addNode(Node *root, Node *node){
  
}

Node *createNode(int num){
  Node *node = malloc(sizeof(Node));
  
  node->left = NULL;
  node->right = NULL;
  node->weight = 0;
  node->data = num;
  
  return node;
}