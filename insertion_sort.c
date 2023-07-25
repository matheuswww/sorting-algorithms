#include <stdio.h>

void main() {
  int list[] = {9,6,5,2,1,0};
  int lenght = sizeof(list) / sizeof(int);

for (int i = 0; i < lenght; i++)
{
  int key = list[i];
  int j = j - 1;
  while (list[j]>=0 && list[j] > key)
  {
    list[j + 1] = list[j];
    j = j - 1;
  }
  list[j + 1] = key;
}
  
  for (int i = 0; i < lenght; i++) {
    printf("%d -> ",list[i]);
  }
  puts("");
}