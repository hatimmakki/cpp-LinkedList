
#ifndef WEEK06_NODE_H
#define WEEK06_NODE_H
#include "Tile.h"
#include <memory>

class Node {
public:

   Node(Tile* tile, std::shared_ptr<Node> next);
   Node(const Node& other);

   // THIS IS PUBLIC!
   // Question: Is this being public good or bad?
   Tile*   tile;
//   Node* next;
   std::shared_ptr<Node> next;
};

#endif // WEEK06_NODE_H
