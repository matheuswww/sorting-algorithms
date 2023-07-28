#include <stdio.h>
#include <stdlib.h>

typedef struct array {
  int* array;
  int size;
  int fill;
} Array;

void error(char msg[]) {
  fprintf(stderr,"%s\n",msg);
  exit(EXIT_FAILURE);
}

void array_print(Array* array) {
  printf("[");
  for (int i = 0; i < array->size; i++)
  {
    printf("%d",array->array[i]);
    if(i != array->size - 1) printf(",");
  }
  printf("]");
  puts("");
}

Array* array_create(int size) {
  Array* array = (Array*)malloc(sizeof(Array));
  array->array = (int *)malloc(size * sizeof(int));
  array->size = size;
  array->fill = -1;
  return array;
}

void array_push(Array* array,int v) {
  array->array[array->fill + 1] = v;
  array->fill ++;
}

int partition(Array* list,int init,int end) {
  int pivot = list->array[end];
  int i = init;
  int aux = 0;
  for (int j = init; j < end; j++) {
    if(list->array[j] <= pivot) {
      aux = list->array[j];
      list->array[j] = list->array[i];
      list->array[i] = aux;
      i++;
    }
  }
  aux = list->array[i];
  list->array[i] = list->array[end];
  list->array[end] = aux;
  return i;
}

void array_quicksort(Array* list,int init,int end) {
  int p = 0;
  if(init < end) {
    p = partition(list,init,end);
    array_quicksort(list,init,p-1);
    array_quicksort(list,p+1,end);
  }
}

void main() {
  Array* list = array_create(10);
  array_push(list,10);
  array_push(list,9);
  array_push(list,8);
  array_push(list,7);
  array_push(list,6);
  array_push(list,5);
  array_push(list,4);
  array_push(list,3);
  array_push(list,2);
  array_push(list,1);

  printf("%d",list->array[9]);
  array_quicksort(list,0,list->size - 1);

  array_print(list);
}
