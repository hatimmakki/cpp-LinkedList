#include "../LinkedList.h"
#include <iostream>
#include <exception>
#include <cstdint>
#include "types.h"

using namespace std;
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

struct Man{
	int age;
	float slry;
	std::string name;
};


int main(int argc, char *argv[]) {
	
	cout << "Testing LinkedList:" << endl;
	test_getLastNode();
	test_prepend_with_getLastNode();
	test_append();
	test_get();
	test_devide();
	test_get_error_outofrange();
	test_deleteFirst();
	test_deleteLast();
//	test_contains();
	test_get_error_outofrange_deleteAt();

}


void test_get_error_outofrange_deleteAt() {
	
	try{
		
		Man man1 = {35, 15000, "Hatim1"};
		Man man2 = {36, 16000, "Hatim2"};
		Man man3 = {37, 17000, "Hatim3"};
		
		LinkedList<Man> list = LinkedList<Man>();

		list.append(man1);
		list.deleteAt(0);
		list.deleteAt(0);		// this should throw error
		cout << WHITE_TEXT << "test_get_error_outofrange_deleteAt: " << RED_TEXT << "FAILED" << WHITE_TEXT << endl;

	} catch (std::out_of_range& e){
		cout << WHITE_TEXT << "test_get_error_outofrange_deleteAt: " << GREEN_TEXT << "PASSED : " << e.what() <<  WHITE_TEXT << endl;

	}

}

void test_get_error_outofrange() {
	
	try{
		
		Man man1 = {35, 15000, "Hatim1"};
		Man man2 = {36, 16000, "Hatim2"};
		Man man3 = {37, 17000, "Hatim3"};
		
		LinkedList<Man> list = LinkedList<Man>();

		list.append(man1);
		list.get(2);
		cout << WHITE_TEXT << "test_get_error_outofrange: "<< RED_TEXT << "FAILED" << WHITE_TEXT << endl;

	} catch (std::out_of_range& e){
		cout << WHITE_TEXT << "test_get_error_outofrange: "<< GREEN_TEXT << "PASSED : " << e.what() <<  WHITE_TEXT << endl;

	}
}

void test_devide() {

}

void test_prepend(){
	
	Man man1 = {35, 15000, "Hatim1"};
	Man man2 = {36, 16000, "Hatim2"};
	Man man3 = {37, 17000, "Hatim3"};
	
	LinkedList<Man> list = LinkedList<Man>();

	list.prepend(man1);
	list.prepend(man2);
	assert(list.get(0).name == man2.name);
	assert(list.get(1).name == man1.name);
	
	
	cout << WHITE_TEXT << "test_prepend: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;
	
}

void test_deleteAt(){
	Man man1 = {35, 15000, "Hatim1"};
	Man man2 = {36, 16000, "Hatim2"};
	Man man3 = {37, 17000, "Hatim3"};
	Man man7 = {37, 17000, "Hatim3"};
	
	LinkedList<Man> list = LinkedList<Man>();

	list.prepend(man1);
	list.prepend(man2);

	list.prepend(man3);

	// 3 . 2 . 1
	list.deleteAt(2); // deletes 1


	assert(list.contains(man3));
	assert(!list.contains(man1));
	assert(list.contains(man2));
	assert(!list.contains(man7));

	cout << WHITE_TEXT << "test_deleteAt: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;
	
}

void test_deleteFirst(){
	
	Man man1 = {35, 15000, "Hatim1"};
	Man man2 = {36, 16000, "Hatim2"};
	Man man3 = {37, 17000, "Hatim3"};
	Man man4 = {37, 17000, "Hatim3"};
	Man man5 = {37, 17000, "Hatim3"};
	
	LinkedList<Man> list = LinkedList<Man>();

	list.append(man1);
	list.append(man2);
	list.append(man3);
	list.append(man4);
	list.append(man5);
	list.deleteFirst();
	assert(list.get(0).name == man2.name);
	list.deleteFirst();
	assert(list.get(0).name == man3.name);

	cout << WHITE_TEXT << "test_deleteFirst: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT <<  endl;



}

void test_contains(){
	Man man1 = {35, 15000, "Hatim1"};
	Man man2 = {36, 16000, "Hatim2"};
	Man man3 = {37, 17000, "Hatim3"};
	Man man4 = {37, 17000, "Hatim3"};
	Man man5 = {37, 17000, "Hatim3"};
	
	LinkedList<Man> list = LinkedList<Man>();

	list.prepend(man1);
	list.prepend(man2);
	list.prepend(man3);
	
	assert(!list.contains(man4));
	assert(list.contains(man1));
	assert(list.contains(man2));
	assert(!list.contains(man5));

	cout << WHITE_TEXT << "test_contains: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;


}

void test_getLastNode(){
	Man man1 = {35, 15000, "Hatim1"};
	Man man2 = {36, 16000, "Hatim2"};
	Man man3 = {37, 17000, "Hatim3"};
	Man man4 = {37, 17000, "Hatim3"};
	Man man5 = {37, 17000, "Hatim3"};
	
	LinkedList<Man> list = LinkedList<Man>();
	
	list.prepend(man1);
	list.prepend(man2);
	list.prepend(man3);
	list.prepend(man4);

	assert(list.getLastNode()->data.name == man1.name);
	cout << WHITE_TEXT << "test_getLastNode: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT <<  endl;
	
	
}

void test_append(){
		
		Man man1 = {35, 15000, "Hatim1"};
		Man man2 = {36, 16000, "Hatim2"};
		Man man3 = {37, 17000, "Hatim3"};
		Man man4 = {37, 17000, "Hatim3"};
		Man man5 = {37, 17000, "Hatim3"};
		
		LinkedList<Man> list = LinkedList<Man>();
		list.append(man1);
		list.append(man2);
		list.append(man3);
		list.append(man4);

		assert(list.getLastNode()->data.name == man4.name);
		cout << WHITE_TEXT << "test_append: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;


}


void test_prepend_with_getLastNode(){
	
	Man man1 = {35, 15000, "Hatim1"};
	Man man2 = {36, 16000, "Hatim2"};
	Man man3 = {37, 17000, "Hatim3"};
	Man man4 = {37, 17000, "Hatim3"};
	Man man5 = {37, 17000, "Hatim3"};
	
	LinkedList<Man> list = LinkedList<Man>();
	
	list.prepend(man1);   //last
	list.prepend(man2);
	list.prepend(man3);
	list.prepend(man4);   //first

	assert(list.getLastNode()->data.name == man1.name);
	cout << WHITE_TEXT << "test_prepend_with_getLastNode: " << GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;


}

void test_get(){
	
	Man man1 = {35, 15000, "Hatim1"};
	Man man2 = {36, 16000, "Hatim2"};
	Man man3 = {37, 17000, "Hatim3"};
	Man man4 = {37, 17000, "Hatim3"};
	Man man5 = {37, 17000, "Hatim3"};
	
	LinkedList<Man> list = LinkedList<Man>();

	try{
		
		list.append(man3);      // last
		list.append(man4);      // second
		list.append(man5);      // first
	//   list.print();
		
		assert(list.get(2).name == man5.name);
		assert(list.get(1).name == man4.name);
		assert(list.get(0).name == man3.name);

		cout << WHITE_TEXT << "test_get: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;

	} catch (std::exception& e){
		cout << e.what() << endl;
	}


}

void test_deleteLast(){
	
	Man man1 = {35, 15000, "Hatim1"};
	Man man2 = {36, 16000, "Hatim2"};
	Man man3 = {37, 17000, "Hatim3"};
	Man man4 = {37, 17000, "Hatim3"};
	Man man5 = {37, 17000, "Hatim3"};
	
	LinkedList<Man> list = LinkedList<Man>();

	list.append(man3);      // last
	list.append(man4);      // second
	list.append(man5);      // first
	
	assert(list.getHead()->data.name == man3.name);
	list.deleteFirst(); // delete 3
	
	assert(list.getHead()->data.name == man4.name);

	cout << WHITE_TEXT << "test_deleteFirst: "<< GREEN_TEXT << "PASSED" << WHITE_TEXT << endl;


}
