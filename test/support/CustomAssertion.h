#ifndef CustomAssertion_H
#define CustomAssertion_H

#include "unity.h"
#include "Node.h"

#define CUSTOM_TEST_FAIL(lineNo, msg, ...)                                        \
                {                                                                 \
                char buffer[256];                                                 \
                sprintf(buffer, msg, ## __VA_ARGS__);                             \
                UNITY_TEST_FAIL(lineNo, buffer);                                  \
                }
                
                
#define TEST_ASSERT_NODE(balanceFactor, root, left, right)       \
                 customTestAssertNode(balanceFactor, root, left, right, __LINE__);
                 
void customTestAssertNode(int balanceFactor, Node *root, Node *left, Node *right, int lineNo);

#endif // CustomAssertion_H
