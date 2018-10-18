#include <stdio.h>

int main(int arg, char* argc[]){
  int a;
  int* b;
  long c;
  double* d;
  char** e;
  printf("Int size: %d \n",sizeof(a));
  printf("Int pointer size: %d\n",sizeof(b));
  printf("Long size: %d\n",sizeof(c));
  printf("Double pointer size: %d\n",sizeof(d));
  printf("Int pointer size: %d\n",sizeof(e));

  return 0;
}
