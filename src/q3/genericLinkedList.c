#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct{
    void* data;
    size_t size;
    void*(*printFunction)(void* data);
    struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void* printFunction){
    listElement* e = malloc(sizeof(listElement));
    if(e == NULL){
        //malloc has had an error
        return NULL; //return NULL to indicate an error.
    }
    char* dataPointer = malloc(sizeof(char)*size);
    if(dataPointer == NULL){
        //malloc has had an error
        free(e); //release the previously allocated memory
        return NULL; //return NULL to indicate an error.
    }
    memcpy(dataPointer, data, size);
    e->data = dataPointer;
    e->size = size;
    e->printFunction = printFunction;
    e->next = NULL;
    return e;
}

void printInt(void* data){
    printf("%d\n", *(int*)data);
}

void printDouble(void* data){
    printf("%lf\n", *(double*)data);
}

void printChar(void* data){
    printf("%c\n", *(char*)data);
}

void printString(void *data){
    printf("%s\n", (char*)data);
}


//Prints out each element in the list
void traverse(listElement* start){
    listElement* current = start;
    while(current != NULL){
        current->printFunction(current->data);
        current = current->next;
    }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size, void* printFunction){
    listElement* newEl = createEl(data, size, printFunction);
    listElement* next = el->next;
    newEl->next = next;
    el->next = newEl;
    return newEl;
}

//Delete the element after the given el
void deleteAfter(listElement* after){
    listElement* delete = after->next;
    listElement* newNext = delete->next;
    after->next = newNext;
    //need to free the memory because we used malloc
    free(delete->data);
    free(delete);
}

int length(listElement* list){
    int count = 0;
    listElement* current = list;
    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

void push(listElement** list, void* data, size_t size, void* printFunction){
    listElement* head = createEl(data, size, printFunction);
    head->next = *list;
    *list = head;
}

listElement* pop(listElement** list){
    if(list == NULL){
        return NULL;
    }

    listElement* popped = *list;
    *list = popped->next;
    popped->next = NULL;
    return popped;
}

void enqueue(listElement** list, void* data, size_t size, void* printFunction){
    listElement* head = createEl(data, size, printFunction);
    head->next = *list;
    *list = head;
}

listElement* dequeue(listElement* list){
    if(list == NULL){
        return NULL;
    }

    listElement* tail = list;
    listElement* nTail = NULL;
    while (tail->next != NULL){
        nTail = tail;
        tail = tail->next;
    }

    nTail->next = NULL;
    return tail;
}

