#define MAX_FRAMES    32
#define MAX_PARAMS     8
#define MAX_ARR_SIZE  16
#define MAX_STR       32
#define C_OK           0
#define C_NOK         -1

typedef struct {
  char funcName[MAX_STR];
  int  numParams;
  int  params[MAX_PARAMS];
} FrameType;

typedef struct {
  int numFrames;
  FrameType frames[MAX_FRAMES];
} StackType;

/*  Stack functions  */
void st_init(StackType*);
void st_push(StackType*, char*, int, int*);
void st_pop(StackType*, int, int*);
void st_dump(StackType*);

/*  Loop functions  */
void sumIterative(int, int*, int*, StackType*);
void sumRecursive(int, int*, int*, StackType*);

