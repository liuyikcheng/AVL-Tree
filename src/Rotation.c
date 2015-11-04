#include "Rotation.h"
#include <stdio.h>
#include <stdlib.h>

Node *leftRotation(Node *root){
  
  if(root->right == NULL){
    printf("No right child!");
    return root;
  }
  
  Node *temp1;
  Node *temp2;
  Node *temp3;
  
  temp1 = root;
  temp2 = root->right;
  temp3 = root->right->left;
   
  temp2->left = temp1;
  temp1->right = temp3;
  
  root = temp2;
  
  return root;
}

Node *rightRotation(Node *root){
  
  if(root->left == NULL){
    printf("No left child!");
    return root;
  }
  
  Node *temp1;
  Node *temp2;
  Node *temp3;
  
  temp1 = root;
  temp2 = root->left;
  temp3 = root->left->right;
  
  temp2->right = temp1;
  temp1->left = temp3;
  
  root = temp2;
  
  return root;
}

Node *rightLeftRotation(Node *root){
  
  root->right = rightRotation(root->right);
  root = leftRotation(root);
  
  return root;
}

Node *leftRightRotation(Node *root){
  
  root->left = leftRotation(root->left);
  root = rightRotation(root);
  
  return root;
}
