#include <stdlib.h>
#include <stdio.h>

typedef struct array {
  int* array;
  int size;
  int fill;
}Array;


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

Array* array_get_position(Array* array,int init_pos,int end_pos) {
  if(init_pos < 0 || end_pos > array->size) {
    error("dynamicArray_get_pos: ERROR invalid postion");
  }

  Array* new_array = array_create(end_pos - init_pos);
  for (int i = init_pos,j = 0; i < end_pos; i++,j++) {
    new_array->array[j] = array->array[i];
  }
  return new_array;
}

void array_merge(Array *list,int init,int end,int middle) {
  Array* right = array_get_position(list,init,middle);
  Array* left = array_get_position(list,middle,end);
  puts("");
  int top_left = 0;
  int top_right = 0;
  for (int k = init; k < end; k++)
  {
    if(top_left >= left->size) {
      list->array[k] = right->array[top_right];
      top_right = top_right + 1;
    } else if (top_right >= right->size) {
      list->array[k] = left->array[top_left];
      top_left = top_left + 1;
    } else if (left->array[top_left] < right->array[top_right]) {
      list->array[k] = left->array[top_left];
      top_left = top_left + 1;
    } else {
      list->array[k] = right->array[top_right];
      top_right = top_right + 1;
    }
  }
  free(right->array);
  free(right);
  free(left->array);
  free(left);
}

void array_merge_sort(Array *list,int start,int end) {
  if((end - start) > 1) {
    int middle = (start + end) / 2;
    array_merge_sort(list,start,middle);
    array_merge_sort(list,middle,end);
    array_merge(list,start,end,middle);
  }
}

void main() {
  Array* array = array_create(10);
  array_push(array,10);
  array_push(array,9);
  array_push(array,8);
  array_push(array,7);
  array_push(array,6);
  array_push(array,5);
  array_push(array,4);
  array_push(array,3);
  array_push(array,2);
  array_push(array,1);

  array_merge_sort(array,0,10);
  array_print(array);
}