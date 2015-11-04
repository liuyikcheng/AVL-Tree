#include "unity.h"
#include "Node.h"
#include "Rotation.h"
#include "CustomAssertion.h"

//Creating global variables
Node node10, node20, node30, node40, node50;
Node node60, node70, node80, node90, node100;
Node node110, node120, node130, node140, node150;

/*
 * Reset the global variable nodes
 *
 */
void resetNode(Node *node, int value){
  node->data = value;
  node->balanceFactor = 0;
  node->left = NULL;
  node->right = NULL;
}

void setUp(void){
  resetNode(&node10, 10);
  resetNode(&node20, 20);
  resetNode(&node30, 30);
  resetNode(&node40, 40);
  resetNode(&node50, 50);
  resetNode(&node60, 60);
  resetNode(&node70, 70);
  resetNode(&node80, 80);
  resetNode(&node90, 90);
  resetNode(&node100, 100);
  resetNode(&node110, 110);
  resetNode(&node120, 120);
  resetNode(&node130, 130);
  resetNode(&node140, 140);
  resetNode(&node150, 150);
}

void tearDown(void)
{
}

/**
 *  Given:                                 Return:
 *
 *             60                                       110
 *          /     \                                   /    \ 
 *        30       110       Left Rotation          60      150
 *       /       /    \         ========>         /   \     /
 *     20      80      150                      30    80  130
 *            /  \     /                      /      / \
 *         70    90  130                    20     70  90
 *                \                                     \
 *                 100                                  100
 *
 **/
void test_leftRotation(void){
  Node *root = &node60;
  
  setNode(0, &node60, &node30, &node110);
  setNode(0, &node30, &node20, NULL);
  setNode(0, &node110, &node80, &node150);
  setNode(0, &node80, &node70, &node90);
  setNode(0, &node90, NULL, &node100);
  setNode(0, &node150, &node130, NULL);
  
  root = leftRotation(root);
  
  TEST_ASSERT_EQUAL_PTR(root, &node110);
  TEST_ASSERT_NODE(0, &node110, &node60, &node150);
  TEST_ASSERT_NODE(0, &node150, &node130, NULL);
  TEST_ASSERT_NODE(0, &node60, &node30, &node80);
  TEST_ASSERT_NODE(0, &node30, &node20, NULL);
  TEST_ASSERT_NODE(0, &node80, &node70, &node90);
  TEST_ASSERT_NODE(0, &node90, NULL, &node100);
  
}

/**
 *  Given:                                 Return:
 *
 *             60                                       30
 *          /     \                                   /    \ 
 *        30       110       Right Rotation         20      60
 *       /       /    \         ========>                     \
 *     20      80      150                                     110
 *            /  \     /                                     /    \
 *         70    90  130                                   80      150   
 *                \                                       /  \     /
 *                 100                                  70    90  130
 *                                                             \   
 *                                                             100
 *
 **/
void test_rightRotation(void){
  Node *root = &node60;
  
  setNode(0, &node60, &node30, &node110);
  setNode(0, &node30, &node20, NULL);
  setNode(0, &node110, &node80, &node150);
  setNode(0, &node80, &node70, &node90);
  setNode(0, &node90, NULL, &node100);
  setNode(0, &node150, &node130, NULL);
  
  root = rightRotation(root);
  
  TEST_ASSERT_EQUAL_PTR(root, &node30);
  TEST_ASSERT_NODE(0, &node30, &node20, &node60);
  TEST_ASSERT_NODE(0, &node60, NULL, &node110);
  TEST_ASSERT_NODE(0, &node110, &node80, &node150);
  TEST_ASSERT_NODE(0, &node80, &node70, &node90);
  TEST_ASSERT_NODE(0, &node90, NULL, &node100);
  TEST_ASSERT_NODE(0, &node150, &node130, NULL);
  
}

/**
 *  Given:                                                     Return:
 *
 *             60                                                            80
 *          /     \                                                       /     \
 *        30       110           Right Left Rotation                    60        110
 *       /       /    \          =====================>               /   \     /    \ 
 *     20      80      150                                          30    70   90     150
 *            /  \     /                                           /            \     /
 *         70    90  130                                         20             100 130
 *                \                  
 *                 100                         
 *
 **/
void test_rightLeftRotation(void){
  Node *root = &node60;
  
  setNode(0, &node60, &node30, &node110);
  setNode(0, &node30, &node20, NULL);
  setNode(0, &node110, &node80, &node150);
  setNode(0, &node80, &node70, &node90);
  setNode(0, &node90, NULL, &node100);
  setNode(0, &node150, &node130, NULL);
  
  root = rightLeftRotation(root);
  
  TEST_ASSERT_EQUAL_PTR(root, &node80);
  TEST_ASSERT_NODE(0, &node80, &node60, &node110);
  TEST_ASSERT_NODE(0, &node60, &node30, &node70);
  TEST_ASSERT_NODE(0, &node110, &node90, &node150);
  TEST_ASSERT_NODE(0, &node30, &node20, NULL);
  TEST_ASSERT_NODE(0, &node90, NULL, &node100);
  TEST_ASSERT_NODE(0, &node150, &node130, NULL);
  
}

/**
 *  Given:                                                Return:
 *  
 *             60                                                             50                                  
 *          /     \                                                         /    \
 *        30       110                                                    30     60
 *       /  \    /    \           Left Right Rotation                   /          \
 *     20   50 80      150        =====================>              20           110
 *            /  \     /                                                          /   \ 
 *         70    90  130                                                       80      150
 *                \                                                           / \      /
 *                 100                                                      70  90   130
 *                                                                               \
 *                                                                               100
 *
 **/
void test_leftRightRotation(void){
  Node *root = &node60;
  
  setNode(0, &node60, &node30, &node110);
  setNode(0, &node30, &node20, &node50);
  setNode(0, &node110, &node80, &node150);
  setNode(0, &node80, &node70, &node90);
  setNode(0, &node90, NULL, &node100);
  setNode(0, &node150, &node130, NULL);
  
  root = leftRightRotation(root);
  
  TEST_ASSERT_EQUAL_PTR(root, &node50);
  TEST_ASSERT_NODE(0, &node50, &node30, &node60);
  TEST_ASSERT_NODE(0, &node30, &node20, NULL);
  TEST_ASSERT_NODE(0, &node60, NULL, &node110);
  TEST_ASSERT_NODE(0, &node110, &node80, &node150);
  TEST_ASSERT_NODE(0, &node80, &node70, &node90);
  TEST_ASSERT_NODE(0, &node150, &node130, NULL);
  TEST_ASSERT_NODE(0, &node90, NULL, &node100);
  
}
