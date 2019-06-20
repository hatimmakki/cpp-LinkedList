
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <memory>

/*

   A collection of items implemented using Linked List algorithm
   
*/
template <typename T>
class LinkedList {
   public:

      LinkedList(){
         
         head = nullptr;
         this->iSize = 0;
      }
      
      ~LinkedList(){
         this->clear();
      }

      /*
         Clears all items in the list
      */
      void clear() {

         head = nullptr;
         this->iSize = 0;

      }
      
      /*
         overloading += operator for the list
         used to APPEND a new item into the list
         
         list.print(); // 1, 44, 2, 6, 4,
         e.g. list += 5
         list.print(); // 1, 44, 2, 6, 4, 5,
         
         Arguments:
            value the item you want to append : T (any type)
            
      */
      LinkedList& operator+=(T value){
         this->append(value);
         return *this;
      }
      
      /*
         overloading -= operator for the list
         used to remove an item from the list
         
         list.print(); // 1, 44, 2, 6, 4,
         e.g. list -= 44
         list.print(); // 1, 2, 6, 4, 5,
         
         Arguments:
            value the item you want to remove : T (any type)
            
      */
      LinkedList& operator-=(T value){
         this->removeByValue(value);
         return *this;
      }

      /*
         overloading -= operator for the list
         used to remove a list of items from the list 
            if the passed list is subset of this list
         
         list1.print(); // 1, 44, 2, 6, 4,
         list2.print(); // 1, 44,
         
         e.g. list1 -= list2
         list1.print(); // 2, 6, 4,
         
         Arguments:
            other The list you want to remove : LinkedList
            
      */
      LinkedList& operator-=( LinkedList& other){
         
         if( other.isSubsetOf(*this)){
            std::shared_ptr<Node<T>> node = other.getHead();
            
            // if no items
            if(other.getSize() > 0) {
               while(node != nullptr){
                  this->removeByValue(node->data);
                  node = node->next;
               }
            }

         }
         return *this;
      }

      LinkedList& operator+=(const LinkedList& other){
         
         if(this->getSize() == 0){
            this->head = other.head;
         } else {
            std::shared_ptr<Node<T>> lastNode = this->getLastNode();
            lastNode->next = other.head;
            
         }
         // edit size
         this->setSize(this->getSize() + other.getSize());
         return *this;
      }

      /*
         Gets item by index
         
         Arguments:
            i index : unsigned int
         Throws:
            std::out_of_range : if the index >= the size of the list
      */
      T get(const unsigned int i) const {
         unsigned int internalIndex = 0;
         
         if(i >= this->getSize() ){
            throw std::out_of_range ("You exceeded the size of the list");
         }
         
         std::shared_ptr<Node<T>> node = this->head;
         
         // if no items
         if(node == nullptr) {
            throw std::out_of_range ("The list is empty.");
         }
         
         while(node != nullptr && internalIndex != i){
            node = node->next;
            internalIndex++;
         }

         return node->data;

      }
      
      /*
         Gets random item
      */
      T getRand() const {
         int randomNum = rand() % this->size();

         return this->get(randomNum);

      }
      
      /*
         Detemines if a list is subset of this list or not
      */
      bool isSubset(LinkedList& other) const {

         if(other.getSize() > 0){
   //         for(int i = 0; i < other.getSize(); ++i){}
            std::shared_ptr<Node<T>> node = other.getHead();
            while(node != nullptr){
               if(!this->contains(node->data)) return false;

               node = node->next;
            }
            
         }
         
         return true;
      }
      
      /*
         Detemines if a list is subset of this list or not
      */
      bool isSubsetOf(LinkedList& other) const {

         if(this->getSize() > 0){
   //         for(int i = 0; i < other.getSize(); ++i){}
            std::shared_ptr<Node<T>> node = this->head;
            while(node != nullptr){
               if(!other.contains(node->data)) return false;

               node = node->next;
            }
            
         }
         
         return true;
      }



      /*
         Appends an item to the list
         
         Arguments:
            item : T (any type) - numbers and string is tested and passed all tests
      */
      void add(T val){
         this->append(val);
      }

      
      /*
         Prepends an item to the list
         
         Arguments:
            item : T (any type) - numbers and string is tested and passed all tests
      */
      void prepend(T val){
         std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>( Node<T>(val, nullptr) );
         node->next = head;
         head = node;
         this->sizeUp();
      }

      /*
         Appends an item to the list
         
         Arguments:
            item : T (any type) - numbers and string is tested and passed all tests
      */
      void append(T val){
         // creqte new Node wpointing to nullptr
         //	TODO: fix structural programming

         std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>( Node<T>(val, nullptr) );

         // get the last Node and point it to the new created Node
         try {
            std::shared_ptr<Node<T>> lastNode = this->getLastNode();
            
            
            if(lastNode == nullptr){
               // add first node
               this->head = newNode;
               this->sizeUp();
               return;
            }
            
            // node is not first item.
            
            lastNode->next = newNode;
            this->sizeUp();
         } catch (std::exception& e) {
            std::cout << "error: " << e.what() << std::endl;

         }

      }
      
      
      /*
         Prints all the items
         
         e.g. 3, 43, 75, 23, 44,
         
      */
      void print(){
         // TODO: print example : 3, 4, 5, 83, 20, 1
         std::shared_ptr<Node<T>> node = this->head;

         while(node != nullptr){
            std::cout << node->data << ", ";
            node = node->next;
         }
         std::cout <<  std::endl;
      }
      
      /*
         Returns a boolean showing whether the list contains this item or not
         
         Arguments:
            i item : T (any type)
      */

      bool contains(T i) const{
         bool found = false;
         std::shared_ptr<Node<T>> node = head;
         
         while(node != nullptr && !found){ // one way of exit the loop. don't use break
            if(node->data == i){
               found = true;
            }
            
            node = node->next;
            
         }
         
         return found;
         

      }

      /*
         Deletes the first item in the list
         it does nothing if the list is empty
      */
      void deleteFirst() {
         if(this->getSize() == 1){
            this->clear();
         }
         if(this->head != nullptr && this->getSize() > 1){
            std::shared_ptr<Node<T>> nodeToDelete = this->head;
            this->head = nodeToDelete->next;
            // delete nodeToDelete;
            this->sizeDown();
         }
         

      }
      
      /*
         Deletes the last item in the list
         it does nothing if the list is empty
      */
      void deleteLast() {
         if (this->getSize() == 1){
            // just clear
            this->clear();
            
         } else if (this->getSize() > 1){
            std::shared_ptr<Node<T>> last = this->getLastNode();
            std::shared_ptr<Node<T>> secondLast = this->getSecondLastNode();
            secondLast->next = nullptr;
            this->sizeDown();
            // delete last;
         }

      }
      
      
      /*
         Removes an item from the list by the value of the item
         it does nothing if the item isn't in the list
         Arguments:
            val item's value : T (any type)
         
         e.g. 
         lsit.print() // 1,5,3,4,
         list.removeByValue(5);
         lsit.print() // 1,3,4,
         
      */
      void removeByValue(T val) {
         bool found = false;
         
         if(this->contains(val)){
            // value found
            // then, delete it
            if (this->size() == 1){
               // size = 1
               this->head = nullptr;
            } else {
               // size is > 1
               std::shared_ptr<Node<T>> prev = this->head;
               std::shared_ptr<Node<T>> node = this->head;
               
               if(val == this->getHead()->data){
                  // value is the first tile in the list
                  this->head = node->next;
                  
               } else {
                  
                  // value is second or later
                  while (node != nullptr && !found) {

                     if(val == node->data){
                        // found
                        prev->next = node->next;
                        found = true;
                        
                     } else {
                        prev = node;      // prev is node
                        node = node->next;      // node goes to the next place
                     }

                  }

               }
               //delete node;


            }
            
            this->sizeDown();
            
         }

      }
      
      /*
         Returns the last node in the list         
      */
      std::shared_ptr<Node<T>> getLastNode() {
         // loop until you get nullptr

         std::shared_ptr<Node<T>> node = this->head;   // first item , head is null

         if(node != nullptr){
            while(node->next != nullptr){
               node = node->next;
            }
         }
         return node;
      }

      /*
         Returns the second last node in the list         
      */
      std::shared_ptr<Node<T>> getSecondLastNode(){
         // loop until you get nullptr
         //	TODO: fix structural programming

         std::shared_ptr<Node<T>> lastNode = this->getLastNode();   // first item , head is null
         std::shared_ptr<Node<T>> node = this->head;
         
         if(node != nullptr){
            while(node != nullptr && node->next != lastNode){
               node = node->next;
            }
         }
         return node;
      }
      
      /*
         Returns the head of the list, which is the first item         
      */

      std::shared_ptr<Node<T>> getHead(){
         return this->head;
      }

      
      /*
         Returns the size of the list         
      */
      int size() const {
         return this->getSize();
      }
      
      /*
         Returns the size of the list         
      */
      int getSize() const {
         return this->iSize;

      }
      
      /*
         sets the size of the list         
      */
      void setSize(unsigned int newValue) {
         this->iSize = newValue;

      }
      
      /*
         increase the size by 1         
      */
      void sizeUp(){

         this->iSize++;
      }


      /*
         decrease the size by 1         
      */
      void sizeDown(){

         if(this->iSize <= 0)
            this->setSize(0);
         else
            this->iSize--;
      }

      /*
         Shuffles the items         
      */

      void shuffle(){
         
         // loop 3 times the list size
         for(int i = 0; i < this->size() * 3; i++){
            
            // get random value
            int r = this->getRand();
            
            this->removeByValue(r);
            
            // put the random node at the head
            this->prepend(r);
            
         }
      }

      /*
         Deletes an item by index
         
         Arguments:
            i index: the index of the item which you want to delete
                     
         Throw:
            std::out_of_range
            
      */

      void deleteAt(unsigned int i) {
         if (i < this->size()){
            if (i == 0) this->deleteFirst();
            else if (i == this->size()-1) {
               this->deleteLast();
            }
            else {
               std::shared_ptr<Node<T>> node = this->head;
               std::shared_ptr<Node<T>> pNode = nullptr;
               int count = 0;
               bool found = false;
               while(node != nullptr && !found){
                  count++;
                  pNode = node;
                  node = node->next;
                  if(count == i){
                     found = true;
                     pNode->next = node->next;
                     this->sizeDown();
                  }

               }

            }
         } else {
            throw std::out_of_range("Out of range! You can't delete item that is not exist!!!");
         }

      }
   private:
   
      // the head node of the list
      std::shared_ptr<Node<T>> head;
      
      // list size
      int iSize;
};

#endif // LINKEDLIST_H
