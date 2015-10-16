#include "unity.h"
#include "Node.h"
#include "Rotation.h"
#include <stdlib.h>


#define treeCreate    Node *root , *node; \
                      root = createNode(60);\
                      node = createNode(30);\
                      root = nodeTree(root, node);\
                      node = createNode(110);\
                      root = nodeTree(root, node);\
                      node = createNode(20);\
                      root = nodeTree(root, node);\
                      node = createNode(80);\
                      root = nodeTree(root, node);\
                      node = createNode(150);\
                      root = nodeTree(root, node);\
                      node = createNode(70);\
                      root = nodeTree(root, node);\
                      node = createNode(90);\
                      root = nodeTree(root, node);\
                      node = createNode(130);\
                      root = nodeTree(root, node);\
                      node = createNode(100);\
                      root = nodeTree(root, node);

void setUp(void)
{
}

void tearDown(void)
{
}

void test_nodes(void)
{
  int arr[] = {60, 30, 110, 20, 80, 150, 70, 90, 130, 100};
  
  treeCreate;
  
  TEST_ASSERT_EQUAL(60, root->data);
  TEST_ASSERT_EQUAL(30, root->left->data);
  TEST_ASSERT_EQUAL(110, root->right->data);
  TEST_ASSERT_EQUAL(20, root->left->left->data);
  TEST_ASSERT_EQUAL(80, root->right->left->data);
  TEST_ASSERT_EQUAL(150, root->right->right->data);
  TEST_ASSERT_EQUAL(70, root->right->left->left->data);
  TEST_ASSERT_EQUAL(90, root->right->left->right->data);
  TEST_ASSERT_EQUAL(130, root->right->right->left->data);
  TEST_ASSERT_EQUAL(100, root->right->left->right->right->data);
}

void test_leftRotation(void){
  
  treeCreate;
  
  root = leftRotation(root);
  
  TEST_ASSERT_EQUAL(110, root->data);
  TEST_ASSERT_EQUAL(60, root->left->data);
  TEST_ASSERT_EQUAL(150, root->right->data);
  TEST_ASSERT_EQUAL(30, root->left->left->data);
  TEST_ASSERT_EQUAL(80, root->left->right->data);
  TEST_ASSERT_EQUAL(130, root->right->left->data);
  TEST_ASSERT_EQUAL(20, root->left->left->left->data);
  TEST_ASSERT_EQUAL(70, root->left->right->left->data);
  TEST_ASSERT_EQUAL(90, root->left->right->right->data);
  TEST_ASSERT_EQUAL(100, root->left->right->right->right->data);
  
}

void test_rightRotation(void){
  
  treeCreate;
  
  root = rightRotation(root);
  
  TEST_ASSERT_EQUAL(30, root->data);
  TEST_ASSERT_EQUAL(20, root->left->data);
  TEST_ASSERT_EQUAL(60, root->right->data);
  TEST_ASSERT_EQUAL(NULL, root->right->left);
  TEST_ASSERT_EQUAL(110, root->right->right->data);
  TEST_ASSERT_EQUAL(150, root->right->right->right->data);
  TEST_ASSERT_EQUAL(130, root->right->right->right->left->data);
  TEST_ASSERT_EQUAL(80, root->right->right->left->data);
  TEST_ASSERT_EQUAL(90, root->right->right->left->right->data);
  TEST_ASSERT_EQUAL(70, root->right->right->left->left->data);
  TEST_ASSERT_EQUAL(100, root->right->right->left->right->right->data);
  
}

void test_rightLeftRotation(void){
  
  treeCreate;
  
  root = rightLeftRotation(root);
  
  TEST_ASSERT_EQUAL(80, root->data);
  TEST_ASSERT_EQUAL(60, root->left->data);
  TEST_ASSERT_EQUAL(110, root->right->data);
  TEST_ASSERT_EQUAL(30, root->left->left->data);
  TEST_ASSERT_EQUAL(70, root->left->right->data);
  TEST_ASSERT_EQUAL(20, root->left->left->left->data);
  TEST_ASSERT_EQUAL(90, root->right->left->data);
  TEST_ASSERT_EQUAL(100, root->right->left->right->data);
  TEST_ASSERT_EQUAL(150, root->right->right->data);
  TEST_ASSERT_EQUAL(130, root->right->right->left->data);
  
}

void test_leftRightRotation(void){
  
  treeCreate;
  node = createNode(50);// an additional node added to allow rotation
  root = nodeTree(root, node);
  
  root = leftRightRotation(root);
  
  TEST_ASSERT_EQUAL(50, root->data);
  TEST_ASSERT_EQUAL(30, root->left->data);
  TEST_ASSERT_EQUAL(60, root->right->data);
  TEST_ASSERT_EQUAL(20, root->left->left->data);
  TEST_ASSERT_EQUAL(110, root->right->right->data);
  TEST_ASSERT_EQUAL(80, root->right->right->left->data);
  TEST_ASSERT_EQUAL(150, root->right->right->right->data);
  TEST_ASSERT_EQUAL(130, root->right->right->right->left->data);
  TEST_ASSERT_EQUAL(70, root->right->right->left->left->data);
  TEST_ASSERT_EQUAL(90, root->right->right->left->right->data);
  TEST_ASSERT_EQUAL(100, root->right->right->left->right->right->data);
  
}