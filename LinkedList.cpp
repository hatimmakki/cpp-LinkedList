
#include "LinkedList.h"

LinkedList::LinkedList() {
//   srand(time(NULL));

   head = nullptr;
   this->iSize = 0;
}

LinkedList::~LinkedList() {
   this->clear();
}

int LinkedList::size() const{
   return this->getSize();
}



/*
   Returns true if the list contains a SAME value
   
   Argument:
      a value : int
*/
bool LinkedList::contains(int val) const {
   
   bool found = false;
   std::shared_ptr<Node> node = head;
   
   while(node != nullptr && !found){ // one way of exit the loop. don't use break
      if(node->data == val){
         found = true;
      }
      
      node = node->next;
      
   }
   
   return found;
   
}

/*
   Deletes a node at specific index
*/
void LinkedList::deleteAt(unsigned int i){
   if (i < this->size()){
      if (i == 0) this->deleteFirst();
      else if (i == this->size()-1) {
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
      }
   } else {
      throw std::out_of_range("Out of range!");
   }
}


void LinkedList::removeByValue(int val){
   bool found = false;
   
   if(this->contains(val)){
      // value found
      // then, delete it
      if (this->size() == 1){
         // size = 1
         this->head = nullptr;
      } else {
         // size is > 1
         std::shared_ptr<Node> prev = this->head;
         std::shared_ptr<Node> node = this->head;
         
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


void LinkedList::deleteFirst() {
   
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

void LinkedList::deleteLast() {
   
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

void LinkedList::clear() {
   std::shared_ptr<Node> node = head;
   
   while (node != nullptr) {
      std::shared_ptr<Node> save = node->next;
      // delete node;
      node = save;
   }
   head = nullptr;
   this->iSize = 0;
}

// Gets a random value from the list
int LinkedList::getRand() const{
   
   int randomNum = rand() % this->size();

   return this->get(randomNum);
   
}



// i must be < size
int LinkedList::get(const unsigned int i) const{
   
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

   return node->data;
}

int LinkedList::getSize() const{
   return this->iSize;
}

void LinkedList::setSize(unsigned int newValue){
   this->iSize = newValue;
}

void LinkedList::sizeUp(){

   this->iSize++;
}
void LinkedList::sizeDown(){

   if(this->iSize <= 0)
      this->setSize(0);
   else
      this->iSize--;
}

/*
   Adds int at the end of the list (append)
*/
void LinkedList::add(int val){
   this->append(val);
}

void LinkedList::prepend(int val) {
   std::shared_ptr<Node> node = std::make_shared<Node>( Node(val, nullptr) );
   node->next = head;
   head = node;
   this->sizeUp();
}

/*
   Adds a node at the end of the list
*/
void LinkedList::append(int val) {
   // creqte new Node wpointing to nullptr
   //	TODO: fix structural programming

   std::shared_ptr<Node> newNode = std::make_shared<Node>( Node(val, nullptr) );

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

void LinkedList::print(){
   // TODO: print example : 3, 4, 5, 83, 20, 1
   std::shared_ptr<Node> node = this->head;

   while(node != nullptr){
      std::cout << node->data << ", ";
      node = node->next;
   }
   std::cout <<  std::endl;
}

std::shared_ptr<Node> LinkedList::getLastNode(){
   // loop until you get nullptr

   std::shared_ptr<Node> node = this->head;   // first item , head is null

   if(node != nullptr){
      while(node->next != nullptr){
         node = node->next;
      }
   }
   return node;
}

std::shared_ptr<Node> LinkedList::getSecondLastNode(){
   // loop until you get nullptr
   //	TODO: fix structural programming

   std::shared_ptr<Node> lastNode = this->getLastNode();   // first item , head is null
   std::shared_ptr<Node> node = this->head;
   
   if(node == nullptr){
      while(node != nullptr && node->next != lastNode){
         node = node->next;
      }
   }
   return node;
}

// for TESTING needs
std::shared_ptr<Node> LinkedList::getHead(){
   return this->head;
}

void LinkedList::shuffle(){
   
   // loop 3 times the list size
   for(int i = 0; i < this->size() * 3; i++){
      
      // get random value
      int r = this->getRand();
      
      this->removeByValue(r);
      
      // put the random node at the head
      this->prepend(r);
      
   }
}
