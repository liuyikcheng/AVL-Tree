#include "unity.h"
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

void tearDown(void)
{
}


/**
 *  Return:
 *
 *             60                                   
 *          /     \                                
 *        30       110                        
 *       /       /    \                  
 *     20      80      150             
 *            /  \     /              
 *         70    90  130             
 *                \                  
 *                 100                         
 *
 **/
void test_nodes(void)
{
  
  setNode(0, &node60, &node30, &node110);
  setNode(0, &node30, &node20, NULL);
  setNode(0, &node110, &node80, &node150);
  setNode(0, &node80, &node70, &node90);
  setNode(0, &node90, NULL, &node100);
  setNode(0, &node150, &node130, NULL);
  
  TEST_ASSERT_NODE(0, &node60, &node30, &node110);
  TEST_ASSERT_NODE(0, &node30, &node20, NULL);
  TEST_ASSERT_NODE(0, &node110, &node80, &node150);
  TEST_ASSERT_NODE(0, &node80, &node70, &node90);
  TEST_ASSERT_NODE(0, &node90, NULL, &node100);
  TEST_ASSERT_NODE(0, &node150, &node130, NULL);
  
}





/*
 *
 *  Given:
 *         60(0)        add  90           60(+1)
 *       /   \     ===============>     /   \
 *     20(0) 100(0)                   20(0) 100(-1)
 *                                         /
 *                                       90(0)
 *
 **/
void xtest_addNode(void){
  setNode(0, &node60, &node20, &node100);
  
  Node *root = &node60;
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node90);
  
  TEST_ASSERT_EQUAL(1, balanceFactor);
  TEST_ASSERT_NODE(1, &node60, &node20, &node100);
  TEST_ASSERT_NODE(-1, &node100, &node90, NULL);
  
}

/*
 *
 *  Given:
 *         80(+1)        add  90           80(+1)
 *       /   \     ===============>      /   \
 *     20(0) 110(+1)                   20(0) 110(0)
 *             \                            /   \
 *             130(0)                     90(0) 130(0)
 *
 **/
void xtest_addNode_2(void){
  setNode(1, &node80, &node20, &node110);
  setNode(1, &node110, NULL, &node130);
  
  Node *root = &node80;
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node90);
  
  TEST_ASSERT_EQUAL(0, balanceFactor);
  TEST_ASSERT_NODE(1, &node80, &node20, &node110);
  TEST_ASSERT_NODE(0, &node110, &node90, &node130);
  
}

/*
 *
 *  Given:
 *         80(+1)             add  90                  80(+2)
 *       /   \           ===============>            /   \
 *     20(0) 110(-1)                              20(0) 110(-2)
 *           /                                         /   
 *         100(0)                                    100(-1) 
 *                                                   /
 *                                                 90(0)
 *
 **/
void xtest_addNode_3(void){
  setNode(1, &node80, &node20, &node110);
  setNode(-1, &node110, &node100, NULL);
  
  Node *root = &node80;
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node90);
  
  TEST_ASSERT_EQUAL(1, balanceFactor);
  TEST_ASSERT_NODE(2, &node80, &node20, &node110);
  TEST_ASSERT_NODE(-2, &node110, &node100, NULL);
  TEST_ASSERT_NODE(-1, &node100, &node90, NULL);
  
}

/*
 *
 *  Given:
 *         80(-1)             add  30                  80(-1)
 *       /    \           ===============>            /   \
 *     20(-1) 110(0)                              20(0)   110(0)
 *    /                                           /  \          
 * 10(0)                                       10(0) 30(0)   
 *                                                   
 *                                                
 **/
void xtest_addNode_4(void){
  setNode(-1, &node80, &node20, &node110);
  setNode(-1, &node20, &node10, NULL);
  
  Node *root = &node80;
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node30);
  
  TEST_ASSERT_EQUAL(0, balanceFactor);
  TEST_ASSERT_NODE(-1, &node80, &node20, &node110);
  TEST_ASSERT_NODE(0, &node20, &node10, &node30);
  
}

/*
 *
 *  Given:
 *         80(-1)             add  30                80(-2)        Right Rotation          40(0)
 *       /   \           ===============>            /   \            =============>     /     \
 *     40(0) 110(0)                               40(-1)  110(0)                       20(+1)  80(0)
 *    /   \                                     /   \                                   \      /  \
 *  20(0) 60(0)                             20(+1) 60(0)                              30(0)  60(0) 110(0)
 *                                              \                                        
 *                                               30(0)                       
 *
 **/
void test_addNode_and_right_rotate1(void){
  setNode(-1, &node80, &node40, &node110);
  setNode(0, &node40, &node20, &node60);
  
  Node *root = &node80;
  
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node30);
  
  TEST_ASSERT_EQUAL(0, balanceFactor);
  TEST_ASSERT_NODE(0, &node40, &node20, &node80);
  TEST_ASSERT_NODE(1, &node20, NULL, &node30);
  TEST_ASSERT_NODE(0, &node80, &node60, &node110);
}

/*
 *
 *  Given:
 *         80(+1)             add  120                80(+2)        left Rotation          110(0)
 *       /   \           ===============>            /   \            =============>     /     \
 *     20(0) 110(0)                              20(0)  110(+1)                        80(0)   150(-1)
 *           /   \                                      /  \                         /   \       /
 *         90(0)  150(0)                             90(0) 150(-1)                20(0) 90(0)  120(0)
 *                                                           /                             
 *                                                          120(0)                       
 *
 **/
void test_addNode_and_left_rotate1(void){
  setNode(1, &node80, &node20, &node110);
  setNode(0, &node110, &node90, &node150);
  
  Node *root = &node80;
  
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node120);
  
  TEST_ASSERT_EQUAL(0, balanceFactor);
  TEST_ASSERT_NODE(0, &node80, &node20, &node90);
  TEST_ASSERT_NODE(0, &node110, &node80, &node150);
  TEST_ASSERT_NODE(-1, &node150, &node120, NULL);
}

/*
 *
 *  Given:
 *         60(+1)             add   150                60(+2)        left Rotation         110(0)
 *       /   \           ===============>            /   \            =============>     /        \
 *     20(-1) 110(0)                              20(-1) 110(+1)                        60(0)      130(+1)
 *    /       /   \                               /      /    \                         /   \       /    \
 *  10(0)   90(+1)  130(0)                      10(0)  90(+1)130(+1)               20(-1) 90(+1) 120(0) 140(+1)
 *          \       /  \                                 \      /   \                  /     \             \
 *         100(0)120(0)140(0)                        100(0) 120(0) 140(+1)          10(0)    100(0)        150(0)
 *                                                                  \
 *                                                                  150(0)    
 **/
void test_addNode_and_left_rotate2(void){
  setNode(1, &node60, &node20, &node110);
  setNode(-1, &node20, &node10, NULL);
  setNode(0, &node110, &node90, &node130);
  setNode(1, &node90, NULL, &node100);
  setNode(0, &node130, &node120, &node140);
  
  Node *root = &node60;
  
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node150);
  
  TEST_ASSERT_EQUAL(0, balanceFactor);
  TEST_ASSERT_NODE(0, &node110, &node60, &node130);
  TEST_ASSERT_NODE(0, &node60, &node20, &node90);
  TEST_ASSERT_NODE(1, &node90, NULL, &node100);
  TEST_ASSERT_NODE(1, &node130, &node120, &node140);
}

/*
 *
 *
 *
 *
 */
void test_addNode_and_right_rotation1(void){
  
}

/*
 *       60(+1)                                 60(+2)                                         80(0)
 *      /  \              Add  70             /  \            right left rotation             /   \
 *    40(0) 100(0)        ============>    40    100(-1)   ========================>        60(0) 100(1)
 *          /  \                                 /  \                                      /  \      \
 *        80(0) 130(0)                       80(-1) 130(0)                               40(0) 70(0)  130(0)
 *                                            /
 *                                         70(0)
 *
 */
void test_addNode_and_right_left_rotation1(void){
  setNode(1, &node60, &node40, &node100);
  setNode(0, &node100, &node80, &node130);
  
  Node *root = &node60;
  
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node70);
  
  TEST_ASSERT_EQUAL(0, balanceFactor);
  TEST_ASSERT_NODE(0, &node80, &node60, &node100);
  TEST_ASSERT_NODE(1, &node100, NULL, &node130);
  TEST_ASSERT_NODE(0, &node60, &node40, &node70);
}

/*
 *       60(+1)                                 60(+2)                                         80(0)
 *      /  \              Add  90             /  \            right left rotation             /   \
 *    40(0) 100(0)        ============>    40    100(-1)   ========================>        60(-1) 100(0)
 *          /  \                                 /  \                                      /       / \
 *        80(0) 130(0)                       80(+1) 130(0)                               40(0) 90(0)  130(0)
 *                                            \
 *                                            90(0)
 *
 */
void test_addNode_and_right_left_rotation2(void){
  setNode(1, &node60, &node40, &node100);
  setNode(0, &node100, &node80, &node130);
  
  Node *root = &node60;
  
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node90);
  
  TEST_ASSERT_EQUAL(0, balanceFactor);
  TEST_ASSERT_NODE(0, &node80, &node60, &node100);
  TEST_ASSERT_NODE(0, &node100, &node90, &node130);
  TEST_ASSERT_NODE(-1, &node60, &node40, NULL);
}

/*
 *       60(+1)                                 60(+2)                                         80(0)
 *         \              Add  80                \            right left rotation             /   \
 *          100(0)        ============>          100(-1)   ========================>        60(0) 100(0)
 *                                               /                                                        
 *                                           80(0)                                                   
 *                                            
 *           
 *
 */
void test_addNode_and_right_left_rotation3(void){
  setNode(1, &node60, NULL, &node100);
  
  Node *root = &node60;
  
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node80);
  
  TEST_ASSERT_EQUAL(0, balanceFactor);
  TEST_ASSERT_NODE(0, &node80, &node60, &node100);
  TEST_ASSERT_NODE(0, &node60, NULL, NULL);
  TEST_ASSERT_NODE(0, &node110, NULL, NULL);
}

/*
 *       60(-1)                                 60(-2)                                         50(0)
 *         /              Add  50               /             left right rotation             /   \
 *      40(0)            ==============>      40(+1)         ========================>      40(0)  60(0)
 *                                              \                                                         
 *                                              50(0)                                                 
 *                                            
 *           
 *
 */
void test_addNode_and_left_right_rotation1(void){
  setNode(-1, &node60, &node40, NULL);
  
  Node *root = &node60;
  
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node50);
  
  TEST_ASSERT_EQUAL(0, balanceFactor);
  TEST_ASSERT_NODE(0, &node50, &node40, &node60);
  TEST_ASSERT_NODE(0, &node60, NULL, NULL);
  TEST_ASSERT_NODE(0, &node40, NULL, NULL);
}

/*
 *       60(-1)                                 60(-2)                                         30(0)
 *         /  \           Add  40               /    \        left right rotation             /    \
 *      20(0)  80(0)     ==============>      20(+1)  80(0)  ========================>      20(-1) 60(0)
 *     /  \                                  /    \                                         /       /  \   
 *   10(0) 30(0)                            10(0) 30(+1)                                 10(0)   40(0) 80(0)
 *                                                 \
 *                                                 40(0)
 *
 */
void test_addNode_and_left_right_rotation2(void){
  setNode(-1, &node60, &node20, &node80);
  setNode(0, &node20, &node10, &node30);
  
  Node *root = &node60;
  
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node40);
  
  TEST_ASSERT_EQUAL(0, balanceFactor);
  TEST_ASSERT_NODE(0, &node30, &node20, &node60);
  TEST_ASSERT_NODE(-1, &node20, &node10, NULL);
  TEST_ASSERT_NODE(0, &node60, &node40, &node80);
}

/*
 *       60(-1)                                 60(-2)                                         40(0)
 *         /  \           Add  30               /    \        left right rotation             /    \
 *      20(0)  80(0)     ==============>      20(+1)  80(0)  ========================>      20(0)  60(+1)
 *     /  \                                  /    \                                         / \        \   
 *   10(0) 40(0)                            10(0) 40(-1)                                 10(0) 30(0)   80(0)
 *                                                /
 *                                               30(0)
 *
 */
void test_addNode_and_left_right_rotation3(void){
  setNode(-1, &node60, &node20, &node80);
  setNode(0, &node20, &node10, &node40);
  
  Node *root = &node60;
  
  int balanceFactor;
  
  balanceFactor = avlAdd(&root, &node30);
  
  TEST_ASSERT_EQUAL(0, balanceFactor);
  TEST_ASSERT_NODE(0, &node40, &node20, &node60);
  TEST_ASSERT_NODE(0, &node20, &node10, &node30);
  TEST_ASSERT_NODE(1, &node60, NULL, &node80);
}