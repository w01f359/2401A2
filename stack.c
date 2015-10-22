#include <stdio.h>
#include <string.h>
#include "stackDefs.h"

/*
  function: st_init
  purpose:  initialize the stack
  out:      *stk - the stack to initialize
*/
void st_init(StackType *stk)
{
  stk->numFrames = 0;
  stk->frames[MAX_FRAMES];
}

/*
  function: st_dump
  purpose:  dump(print) the stack (all the frames)
  in:       *stk - the stack to dump(print)
*/
void st_dump(StackType *stk)
{
  int i, j, k;

  printf("     -- STACK --\n");

  for (i=0; i<stk->numFrames; ++i) {
    printf("     ---- FRAME #%d:  %s \n", i, 
             stk->frames[i].funcName);

    for (j=0; j<stk->frames[i].numParams; j++) {
      printf("     ------ param %d: %4d \n", j, stk->frames[i].params[j]);
    }
  }
  printf("     -- END OF STACK --\n\n");
}

/*
  function: st_push
  purpose:  add a frame to the stack
  in/out:   *stk - the stack to be added to
  in:       *fname - the function name
  in:       numP - the number of parameters
  in:      *paramArr - the array of parameters (numbers to be summed, and the sum)
*/
void st_push(StackType *stk, char *fname, int numP, int* paramArr)
{
  int i;
  FrameType frame;
  strcpy(frame.funcName, fname);
  frame.numParams = numP;

  for(i = 0; i < numP; i++)
    frame.params[i] = paramArr[i];

  stk->frames[stk->numFrames] = frame;
  stk->numFrames++;

  st_dump(stk);
}

/*
  function: st_pop
  purpose:  remove a frame from the stack
  in/out:   *stk - the stack to be removed from
  in:       numP - the number of parameters
  in:       *paramArr - the array of parameters (numbers to be summed, and the sum)
*/
void st_pop(StackType *stk, int numP, int* paramArr)
{ 
  int i;
  for(i = 0; i < numP; i++)
    stk->frames[stk->numFrames-1].params[i] = paramArr[i];

  st_dump(stk);
  
  if(stk->numFrames > 0)
    stk->numFrames--;
}

