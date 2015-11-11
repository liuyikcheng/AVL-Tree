#include "AvlRemove.h"



Node *avlRemove(Node **rootPtr, int value, int *heightChange){
  Node *removedNode;
  
  if (value == (*rootPtr)->left->data){
    removedNode = (*rootPtr)->left;
    (*rootPtr)->left = NULL;
    (*rootPtr)->balanceFactor++;
    
    if((*rootPtr)->balanceFactor == 0)
      *heightChange = 1;
    else
      *heightChange = 0;
  }
  else if (value == (*rootPtr)->right->data){
    removedNode = (*rootPtr)->right;
    (*rootPtr)->right = NULL;
    (*rootPtr)->balanceFactor--;
    
    if((*rootPtr)->balanceFactor == 0)
      *heightChange = 1;
    else
      *heightChange = 0;
  }
  // else if (value == (*rootPtr)->data){
    // removedNode = (*rootPtr);
    // **rootPtr = 0;
  // } 
  else if (value < (*rootPtr)->data){
      removedNode = avlRemove(&((*rootPtr)->left), value, heightChange);
      
      if(*heightChange)
      (*rootPtr)->balanceFactor++;
    }
  else if (value > (*rootPtr)->data){
    removedNode = avlRemove(&((*rootPtr)->right), value, heightChange);
    // printf("%d", (*rootPtr)->right->right->data);
    if(*heightChange)
      (*rootPtr)->balanceFactor--;
  }
  
  
  
  // nodeRotation(*rootPtr);
  
  return removedNode;
}