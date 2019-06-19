
#include "Node.h"

Node::Node(Tile* tile, std::shared_ptr<Node> next) :
   tile(tile),
   next(next)
{
}

Node::Node(const Node& other) :
   tile(other.tile),
   next(other.next)
{
}
