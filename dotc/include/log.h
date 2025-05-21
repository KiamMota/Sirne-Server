#include "defines.h"
#include <stdio.h>
#include <stdlib.h>

#if !defined(LOG_H)
#define LOG_H

struct logState{
  FILE* fptr;
  const char* file_name;
  int line;
  int offset;
  int cursor_position;
};

struct logState* init_logState(const char* fname);
struct logState* destroy_logState(struct logState* log_state);
int writen(struct logState* log_state, const char* write);
int write(struct logState* log_state, const char* write);

int log_close(struct logState* log_state);

#endif
