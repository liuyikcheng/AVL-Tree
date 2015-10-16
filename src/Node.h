#ifndef Node_H
#define Node_H

typedef struct Node_t Node;

struct Node_t{
  Node *left;
  Node *right;
  int weight;
  int data;
};

Node *nodeTree(Node *root, Node *node);
Node *createNode(int num);
#endif // Node_H
