# cpp-LinkedList
implementation of Linked List of any type

# Diagram
![Diagram of Typed LinkedList](../master/images/diagram.jpg)


# Usage

## import
Download the files and import LinkedList.h

e.g. 

```c++
#include "LinkedList.h"
#include <iostream>
#include <exception>	// for exception handling
#include <cstdint>
```

## create a new list instance

This linked list uses templates. So, you can use whatever type you want.
The following example uses std::string as a type of the items in the list.

```c++
LinkedList<std::string> list = LinkedList<std::string>();
```
### Passed Types:

- [x] std::string
- [x] int
- [x] float

## add items

```c++
list.append("some string");
list.add("some string");	// same append
list.prepend("some string2");
list += "some text!";

```

### Example of merging 2 lists togother and adding items to the list
```c++

LinkedList<int> list1 = LinkedList<int>();
LinkedList<int> list2 = LinkedList<int>();

list1.append(1);
list1.append(2);
	
list2.append(3);
list2.append(4);
	
list1 += list2;
	
assert(list1.contains(4));
assert(list1.getSize() == 4);
	
list1 += 5;
assert(list1.contains(5));
assert(list1.getSize() == 5);

```


## delete items

```c++
list.deleteByValue("some string");
list.deleteAt(0);

list -= "text";		// will delete "text" from the list if it's found

// you can remove a list from a list if it's a subset
list_big -= list_small;		// e.g. list_big is 1,2,3,4,5 and list small is 3, 4. then list_big will be 1, 2, 5


```

## Delete all items

```c++
list.clear();
```

## Get item by index

```c++
list.get(3);
```

## Shuffle the list

```c++
list.shuffle();
```

## Check Subset

You can check if a list is subset of another list, by simply call isSubset(...) function
list1.isSubset(list2) is true if list2 is subset of list1
or similar to
list2.isSubsetOf(list1) is true if list2 is subset of list1

```c++
LinkedList<int> list1 = LinkedList<int>();
LinkedList<int> list2 = LinkedList<int>();
LinkedList<int> list3 = LinkedList<int>();
	
list1.append(1);
list1.append(2);
list1.append(3);
list1.append(4);
	
list2.append(3);
list2.append(4);


list3.append(1);
list3.append(2);
list3.append(5);

// list2 is subset of list1
assert(list1.isSubset(list2));
assert(!list1.isSubset(list3));


```


# Tasks

- [x] tests (std::strings)
- [x] tests (integers)
- [x] tests (floats)
- [ ] tests (char*)
- [ ] tests (performance)
- [ ] tests (Objects) -> need to fix contains and deleteAt functions
- [ ] fixing issue: if items are Objects, contains function breaks
- [ ] fixing issue: if items are Objects, deleteAt function breaks

