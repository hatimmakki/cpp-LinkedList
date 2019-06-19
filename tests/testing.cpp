
#include "../LinkedList.h"
#include <iostream>
#include <exception>
#include <cstdint>
#include "types.h"

#define EXIT_SUCCESS    0

using std::cout;
using std::endl;

void test_getLastNode();
void test_prepend_with_getLastNode();
void test_append();
void test_get();

void test_get_error_outofrange();
void test_deleteFirst();
void test_deleteLast();
void test_contains();
void test_containsByValue();
void test_removeTile();


void test_deleteAt();

int main(void) {
	
	// test test_getLatsNode method
	cout << "Testing LinkedList:" << endl;

	test_getLastNode();
	test_prepend_with_getLastNode();
	test_append();
	test_get();

	test_deleteFirst();
	test_deleteLast();





	return EXIT_SUCCESS;
	
}

void test_prepend(){
	LinkedList* list = new LinkedList();

	list->prepend(1);
	list->prepend(2);
	assert(list->get(0) == 2);
	assert(list->get(1) == 1);
	
	
	cout << WHITE_TEXT << "test_prepend: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;
	
	list->clear();
	if(list != nullptr) delete list;

}

void test_deleteAt(){
	LinkedList* list = new LinkedList();

	list->prepend(1);
	list->prepend(2);
	list->prepend(3);
	// 3 -> 2 -> 1
	list->deleteAt(2); // deletes 1

	assert(list->contains(3));
	assert(!list->contains(1));
	assert(list->contains(2));
	assert(!list->contains(7));

	cout << WHITE_TEXT << "test_deleteAt: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;
	list->clear();
	if(list != nullptr) delete list;

}
void test_deleteFirst(){
	
	LinkedList* list = new LinkedList();

	list->append(1);
	list->append(2);
	list->append(3);
	list->append(4);
	list->append(5);
	list->deleteFirst();
	assert(list->get(0) == 2);
	list->deleteFirst();
	assert(list->get(0) == 3);

	cout << WHITE_TEXT << "test_deleteFirst: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT <<  endl;

	list->clear();
	if(list != nullptr) delete list;

}


void test_contains(){
	LinkedList* list = new LinkedList();

	list->prepend(22);
	list->prepend(33);
	list->prepend(44);
	
	assert(list->contains(11));
	assert(list->contains(22));
	assert(list->contains(33));
	assert(!list->contains(4444));

	cout << WHITE_TEXT << "test_contains: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;
	list->clear();
	if(list != nullptr) delete list;

}

void test_getLastNode(){
	LinkedList* list = new LinkedList();
	
	list->prepend(1);
	list->prepend(2);
	list->prepend(3);
	list->prepend(4);

	assert(list->getLastNode()->data == 1);
	cout << WHITE_TEXT << "test_getLastNode: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT <<  endl;
	
	list->clear();
	if(list != nullptr) delete list;
	
}

void test_append(){
		
		LinkedList* list = new LinkedList();
		list->append(1);
		list->append(2);
		list->append(3);
		list->append(4);

		assert(list->getLastNode()->data == 4);
		cout << WHITE_TEXT << "test_append: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;
		list->clear();
		if(list != nullptr) delete list;

}


void test_prepend_with_getLastNode(){
	
	LinkedList* list = new LinkedList();
	
	
	list->prepend(1);   //last
	list->prepend(2);
	list->prepend(3);
	list->prepend(4);   //first

	assert(list->getLastNode()->data == 1);
	cout << WHITE_TEXT << "test_prepend_with_getLastNode: " << GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;
	list->clear();
	if(list != nullptr) delete list;

}

void test_get(){
	
	LinkedList* list = new LinkedList();

	try{
		
		list->append(3);      // last
		list->append(4);      // second
		list->append(5);      // first
	//   list->print();
		
		assert(list->get(2) == 5);
		assert(list->get(1) == 4);
		assert(list->get(0) == 3);

		cout << WHITE_TEXT << "test_get: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;

	} catch (std::exception& e){
		cout << e.what() << endl;
	}
	list->clear();
	if(list != nullptr) delete list;

}

void test_deleteLast(){
	
	LinkedList* list = new LinkedList();


	list->append(3);      // last
	list->append(4);      // second
	list->append(5);      // first
	
	assert(list->getHead()->data == 3);
	list->deleteFirst(); // delete 3
	
	assert(list->getHead()->data == 4);

	cout << WHITE_TEXT << "test_deleteFirst: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;
	list->clear();
	if(list != nullptr) delete list;

}
