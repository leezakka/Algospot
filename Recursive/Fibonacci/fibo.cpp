#include <stdio.h>

int recursive(int n);

int main() {

  int n;

  printf("Input : ");
  scanf("%d",&n);
  
  printf("Result[%d]\n", recursive(n));

  return 0;
}

int recursive(int n) {

  if (n==1)
    return 1;
  if (n<1)
    return 0;

  int res = recursive(n-1) + recursive(n-2);
  return res;

}
