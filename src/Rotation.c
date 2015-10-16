#include "Rotation.h"
#include "stdlib.h"

Node *rightRotation(Node *root){
  
  Node *temp1 = malloc(sizeof(Node));
  Node *temp2 = malloc(sizeof(Node));
  Node *temp3 = malloc(sizeof(Node));
  
  temp1 = root;
  temp2 = root->right;
  temp3 = root->right->left;

  temp2->left = temp1;
  temp1->right = temp3;
  
  root = temp2;
  
  return root;
}

Node *leftRotation(Node *root){
  
  
}