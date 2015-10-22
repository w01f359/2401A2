#include <stdio.h>
#include <string.h>
#include "stackDefs.h"

/*
  function: sumIterative
  purpose:  to sum the elements of an array iteratively
  in:      numElements - the number of elements to sum
  in:      *intArray - pointer to the numbers to be summed 
  in:      *sum - the sum of the numbers
  in/out:  *stk - the stack with which to use to sum the numbers
*/
void sumIterative(int numElements, int *intArray, int *sum, StackType *stk)
{
  int i;
  *sum = 0;
  int params[2];
  
  //store the parameters
  params[0] = numElements;
  params[1] = *sum;

  for (i=0; i<numElements; ++i)
    *sum += intArray[i];

  st_push(stk, "sumIterative", 2, params);

  //reset parameter that's changed
  params[1] = *sum;

  st_pop(stk, 2, params);
}

/*
  function: sumRecursive
  purpose:  to sum the elements of an array using recursion
  in:      numElements - the number of elements to sum
  in:      *intArray - pointer to the numbers to be summed 
  in:      *sum - the sum of the numbers
  in/out:  *stk - the stack with which to use to sum the numbers
*/
void sumRecursive(int numElements, int *intArray, int *sum, StackType *stk)
{

  int params[2];
  int i;
  
  //store the parameters
  params[0] = numElements;
  params[1] = *sum;

  if (numElements == 0) {
    *sum = 0;
    st_push(stk, "sumRecursive", 2, params);
    st_pop(stk, 2, params);
    return;
  }

  st_push(stk, "sumRecursive", 2, params);

  sumRecursive(numElements-1, intArray, sum, stk);
  *sum += intArray[numElements-1];
  
  //reset the parameters
  params[0] = numElements;
  params[1] = *sum;

  st_pop(stk, 2, params);
}

