#include <stdio.h>
#include <string.h>
#include "stackDefs.h"

void sumIterative(int numElements, int *intArray, int *sum, StackType *stk)
{
  int i;
  *sum = 0;
  int temp[2];
  temp[0] = numElements;
  temp[1] = *sum;

  for (i=0; i<numElements; ++i)
    *sum += intArray[i];

  st_push(stk, "sumIterative", 2, temp);

  temp[0] = 0;
  temp[1] = *sum;

  st_pop(stk, 2, temp);
}




void sumRecursive(int numElements, int *intArray, int *sum, StackType *stk)
{
  if (numElements == 0) {
    *sum = 0;
    return;
  }

  sumRecursive(numElements-1, intArray, sum, stk);
  *sum += intArray[numElements-1];
}

