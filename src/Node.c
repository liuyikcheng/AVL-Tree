#include "Node.h"
#include <stdio.h>
#include <stdlib.h>


Node *nodeTree(Node *root, Node *node){
  
  if ((root->data > node->data)&&(root->left == NULL))
    root->left = node;
  else if ((root->data < node->data)&&(root->right == NULL))
    root->right = node;
  else if ((root->data > node->data)&&(root->left != NULL))
    nodeTree(root->left, node);
  else if ((root->data < node->data)&&(root->right != NULL))
    nodeTree(root->right, node);
  
  return root;
}

// Node *addNode(Node *root, Node *node){
  // if(root->data > node->data)
    // root->left = node;
  // else
    // root->right = node;
  // return root;
// }

Node *createNode(int num){
  Node *node = malloc(sizeof(Node));
  
  node->left = NULL;
  node->right = NULL;
  node->weight = 0;
  node->data = num;
  
  return node;
}