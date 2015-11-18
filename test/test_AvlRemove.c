#include "unity.h"
#include "AvlRemove.h"
#include "Node.h"
#include "Rotation.h"
#include "CustomAssertion.h"
#include <stdlib.h>
#include <stdio.h>

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
void test_node_remove(void){
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
void test_node_remove2(void){
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
void test_node_remove3(void){
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
void test_node_remove4(void){
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
 *                80(1)                                     80(1) 
 *               /     \          remove 150               /     \
 *            40(0)  110(0)  =================>        40(0)  110(-1)       
 *                    /   \                                    /  
 *                  120(0) 150(0)                             120(0)
 *                                                    
 *                                  
 *
 **/
void test_node_remove5(void){
  setNode(1, &node80, &node40, &node110);
  setNode(0, &node110, &node120, &node150);
  
  Node *root = &node80;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 150, &heightChange);
  
  TEST_ASSERT_NODE(1, &node80, &node40, &node110);
  TEST_ASSERT_NODE(-1, &node110, &node120, NULL);
  TEST_ASSERT_EQUAL_PTR(&node150, removedNode);
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
void test_node_remove_and_left_rotate_the_tree(void){
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
  
  removedNode = avlRemove(&root, 140, &heightChange);
  
  TEST_ASSERT_NODE(0, &node40, &node20, &node80);
  TEST_ASSERT_NODE(1, &node20, NULL, &node30);
  TEST_ASSERT_NODE(0, &node80, &node60, &node110);
}

/*
 *
 *  Given:
 *                80(1)                                    100(1) 
 *               /     \          remove 80               /     \
 *            40(0)  110(0)  =================>        40(0)  110(1)       
 *                    /   \                                      \  
 *                  100(0) 150(0)                                150(0)
 *                                                    
 *                                  
 *
 **/
void test_node_remove_root_node(void){
  setNode(1, &node80, &node40, &node110);
  setNode(0, &node110, &node100, &node150);
  
  Node *root = &node80;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 80, &heightChange);
  
  TEST_ASSERT_NODE(1, &node100, &node40, &node110);
  TEST_ASSERT_NODE(1, &node110, NULL, &node150);
  TEST_ASSERT_EQUAL_PTR(&node80, removedNode);
}

/*
 *
 *  Given:
 *                80(0)                                    110(-1) 
 *               /     \          remove 80               /
 *            40(0)  110(0)  =================>        40(0)  
 *                                                    
 *                                  
 *
 **/
void test_node_remove_root_node2(void){
  setNode(0, &node80, &node40, &node110);
  
  Node *root = &node80;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 80, &heightChange);
  
  TEST_ASSERT_NODE(-1, &node110, &node40, NULL);
  TEST_ASSERT_EQUAL_PTR(&node80, removedNode);
}

/*
 *
 *  Given:
 *                80(0)                                            
 *               /                remove 80                
 *            40(0)          =================>           40(0)
 *                                                    
 *                                  
 *
 **/
void test_node_remove_root_node3(void){
  setNode(-1, &node80, &node40, NULL);
  
  Node *root = &node80;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 80, &heightChange);
  
  TEST_ASSERT_NODE(0, &node40, NULL, NULL);
  TEST_ASSERT_EQUAL_PTR(&node80, removedNode);
}

/*
 *
 *  Given:
 *                80(1)                                       90(0) 
 *               /     \            remove 80                /     \
 *            40(-1)  110(-1)    =================>        40(-1)  110(0)       
 *            /        /   \                              /       /   \  
 *          20(0)   100(-1) 150(0)                     20(0)    100(0)150(0)
 *                  /                                  
 *                90(0)                  
 *
 **/
void test_node_remove_root_node4(void){
  setNode(1, &node80, &node40, &node110);
  setNode(-1, &node40, &node20, NULL);
  setNode(-1, &node110, &node100, &node150);
  setNode(-1, &node100, &node90, NULL);
  
  Node *root = &node80;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 80, &heightChange);
  
  TEST_ASSERT_NODE(0, &node90, &node40, &node110);
  TEST_ASSERT_NODE(-1, &node40, &node20, NULL);
  TEST_ASSERT_NODE(0, &node110, &node100, &node150);
  TEST_ASSERT_EQUAL_PTR(&node80, removedNode);
}

/*
 *
 *  Given:
 *                80(0)                                       110(-1) 
 *               /     \            remove 80                /     \
 *            40(-1)  110(1)    =================>        40(-1)  150(0)       
 *            /           \                              /       
 *          20(0)         150(0)                     20(0)
 *                                                     
 *                                       
 *
 **/
void test_node_remove_root_node5(void){
  setNode(0, &node80, &node40, &node110);
  setNode(-1, &node40, &node20, NULL);
  setNode(1, &node110, NULL, &node150);
  
  Node *root = &node80;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 80, &heightChange);
  
  TEST_ASSERT_NODE(-1, &node110, &node40, &node150);
  TEST_ASSERT_NODE(-1, &node40, &node20, NULL);
  TEST_ASSERT_EQUAL_PTR(&node80, removedNode);
}

/*
 *
 *  Given:
 *                80(0)                                       80(0) 
 *               /     \            remove 110                /     \
 *            40(-1)  110(0)    =================>        40(-1)  150(-1)       
 *            /        /   \                              /        /     
 *          20(0)   100(0) 150(0)                     20(0)    100(0)
 *                                                   
 *                       
 *
 **/
void test_node_remove_middle_node(void){
  setNode(0, &node80, &node40, &node110);
  setNode(-1, &node40, &node20, NULL);
  setNode(0, &node110, &node100, &node150);

  
  Node *root = &node80;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 110, &heightChange);
  
  TEST_ASSERT_NODE(0, &node80, &node40, &node150);
  TEST_ASSERT_NODE(-1, &node40, &node20, NULL);
  TEST_ASSERT_NODE(-1, &node150, &node100, NULL);
  TEST_ASSERT_EQUAL_PTR(&node110, removedNode);
}

/*
 *
 *  Given:
 *                60(1)                                          60(0) 
 *               /     \            remove 130                  /     \
 *            40(-1)  100(1)    =================>         40(-1)    100(0)       
 *            / \      /   \                               / \        /    \   
 *      20(-1) 50(0) 80(-1)130(1)                     20(-1) 50(0)  80(-1) 140(0)
 *         /         /      /   \                      /            /       /  \ 
 *      10(0)    70(0)   120(0) 150(-1)             10(0)         70(0) 120(0) 150(0)
 *                              /
 *                            140(0)
 *
 **/
void test_node_remove_middle_node2(void){
  setNode(1, &node60, &node40, &node100);
  setNode(-1, &node40, &node20, &node50);
  setNode(-1, &node20, &node10, NULL);
  setNode(1, &node100, &node80, &node130);
  setNode(-1, &node80, &node70, NULL);
  setNode(1, &node130, &node120, &node150);
  setNode(-1, &node150, &node140, NULL);

  
  Node *root = &node60;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 130, &heightChange);
  
  TEST_ASSERT_NODE(0, &node60, &node40, &node100);
  TEST_ASSERT_NODE(-1, &node40, &node20, &node50);
  TEST_ASSERT_NODE(-1, &node20, &node10, NULL);
  TEST_ASSERT_NODE(0, &node100, &node80, &node140);
  TEST_ASSERT_NODE(-1, &node80, &node70, NULL);
  TEST_ASSERT_NODE(0, &node140, &node120, &node150);
  TEST_ASSERT_EQUAL_PTR(&node130, removedNode);
}

/*
 *
 *  Given:
 *                60(1)                                          60(0) 
 *               /     \            remove 100                  /     \
 *            40(-1)  100(1)    =================>         40(-1)     110(0)       
 *            / \      /   \                               / \        /    \   
 *      20(-1) 50(0) 80(-1)130(-1)                     20(-1) 50(0)  80(-1) 130(0)
 *         /         /      /   \                      /            /       /  \ 
 *      10(0)    70(0)   110(1) 150(0)             10(0)         70(0) 120(0) 150(0)
 *                          \
 *                          120(0)
 *
 **/
void test_node_remove_middle_node3(void){
  setNode(1, &node60, &node40, &node100);
  setNode(-1, &node40, &node20, &node50);
  setNode(-1, &node20, &node10, NULL);
  setNode(1, &node100, &node80, &node130);
  setNode(-1, &node80, &node70, NULL);
  setNode(-1, &node130, &node110, &node150);
  setNode(1, &node110, NULL, &node120);

  
  Node *root = &node60;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 100, &heightChange);
  
  TEST_ASSERT_NODE(0, &node60, &node40, &node110);
  TEST_ASSERT_NODE(-1, &node40, &node20, &node50);
  TEST_ASSERT_NODE(-1, &node20, &node10, NULL);
  TEST_ASSERT_NODE(0, &node110, &node80, &node130);
  TEST_ASSERT_NODE(-1, &node80, &node70, NULL);
  TEST_ASSERT_NODE(0, &node130, &node120, &node150);
  TEST_ASSERT_EQUAL_PTR(&node100, removedNode);
}

/*
 *
 *  Given:
 *                60(0)                                          60(0) 
 *               /     \            remove  80                  /     \
 *            40(-1)  100(0)    =================>         40(-1)     100(1)       
 *            / \      /   \                               / \        /    \   
 *      20(-1) 50(0) 80(-1)130(0)                     20(-1) 50(0) 70(0) 130(0)
 *         /         /      /   \                      /                  /  \ 
 *      10(0)    70(0)   110(0) 150(0)             10(0)              110(0) 150(0)
 *
 *
 *
 **/
void test_node_remove_middle_node4(void){
  setNode(0, &node60, &node40, &node100);
  setNode(-1, &node40, &node20, &node50);
  setNode(-1, &node20, &node10, NULL);
  setNode(0, &node100, &node80, &node130);
  setNode(-1, &node80, &node70, NULL);
  setNode(0, &node130, &node110, &node150);

  
  Node *root = &node60;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 80, &heightChange);
  
  TEST_ASSERT_NODE(0, &node60, &node40, &node100);
  TEST_ASSERT_NODE(-1, &node40, &node20, &node50);
  TEST_ASSERT_NODE(-1, &node20, &node10, NULL);
  TEST_ASSERT_NODE(1, &node100, &node70, &node130);
  TEST_ASSERT_NODE(0, &node130, &node110, &node150);
  TEST_ASSERT_EQUAL_PTR(&node80, removedNode);
}

/*
 *
 *  Given:
 *                60(0)                                          60(0) 
 *               /     \            remove  30                  /     \
 *            30(0)  100(1)    =================>         40(-1)     100(1) 
 *            / \      /   \                               / \        /    \   
 *      20(-1) 40(1) 80(0) 130(0)                     20(-1) 50(0) 80(0) 130(0)
 *         /     \         /   \                      /                  /  \ 
 *      10(0)    50(0)   110(0) 150(0)             10(0)              110(0) 150(0)
 *
 *
 *
 **/
void test_node_remove_middle_node5(void){
  setNode(0, &node60, &node30, &node100);
  setNode(0, &node30, &node20, &node40);
  setNode(-1, &node20, &node10, NULL);
  setNode(1, &node40, NULL, &node50);
  setNode(1, &node100, &node80, &node130);
  setNode(0, &node80, NULL, NULL);
  setNode(0, &node130, &node110, &node150);

  
  Node *root = &node60;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 30, &heightChange);
  
  TEST_ASSERT_NODE(0, &node60, &node40, &node100);
  TEST_ASSERT_NODE(-1, &node40, &node20, &node50);
  TEST_ASSERT_NODE(-1, &node20, &node10, NULL);
  TEST_ASSERT_NODE(1, &node100, &node80, &node130);
  TEST_ASSERT_NODE(0, &node130, &node110, &node150);
  TEST_ASSERT_EQUAL_PTR(&node30, removedNode);
}

/*
 *
 *  Given:
 *                60(1)                                          60(1)                                            60
 *               /     \            remove 80                   /     \              left rotate on 100          /   \
 *            40(-1)  100(1)    =================>         40(-1)     100(2)        ====================>     40      130
 *            / \      /   \                               / \        /    \                                /  \      /  \
 *      20(-1) 50(0) 80(-1)130(1)                     20(-1) 50(0)  70(0) 130(1)                          20   50   100   140
 *         /         /      /   \                      /                    /  \                          /        /  \     \
 *      10(0)    70(0)   110(0) 140(1)             10(0)               110(0) 140(1)                     10      70   110   150
 *                                \                                             \
 *                               150(0)                                        150(0)                                          
 *
 **/
void xtest_node_remove_middle_node_with_rotation(void){
  setNode(1, &node60, &node40, &node100);
  setNode(-1, &node40, &node20, &node50);
  setNode(-1, &node20, &node10, NULL);
  setNode(1, &node100, &node80, &node130);
  setNode(-1, &node80, &node70, NULL);
  setNode(-1, &node130, &node110, &node150);
  setNode(1, &node110, NULL, &node120);

  
  Node *root = &node60;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 100, &heightChange);
  
  TEST_ASSERT_NODE(0, &node60, &node40, &node110);
  TEST_ASSERT_NODE(-1, &node40, &node20, &node50);
  TEST_ASSERT_NODE(-1, &node20, &node10, NULL);
  TEST_ASSERT_NODE(0, &node110, &node80, &node130);
  TEST_ASSERT_NODE(-1, &node80, &node70, NULL);
  TEST_ASSERT_NODE(0, &node130, &node120, &node150);
  TEST_ASSERT_EQUAL_PTR(&node100, removedNode);
}
 
/*
 *
 *  Given:
 *                                                          
 *                            remove 40                
 *            40(0)      =================>       NULL
 *                                                    
 *                                  
 *
 **/
void xtest_node_remove_root(void){
  setNode(-1, &node40, NULL, NULL);
  
  Node *root = &node40;
  Node *removedNode;
  
  int heightChange = 0;
  
  removedNode = avlRemove(&root, 40, &heightChange);
  

  TEST_ASSERT_EQUAL_PTR(&node40, removedNode);
  
}

