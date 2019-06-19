
#include "TileLinkedList.h"

TileLinkedList::TileLinkedList() {
//   srand(time(NULL));

   head = nullptr;
   this->iSize = 0;
}

TileLinkedList::~TileLinkedList() {
   this->clear();
}

int TileLinkedList::size() const{
   return this->getSize();
}

/*
   Returns true if the list contains a similar tile
   
   Argument:
      a pointer to a tile : Tile*
*/
bool TileLinkedList::containsByValue(Tile* s) const {
   
   bool found = false;
   std::shared_ptr<Node> node = head;
   
   while(node != nullptr && !found){ // one way of exit the loop. don't use break
   
      if(node->tile->getString() == s->getString()){      // compare by value, not by address.
         found = true;
      }
      
      node = node->next;
      
   }
   
   return found;

}


/*
   Returns true if the list contains a SAME tile object
   
   Argument:
      a pointer to a tile : Tile*
*/
bool TileLinkedList::contains(Tile* s) const {
   
   bool found = false;
   std::shared_ptr<Node> node = head;
   
   while(node != nullptr && !found){ // one way of exit the loop. don't use break
      if(node->tile == s){
         found = true;
      }
      
      node = node->next;
      
   }
   
   return found;
   
}

void TileLinkedList::deleteAt(unsigned int i){
   //	TODO: fix structural programming

   if (i >= this->size()) return;
   if (i == 0) this->deleteFirst();
   if (i == this->size()-1) {
      this->deleteLast();
   }
   else {
      std::shared_ptr<Node> node = this->head;
      std::shared_ptr<Node> pNode = nullptr;
      for(int count = 0; count < i; count++){
         pNode = node;
         node = node->next;
      }
      pNode->next = node->next;
//      delete node;
   }
}


void TileLinkedList::removeTile(Tile* aTile){
   bool found = false;
   
   if(this->contains(aTile)){
      // tile found
      // then, delete it
      if (this->size() == 1){
         // size = 1
         this->head = nullptr;
      } else {
         // size is > 1
         std::shared_ptr<Node> prev = this->head;
         std::shared_ptr<Node> node = this->head;
         
         if(aTile == this->getHead()->tile){
            // aTile is the first tile in the list
            this->head = node->next;
            
         } else {
            
            // aTile is second or later
            while (node != nullptr && !found) {

               if(aTile == node->tile){
                  // found
                  prev->next = node->next;
                  found = true;
                  
               } else {
                  prev = node;      // prev is node
                  node = node->next;      // node goes to the next place
               }

            }

         }
         
//         delete node;

      }
      this->sizeDown();
      
   }

}

void TileLinkedList::removeTileByValue(Tile* aTile){
   bool found = false;
   
   if(this->contains(aTile)){
      // tile found
      // then, delete it
      if (this->size() == 1){
         // size = 1
         this->head = nullptr;
      } else {
         // size is > 1
         std::shared_ptr<Node> prev = this->head;
         std::shared_ptr<Node> node = this->head;
         
         if(aTile->getString() == this->getHead()->tile->getString()){
            // aTile is the first tile in the list
            this->head = node->next;
            
         } else {
            
            // aTile is second or later
            while (node != nullptr && !found) {

               if(aTile->getString() == node->tile->getString()){
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


void TileLinkedList::deleteFirst() {
   
   if(this->getSize() == 1){
      this->clear();
   }
   if(this->head != nullptr && this->getSize() > 1){
      std::shared_ptr<Node> nodeToDelete = this->head;
      this->head = nodeToDelete->next;
      // delete nodeToDelete;
   }
   this->sizeDown();
}

void TileLinkedList::deleteLast() {
   
   if (this->getSize() == 1){
      // just clear
      this->clear();
      
   } else if (this->getSize() > 1){
      std::shared_ptr<Node> last = this->getLastNode();
      std::shared_ptr<Node> secondLast = this->getSecondLastNode();
      secondLast->next = nullptr;
      this->sizeDown();
      // delete last;
   }
}

void TileLinkedList::clear() {
   std::shared_ptr<Node> node = head;
   
   while (node != nullptr) {
      std::shared_ptr<Node> save = node->next;
      // delete node;
      node = save;
   }
   head = nullptr;
   this->iSize = 0;
}

// Gets a random tile
Tile* TileLinkedList::getRand() const{
   

   int randomNum = rand() % this->size();

   return this->get(randomNum);
   
}



// i must be < size and > 0
Tile* TileLinkedList::get(const unsigned int i) const{
   
   unsigned int internalIndex = 0;
   
   if(i >= this->getSize() ){
      throw std::out_of_range ("You exceeded the size of the list");
   }
   
   std::shared_ptr<Node> node = this->head;
   
   // if no items
   if(node == nullptr) {
      throw std::out_of_range ("The list is empty.");
   }
   
   while(node != nullptr && internalIndex != i){
      node = node->next;
      internalIndex++;
   }

   return node->tile;
}

int TileLinkedList::getSize() const{
   return this->iSize;
}

void TileLinkedList::setSize(unsigned int newValue){
   this->iSize = newValue;
}

void TileLinkedList::sizeUp(){

   this->iSize++;
}
void TileLinkedList::sizeDown(){

   if(this->iSize <= 0)
      this->setSize(0);
   else
      this->iSize--;
}

/*
   Adds aTile* at the end of the list (append)
*/
void TileLinkedList::add(Tile* tile){
   this->append(tile);
}

void TileLinkedList::prepend(Tile* tile) {
   std::shared_ptr<Node> node = std::make_shared<Node>( Node(tile, nullptr) );
   node->next = head;
   head = node;
   this->sizeUp();
}

/*
   Adds a node at the end of the list
*/
void TileLinkedList::append(Tile* tile) {
   // creqte new Node wpointing to nullptr
   //	TODO: fix structural programming

   std::shared_ptr<Node> newNode = std::make_shared<Node>( Node(tile, nullptr) );

   // get the last Node and point it to the new created Node
   try {
      std::shared_ptr<Node> lastNode = this->getLastNode();
      
      
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

void TileLinkedList::print(){
   // TODO: print example : G3, H4, J9
   std::shared_ptr<Node> node = this->head;

   while(node != nullptr){
      std::cout << node->tile->getString() << ", ";
      node = node->next;
   }
   std::cout <<  std::endl;
}

std::shared_ptr<Node> TileLinkedList::getLastNode(){
   // loop until you get nullptr

   std::shared_ptr<Node> node = this->head;   // first item , head is null


   if(node == nullptr) return nullptr;
   while(node->next != nullptr){

      node = node->next;
   }

   return node;
}

std::shared_ptr<Node> TileLinkedList::getSecondLastNode(){
   // loop until you get nullptr
   //	TODO: fix structural programming

   std::shared_ptr<Node> lastNode = this->getLastNode();   // first item , head is null
   std::shared_ptr<Node> node = this->head;
   
   if(node == nullptr) return nullptr;
   
   while(node != nullptr && node->next != lastNode){
      node = node->next;
   }
   
   return node;
}

// for TESTING needs
std::shared_ptr<Node> TileLinkedList::getHead(){
   return this->head;
}

Tile* TileLinkedList::getTileByValue(string value) const{
   bool found = false;
   std::shared_ptr<Node> node = head;
   Tile* tile = nullptr;
   
   while(node != nullptr && !found){
      if(node->tile->getString() == value){
         tile = node->tile;
         found = true;
      }
      
      node = node->next;
      
   }
   
   return tile;
   
}

void TileLinkedList::shuffle(){
   
   // loop 3 times the list size
   for(int i = 0; i < this->size() * 3; i++){
      
      // get random tile
      Tile* r = this->getRand();
      
      this->removeTile(r);
      
      // put the random node at the head
      this->prepend(r);
      
   }
}
