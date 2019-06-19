
#ifndef WEEK06_NODE_H
#define WEEK06_NODE_H
#include <memory>


template <typename T>
class Node {
public:
   
   
   Node(T data, std::shared_ptr<Node<T> > next) :
      data(data),
      next(next)
   {
   }
//   Node(const Node& other);
   Node(const Node<T>& other) :
      data(other.data),
      next(other.next)
   {
   }

   T data;
   std::shared_ptr< Node<T> > next;
};

#endif // WEEK06_NODE_H
