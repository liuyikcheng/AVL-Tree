#include "AvlRemove.h"



Node *avlRemove(Node **rootPtr, int value, int *heightChange){
  Node *removedNode;
  
  // if((*rootPtr)->right->data == 140){
    // printf("%d, ", (*rootPtr)->right->data);
    // printf("%d, ", (*rootPtr)->data);
    // printf("%d, ", value);
      // if (value == (*rootPtr)->right->data){
    // removedNode = (*rootPtr)->right;
    // (*rootPtr)->right = NULL;
    // (*rootPtr)->balanceFactor--;
    
    // if((*rootPtr)->balanceFactor == 0)
      // *heightChange = 1;
    // else
      // *heightChange = 0;
  // }
  // nodeRotation(*rootPtr);
    // return removedNode;
  // }
  if (((*rootPtr)->left != NULL)&&(value == (*rootPtr)->left->data)){
    removedNode = (*rootPtr)->left;
    (*rootPtr)->left = NULL;
    (*rootPtr)->balanceFactor++;
    
    if((*rootPtr)->balanceFactor == 0)
      *heightChange = 1;
    else
      *heightChange = 0;
  }
  else if (((*rootPtr)->right != NULL)&&(value == (*rootPtr)->right->data)){
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

    if(*heightChange)
      (*rootPtr)->balanceFactor--;
  }
  
  nodeRotation(*rootPtr);
  
  return removedNode;
}