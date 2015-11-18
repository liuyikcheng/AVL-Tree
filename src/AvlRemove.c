#include "AvlRemove.h"



Node *avlRemove(Node **rootPtr, int value, int *heightChange){
  Node *removedNode = NULL;
  Node *replaceNode = NULL;
 
  if (value == (*rootPtr)->data){  
      // printf("%d", (*rootPtr)->data);
    
    if ((*rootPtr)->right != NULL){
      replaceNode = avlGetReplacer(&((*rootPtr)->right), heightChange);
      replaceNode->right = (*rootPtr)->right;
      replaceNode->left = (*rootPtr)->left;

      if (*heightChange == 1)
        replaceNode->balanceFactor = --(*rootPtr)->balanceFactor;
      else
        replaceNode->balanceFactor = (*rootPtr)->balanceFactor;
      
      if((*rootPtr)->balanceFactor == 0)
        *heightChange = 1;
      else
        *heightChange = 0;

    }
    else if ((*rootPtr)->left != NULL){
      replaceNode = (*rootPtr)->left;
      *heightChange = 1;
    }
    else {
      replaceNode = NULL;
      *heightChange = 1;
    }
    
    removedNode = (*rootPtr);
    (*rootPtr) = replaceNode;
    removedNode->right = removedNode->left = NULL;
    
  } 
  else if (value < (*rootPtr)->data){
    
    if((*rootPtr)->left != NULL)
      removedNode = avlRemove(&((*rootPtr)->left), value, heightChange);
      
    if (*heightChange){
      (*rootPtr)->balanceFactor++;
      
      if((*rootPtr)->balanceFactor == 0)
        *heightChange = 1;
      else
        *heightChange = 0;
    }
  }
  else if (value > (*rootPtr)->data){
    
    if((*rootPtr)->right != NULL)
      removedNode = avlRemove(&((*rootPtr)->right), value, heightChange);
    
    if (*heightChange){
      (*rootPtr)->balanceFactor--;
      
      if((*rootPtr)->balanceFactor == 0)
        *heightChange = 1;
      else
        *heightChange = 0;
    }
  }
  
  
  if ((*rootPtr) != NULL){
    nodeRotation(*rootPtr);
    
  }
  
  return removedNode;
}



/**
 *
 *
 *
 *
 */
Node *avlGetReplacer(Node **rootPtr, int *heightChange){
  Node *replaceNode;
  
  if ((*rootPtr)->left != NULL){
    replaceNode = avlGetReplacer(&((*rootPtr)->left), heightChange);
    
    if(*heightChange){
      (*rootPtr)->balanceFactor++;
      
      if((*rootPtr)->balanceFactor != 0)
        *heightChange = 0;
      else
        *heightChange = 1;
    }
    
      
  }
  else {
    replaceNode = (*rootPtr);
    *heightChange = 1;
    // printf("%d", (*rootPtr)->data);
    (*rootPtr) = (*rootPtr)->right;
  }
  
  
  return replaceNode;
}