#include "Node.h"
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
    if((((*root)->left->balanceFactor) != 0) && childBalanceFactor != 0)
      ((*root)->balanceFactor)--;
  }
  else if (((*root)->data < newNode->data)&&((*root)->right != NULL)){
    childBalanceFactor = avlAdd(&((*root)->right), newNode);
    if((((*root)->right->balanceFactor) != 0) && childBalanceFactor !=0)
      ((*root)->balanceFactor)++;
  }
  
  if(currentBalanceFactor != ((*root)->balanceFactor))
    return 1;
  else
    return 0;
}