#ifndef CT331_ASSIGNMENT_LINKED_LIST_ANYDATA
#define CT331_ASSIGNMENT_LINKED_LIST_ANYDATA

typedef struct listElementStruct listElement;

void printInt(void* data);
void printDouble(void* data);
void printChar(void* data);
void printString(void *data);

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void* printFunction);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size, void* printFunction);

//Delete the element after the given el
void deleteAfter(listElement* after);

//Return the number of elements in a linked list
int length(listElement* list);

//Push a new element onto the head of the list
void push(listElement** list, void* data, size_t size, void* printFunction);

//Pop and element from the head of the list
listElement* pop(listElement** list);

//Enqueue a new element onto the head of the list, same as push
void enqueue(listElement** list, void* data, size_t size, void* printFunction);

//Dequeue an element from the tail of the list
listElement* dequeue(listElement* list);


#endif
