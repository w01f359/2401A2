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

  temp[1] = *sum;

  st_pop(stk, 2, temp);
}




void sumRecursive(int numElements, int *intArray, int *sum, StackType *stk)
{

  int temp[2];
  int i;
  temp[0] = numElements;
  temp[1] = *sum;

  if (numElements == 0) {
    *sum = 0;
    st_push(stk, "sumRecursive", 2, temp);
    st_pop(stk, 2, temp);
    return;
  }

  st_push(stk, "sumRecursive", 2, temp);

  sumRecursive(numElements-1, intArray, sum, stk);
  *sum += intArray[numElements-1];
  temp[0] = numElements;
  temp[1] = *sum;
  st_pop(stk, 2, temp);
}

