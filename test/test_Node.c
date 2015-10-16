#include "unity.h"
#include "Node.h"
#include "Rotation.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_nodes(void)
{
  int arr[] = {60, 30, 110, 20, 80, 150, 70, 90, 130, 100};
  Node *root , *node;
  root = createNode(60);
  
  node = createNode(30);
  root = nodeTree(root, node);
  node = createNode(110);
  root = nodeTree(root, node);
  node = createNode(20);
  root = nodeTree(root, node);
  node = createNode(80);
  root = nodeTree(root, node);
  node = createNode(150);
  root = nodeTree(root, node);
  node = createNode(70);
  root = nodeTree(root, node);
  node = createNode(90);
  root = nodeTree(root, node);
  node = createNode(130);
  root = nodeTree(root, node);
  node = createNode(100);
  root = nodeTree(root, node);
  
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

void test_rightRotation(void){
  Node *root , *node;
  root = createNode(60);
  
  node = createNode(30);
  root = nodeTree(root, node);
  node = createNode(110);
  root = nodeTree(root, node);
  node = createNode(20);
  root = nodeTree(root, node);
  node = createNode(80);
  root = nodeTree(root, node);
  node = createNode(150);
  root = nodeTree(root, node);
  node = createNode(70);
  root = nodeTree(root, node);
  node = createNode(90);
  root = nodeTree(root, node);
  node = createNode(130);
  root = nodeTree(root, node);
  node = createNode(100);
  root = nodeTree(root, node);
  
  root = rightRotation(root);
  
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