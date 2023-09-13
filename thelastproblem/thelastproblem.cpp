#include <stdio.h>

int main() {
  char s[55];

  scanf("%50[^\n]", s);
  printf("Thank you, %s, and farewell!", s);
  return 0;
}
