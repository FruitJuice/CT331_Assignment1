#include <stdio.h>
#include "genericLinkedList.h"
#include "tests.h"

void runTests(){
  printf("Tests running...\n");

  //Inserting the first element
  listElement* item1 = createEl("First String", 30, &printString);
  traverse(item1);
  printf("Added a string\n\n");


  char c = 'c';
  listElement* item2 = insertAfter(item1, &c, sizeof(c), &printChar);
  traverse(item1);
  printf("Added a char\n\n");

  int in = 40;
  listElement* item3 = insertAfter(item2, &in, sizeof(in), &printInt);
  traverse(item1);
  printf("Added an int\n\n");

  double p = 58.49;
  listElement* item4 = insertAfter(item3, &p, sizeof(p), &printDouble);
  traverse(item1);
  printf("Added a double\n\n");

  printf("Current length of Linked List: %d\n\n", length(item1));

  push(&item1, "New String", 30, &printString);
  traverse(item1);
  printf("Pushed a new item onto the LL\n\n");

  listElement* removed = pop(&item1);
  traverse(item1);
  printf("Popped the newly added item\n\n");

  int k = 10;
  enqueue(&item1, &k, sizeof(k), &printInt);
  traverse(item1);
  printf("Enqueued a new item onto the LL\n\n");

  removed = dequeue(item1);
  traverse(item1);
  printf("Dequeued item from LL\n\n");


  printf("\nTests complete.\n");
}
