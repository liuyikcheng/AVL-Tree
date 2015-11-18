#include "CustomAssertion.h"
#include <stdlib.h>


void customTestAssertNode(int balanceFactor, Node *root, Node *left, Node *right, int lineNo){
  
  if (root != NULL){
    if ((root->left) != left){
    
      if ((root->left) == NULL){
        CUSTOM_TEST_FAIL(lineNo, "Expected left of node %d = %d, but was NULL", root->data, left->data);
        }
      else if (left == NULL){
        CUSTOM_TEST_FAIL(lineNo, "Expected left of node %d = NULL, but was %d", root->data, root->left->data);
      } 
      else{
        CUSTOM_TEST_FAIL(lineNo, "Expected left of node %d = %d, but was %d", root->data, left->data, root->left->data);
        }
    }
  
    if ((root->right) != right){
    
      if ((root->right) == NULL){
        CUSTOM_TEST_FAIL(lineNo, "Expected right of node %d = %d, but was NULL", root->data, right->data);
      }
      else if (right == NULL){
        CUSTOM_TEST_FAIL(lineNo, "Expected right of node %d = NULL, but was %d", root->data, root->right->data);
      }
      else{
        CUSTOM_TEST_FAIL(lineNo, "Expected right of node %d = %d, but was %d", root->data, right->data, root->right->data);
      }
    }
  
    if ((root->balanceFactor) != balanceFactor)
      CUSTOM_TEST_FAIL(lineNo, "Expected balanceFactor of node %d = %d, but was %d", root->data, balanceFactor, root->balanceFactor);
  }
  else
    CUSTOM_TEST_FAIL(lineNo, "Received a NULL root.");
    
}