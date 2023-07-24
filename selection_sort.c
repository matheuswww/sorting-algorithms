#include <stdio.h>

void main() {
  int list[] = {723,5342,1212,8432,3325};
  int lenght = sizeof(list) / sizeof(int);
  int min_index = 0;
  int aux = 0;

  for (int j = 0; j < lenght; j++)
  {
    min_index = j;
    for (int i = j + 1;i < lenght;i++) {
      if(list[i] < list[min_index]) {
        min_index = i;
      }
    }
    if(list[j] > list[min_index]) {
      aux = list[j];
      list[j] = list[min_index];
      list[min_index] = aux;
    }
  }
  
  for (int i = 0; i < lenght; i++)
  {
    printf("%d -> ",list[i]);
  }
  puts("");
}
