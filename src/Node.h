#ifndef Node_H
#define Node_H

typedef struct Node_t Node;

struct Node_t{
  Node *left;
  Node *right;
  int balanceFactor;
  int data;
};

void setNode(int balanceFactor, Node *root, Node *left, Node *right);
int avlAdd(Node **root, Node *newNode);
Node *nodeRotation(Node *root);

#endif // Node_H
