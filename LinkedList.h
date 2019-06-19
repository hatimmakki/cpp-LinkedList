
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <memory>

class LinkedList {
   public:

      LinkedList();
      ~LinkedList();

      void clear();
      
      int get(const unsigned int i) const;
      int getRand() const;

      void add(int val);
      void prepend(int val);
      void append(int val);
      void print();
      bool contains(int i) const;

      void deleteFirst();
      void deleteLast();
      void removeByValue(int value);
      std::shared_ptr<Node> getLastNode();
      std::shared_ptr<Node> getSecondLastNode();
      std::shared_ptr<Node> getHead();      // for TESTING needs
      
      // Size
      int size() const;
      int getSize() const;
      void setSize(unsigned int newValue);
      void sizeUp();
      void sizeDown();
      void shuffle();
      void deleteAt(unsigned int i);
   private:
//      Node* head;
      std::shared_ptr<Node> head;
      int iSize;
};

#endif // LINKEDLIST_H
