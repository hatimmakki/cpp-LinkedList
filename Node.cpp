
#include "Node.h"

Node::Node(int data, std::shared_ptr<Node> next) :
   data(data),
   next(next)
{
}

Node::Node(const Node& other) :
   data(other.data),
   next(other.next)
{
}
