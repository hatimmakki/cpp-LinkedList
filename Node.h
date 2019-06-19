
#ifndef WEEK06_NODE_H
#define WEEK06_NODE_H
#include <memory>

class Node {
public:

   Node(int data, std::shared_ptr<Node> next);
   Node(const Node& other);

   int data;
   std::shared_ptr<Node> next;
};

#endif // WEEK06_NODE_H
