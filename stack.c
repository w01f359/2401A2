#include <stdio.h>
#include <string.h>

#include "stackDefs.h"

void st_init(StackType *stk)
{
  stk->numFrames = 0;
  stk->frames[MAX_FRAMES];
}

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

void st_push(StackType *stk, char *fname, int numP, int* paramArr)
{
  int addAt = stk->numFrames;
  int i;
  FrameType frame;
  strcpy(frame.funcName, fname);
  frame.numParams = numP;

  for(i = 0; i < numP; i++)
    frame.params[i] = paramArr[i];

  stk->frames[addAt] = frame;
  stk->numFrames++;

  st_dump(stk);


}

void st_pop(StackType *stk, int numP, int* paramArr)
{
  
  int i;
  for(i = 0; i < numP; i++)
    stk->frames[stk->numFrames-1].params[i] = paramArr[i];

  st_dump(stk);
  if(stk->numFrames > 0)
    stk->numFrames--;
}

