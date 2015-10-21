#include "CustomAssertion.h"
#include <stdlib.h>


void customTestAssertNode(int balanceFactor, Node *root, Node *left, Node *right, int lineNo){
  
  if((root->left) != left){
    if((root->left) == NULL){
      CUSTOM_TEST_FAIL(lineNo, "Expected right = %d, but was NULL", left->data);
      }
    else{
      CUSTOM_TEST_FAIL(lineNo, "Expected left = %d, but was %d", left->data, root->left->data);
      }
  }
  if((root->right) != right){
    if((root->right) == NULL){
      CUSTOM_TEST_FAIL(lineNo, "Expected right = %d, but was NULL", right->data);
    }
    else{
      CUSTOM_TEST_FAIL(lineNo, "Expected right = %d, but was %d", right->data, root->right->data);
    }
  }
  if((root->balanceFactor) != balanceFactor)
    CUSTOM_TEST_FAIL(lineNo, "Expected balanceFactor = %d, but was %d", balanceFactor, root->balanceFactor);
}