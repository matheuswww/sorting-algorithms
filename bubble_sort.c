#include <stdio.h>

void main() {
  int list[] = {6,8,5,2,7,8};
  int lenght = sizeof(list) / sizeof(int);
  int aux = 0;

  for (int j = 0; j < lenght - 1; j++) {
    for (int i = 0; i < lenght - 1; i++)
    {
      if(list[i] > list[i + 1]) {
        aux = list[i + 1];
        list[i + 1] = list[i];
        list[i] = aux;
      }
    }
  }

  for (int i = 0; i < lenght; i++)
  {
    printf("%d -> ",list[i]);
  }
  puts("");
}