#include "unity.h"
#include "AvlRemove.h"
#include "Node.h"
#include "Rotation.h"
#include "CustomAssertion.h"
#include <stdlib.h>

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

void tearDown(void){}

/*
 *
 *  Given:
 *         60(0)        remove  100      60(-1)
 *       /   \     ===============>     /
 *     20(0) 100(0)                   20(0)
 * 
 *
 **/
void xtest_node_remove(void){
	setNode(0, &node60, &node20, &node100);
  
  Node *root = &node60;
  Node *removedNode;
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 100, &heightChange);
  
  TEST_ASSERT_NODE(-1, &node60, &node20, NULL);
  TEST_ASSERT_EQUAL_PTR(&node100, removedNode);
}

/*
 *
 *  Given:
 *         60(0)        remove  20      60(+1)
 *       /   \     ===============>       \
 *     20(0) 100(0)                     100(0)
 * 
 *
 **/
void xtest_node_remove2(void){
	setNode(0, &node60, &node20, &node100);
  
  Node *root = &node60;
  Node *removedNode;
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 20, &heightChange);
  
  TEST_ASSERT_NODE(1, &node60, NULL, &node100);
  TEST_ASSERT_EQUAL_PTR(&node20, removedNode);
}

/*
 *
 *  Given:
 *         80(+1)             remove 100             80(0)
 *       /   \           ===============>            /   \
 *     20(0) 110(-1)                              20(0) 110(0)
 *           /                                  
 *         100(0)                             
 *                                                                                     
 *
 **/
void xtest_node_remove3(void){
  setNode(1, &node80, &node20, &node110);
  setNode(-1, &node110, &node100, NULL);
  
  Node *root = &node80;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 100, &heightChange);
  
  TEST_ASSERT_NODE(0, &node80, &node20, &node110);
  TEST_ASSERT_NODE(0, &node110, NULL, NULL);
  TEST_ASSERT_EQUAL_PTR(&node100, removedNode);
}

/*
 *
 *  Given:
 *                80(-1)                                   80(-1) 
 *               /     \          remove 60               /     \
 *            40(0)  110(0)  =================>        40(-1)  110(0)       
 *           /   \                                    /  
 *        20(0) 60(0)                              20(0)
 *                                                    
 *                                  
 *
 **/
void xtest_node_remove4(void){
  setNode(-1, &node80, &node40, &node110);
  setNode(0, &node40, &node20, &node60);
  
  Node *root = &node80;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 60, &heightChange);
  
  TEST_ASSERT_NODE(-1, &node80, &node40, &node110);
  TEST_ASSERT_NODE(-1, &node40, &node20, NULL);
  TEST_ASSERT_EQUAL_PTR(&node60, removedNode);
}

/*
 *
 *  Given:
 *                80(+1)                                   80(+2)                                         110(0)
 *               /     \          remove 30               /     \            Left Rotation               /    \
 *            40(-1)  110(+1)  =================>       40(0)  110(+1)        ==========>             80(0)    150(-1)
 *           /        /  \                                      /   \                                /  \      /
 *         30(0)   90(0) 150(-1)                             90(0) 150(-1)                       40(0) 90(0) 120(0)
 *                      /                                           /
 *                   120(0)                                       120(0)
 *
 **/
void xtest_node_remove_and_left_rotate_the_tree(void){
  setNode(1, &node80, &node40, &node110);
  setNode(-1, &node40, &node30, NULL);
  setNode(1, &node110, &node90, &node150);
  setNode(-1, &node150, &node120, NULL);
  
  Node *root = &node80;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 30, &heightChange);
  
  TEST_ASSERT_NODE(0, &node110, &node80, &node150);
  TEST_ASSERT_NODE(-1, &node150, &node120, NULL);
  TEST_ASSERT_NODE(0, &node80, &node40, &node90);
  TEST_ASSERT_EQUAL_PTR(&node30, removedNode);
 }
 
 /*
 *
 *  Given:
 *         80(-1)             remove140               80(-2)        Right Rotation          40(0)
 *       /   \           ===============>            /   \            =============>     /     \
 *    40(-1) 110(+1)                            40(-1)  110(0)                       20(+1)  80(0)
 *    /   \      \                             /   \                                   \      /  \
 *  20(+1) 60(0)  140(0)                     20(+1) 60(0)                              30(0)  60(0) 110(0)
 *    \                                          \                                        
 *     30(0                                      30(0)                       
 *
 **/
void test_node_remove_and_right_rotate_the_tree(void){
  setNode(-1, &node80, &node40, &node110);
  setNode(-1, &node40, &node20, &node60);
  setNode(1, &node110, NULL, &node140);
  setNode(1, &node20, NULL, &node30);
  
  Node *root = &node80;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 30, &heightChange);
  
  TEST_ASSERT_NODE(0, &node40, &node20, &node80);
  TEST_ASSERT_NODE(1, &node20, NULL, &node30);
  TEST_ASSERT_NODE(0, &node80, &node60, &node110);
}