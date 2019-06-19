
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
void test_devide();
void test_get_error_outofrange();
void test_get_error_outofrange_deleteAt();
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
	test_devide();
	test_get_error_outofrange();
	test_deleteFirst();
	test_deleteLast();
	test_contains();
	test_get_error_outofrange_deleteAt();




	 test_deleteAt();

	return EXIT_SUCCESS;
	
}

void test_get_error_outofrange_deleteAt() {
	
	try{
		
		LinkedList<float> list = LinkedList<float>();

		list.append(1);
		list.deleteAt(0);
		list.deleteAt(0);		// this should throw error
		cout << WHITE_TEXT << "test_get_error_outofrange_deleteAt: " << RED_TEXT << "FAILED" << WHITE_TEXT << endl;

	} catch (std::out_of_range& e){
		cout << WHITE_TEXT << "test_get_error_outofrange_deleteAt: " << GREEN_TEXT << "PASSED : " << e.what() <<  WHITE_TEXT << endl;

	}

}

void test_get_error_outofrange() {
	
	try{
		
	LinkedList<float> list = LinkedList<float>();

		list.append(1);
		
		cout << list.get(2) << WHITE_TEXT << "test_get_error_outofrange: "<< RED_TEXT << "FAILED" << WHITE_TEXT << endl;

	} catch (std::out_of_range& e){
		cout << WHITE_TEXT << "test_get_error_outofrange: "<< GREEN_TEXT << "PASSED : " << e.what() <<  WHITE_TEXT << endl;

	}
}
void test_devide() {
	LinkedList<float> list = LinkedList<float>();
	list.append(1);
	assert(list.get(0) / 2 == 0.5);
	cout << WHITE_TEXT << "test_devide: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;

}
void test_prepend(){
	
	LinkedList<float>* list = new LinkedList<float>();

	list->prepend(1);
	list->prepend(2);
	assert(list->get(0) == 2);
	assert(list->get(1) == 1);
	
	
	cout << WHITE_TEXT << "test_prepend: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;
	
	list->clear();
	if(list != nullptr) delete list;

}

void test_deleteAt(){
	LinkedList<float>* list = new LinkedList<float>();

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
	
	LinkedList<float>* list = new LinkedList<float>();

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
	LinkedList<float>* list = new LinkedList<float>();

	list->prepend(22);
	list->prepend(33);
	list->prepend(44);
	
	assert(!list->contains(11));
	assert(list->contains(22));
	assert(list->contains(33));
	assert(!list->contains(4444));

	cout << WHITE_TEXT << "test_contains: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;
	list->clear();
	if(list != nullptr) delete list;

}

void test_getLastNode(){
	LinkedList<float>* list = new LinkedList<float>();
	
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
		
		LinkedList<float>* list = new LinkedList<float>();
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
	
	LinkedList<float>* list = new LinkedList<float>();
	
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
	
	LinkedList<float>* list = new LinkedList<float>();

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
	
	LinkedList<float>* list = new LinkedList<float>();

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
