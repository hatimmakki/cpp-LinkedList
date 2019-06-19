# cpp-LinkedList
implementation of Linked List of any type

# Usage


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

```

## delete items

```c++
list.deleteByValue("some string");
list.deleteAt(0);

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

# Tasks

- [x] tests (std::strings)
- [x] tests (integers)
- [x] tests (floats)
- [ ] tests (char*)
- [ ] tests (performance)
- [ ] tests (Objects) -> need to fix contains and deleteAt functions
- [ ] fixing issue: if items are Objects, contains function breaks
- [ ] fixing issue: if items are Objects, deleteAt function breaks

