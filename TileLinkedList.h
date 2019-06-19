
#ifndef WEEK06_LINKEDLIST_H
#define WEEK06_LINKEDLIST_H

#include "Node.h"
#include "types.h"
#include <ctime>
#include "Tile.h"
#include <cstdlib>
#include <iostream>
#include <memory>

class TileLinkedList {
   public:

      TileLinkedList();
      ~TileLinkedList();

      void clear();
      
      Tile* get(const unsigned int i) const;
      Tile* getRand() const;
      Tile* getTileByValue(string value) const;

      void add(Tile* tile);
      void prepend(Tile* tile);
      void append(Tile* tile);
      void print();
      bool contains(Tile* i) const;
      bool containsByValue(Tile* i) const;
      void deleteFirst();
      void deleteLast();
      void removeTile(Tile* aTile);
      void removeTileByValue(Tile* aTile);
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

#endif // WEEK06_LINKEDLIST_H
