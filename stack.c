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
  FrameType frame;
  strcpy(frame.funcName, fname);
  frame.numParams = numP;
  frame.params[0] = paramArr[0];
  frame.params[1] = paramArr[1];

  stk->frames[addAt] = frame;
  stk->numFrames++;


}

void st_pop(StackType *stk, int numP, int* paramArr)
{


  st_dump(stk);
}

