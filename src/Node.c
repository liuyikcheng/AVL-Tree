#include "Node.h"
#include "Rotation.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief   The function that link the node with the left and right child nodes 
 *          to create a Avl Tree
 *                              root
 *                             /   \
 *                           left  right
 *
 * @param   balanceFactor     contains the balance factor of the node
 *          root              contains the parent node
 *          left              contains the left child node
 *          right             contains the right child node
 * @retval  None
 */
void setNode(int balanceFactor, Node *root, Node *left, Node *right){
  root->balanceFactor = balanceFactor;
  root->left = left;
  root->right = right;
}

/**
 * @brief   The function that add a new node to the Avl Tree
 * @param   root              contains the address of the root pointer
 *          newNode           contains a new node that is going to be added to the tree
 * @retval  1                 There has height change in the tree
 *          0                 There has no height change in the tree
 *
 */
int avlAdd(Node **root, Node *newNode){
  int currentBalanceFactor = ((*root)->balanceFactor);
  int childBalanceFactor;
  
  if (((*root)->data > newNode->data)&&((*root)->left == NULL)){
    (*root)->left = newNode;
    ((*root)->balanceFactor)--;
  }
  else if (((*root)->data < newNode->data)&&((*root)->right == NULL)){
    (*root)->right = newNode;
    ((*root)->balanceFactor)++;
  }
  else if (((*root)->data > newNode->data)&&((*root)->left != NULL)){
    childBalanceFactor = avlAdd(&((*root)->left), newNode);
    if( childBalanceFactor)
      ((*root)->balanceFactor)--;
  }
  else if (((*root)->data < newNode->data)&&((*root)->right != NULL)){
    childBalanceFactor = avlAdd(&((*root)->right), newNode);
    if(childBalanceFactor)
      ((*root)->balanceFactor)++;
  }
  
  nodeRotation(*root);
  
  if(((*root)->balanceFactor != 0) && ((currentBalanceFactor == (*root)->balanceFactor + 1) || (currentBalanceFactor == (*root)->balanceFactor - 1)))
    return 1;
  else
    return 0;
}


Node *nodeRotation(Node *root){
    
  if (root->balanceFactor == 2){         
    
    if (root->right->balanceFactor == 1){      //left rotation
    
      if (root->right->right->balanceFactor != 0){
      root = leftRotation(root);
      root->balanceFactor--;
      root->left->balanceFactor = root->left->balanceFactor - 2;
      }
    }
    else if (root->right->balanceFactor == -1){  //right left rotation
      root = rightLeftRotation(root);
 
      switch(root->balanceFactor) {
        case -1:  root->balanceFactor = 0;
                  root->left->balanceFactor = 0;
                  root->right->balanceFactor = 1;
                  break;
        case  1:  root->balanceFactor = 0;
                  root->left->balanceFactor = -1;
                  root->right->balanceFactor = 0;
                  break;
        case  0:  root->balanceFactor = 0;
                  root->left->balanceFactor = 0;
                  root->right->balanceFactor = 0;
                  break;
      }
      
    }
  
  }
  else if (root->balanceFactor == -2){
    
    if (root->left->balanceFactor == -1){
      
       if (root->left->left->balanceFactor != 0){
      root = rightRotation(root);
      root->balanceFactor++;
      root->right->balanceFactor = root->right->balanceFactor + 2;
      }
    }
    else if (root->left->balanceFactor == 1){
      root = leftRightRotation(root);
      
      switch(root->balanceFactor) {
        case -1:  root->balanceFactor = 0;
                  root->left->balanceFactor = 0;
                  root->right->balanceFactor = 1;
                  break;
        case  1:  root->balanceFactor = 0;
                  root->left->balanceFactor = -1;
                  root->right->balanceFactor = 0;
                  break;
        case  0:  root->balanceFactor = 0;
                  root->left->balanceFactor = 0;
                  root->right->balanceFactor = 0;
                  break;
      }
    }
  }
  return root;
}
