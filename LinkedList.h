
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <memory>

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

      void clear() {
         std::shared_ptr<Node<T>> node = head;
         
         while (node != nullptr) {
            std::shared_ptr<Node<T>> save = node->next;
            // delete node;
            node = save;
         }
         head = nullptr;
         this->iSize = 0;

      }
      
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
      
      T getRand() const {
         int randomNum = rand() % this->size();

         return this->get(randomNum);

      }
      
      void add(T val){
         this->append(val);
      }

      
      void prepend(T val){
         std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>( Node<T>(val, nullptr) );
         node->next = head;
         head = node;
         this->sizeUp();
      }

      
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
      
      void print(){
         // TODO: print example : 3, 4, 5, 83, 20, 1
         std::shared_ptr<Node<T>> node = this->head;

         while(node != nullptr){
            std::cout << node->data << ", ";
            node = node->next;
         }
         std::cout <<  std::endl;
      }
      
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

      std::shared_ptr<Node<T>> getHead(){
         return this->head;
      }

      
      // Size
      int size() const {
         return this->getSize();
      }
      
      int getSize() const {
         return this->iSize;

      }
      void setSize(unsigned int newValue) {
         this->iSize = newValue;

      }
      void sizeUp(){

         this->iSize++;
      }

      void sizeDown(){

         if(this->iSize <= 0)
            this->setSize(0);
         else
            this->iSize--;
      }

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
//      Node* head;
      std::shared_ptr<Node<T>> head;
      int iSize;
};

#endif // LINKEDLIST_H
