#include "log.h"
#include <stdio.h>

struct logState *init_logState(const char *fname) {
  struct logState *log_state =
      (struct logState *)malloc(sizeof(struct logState));
  { 
    log_state->fptr = fopen(fname, "a");
    log_state->file_name = fname;
    log_state->line = 0;
    log_state->offset = 0;
    log_state->cursor_position = SEEK_SET;
  }
  return log_state;
}

struct logState *destroy_logState(struct logState *log_state) {
  if (log_state)
    free(log_state);
  return log_state;
}

int writen(struct logState *log_state, const char *write) {
  if (log_state->fptr == NULL) return -1;
  fputs(write, log_state->fptr);
  fputs("\n", log_state->fptr);
  log_state->line += 1;
  log_state->cursor_position = ftell(log_state->fptr);
  return 0;
}

int write(struct logState* log_state, const char* write)
{
  log_state->fptr = fopen(log_state->file_name, "a");
  if(log_state->fptr) return -1;
  fputs(write, log_state->fptr);
  log_state->line +=1;
  return 0;
}

int close_log(struct logState* log_state)
{
  if (log_state->fptr) {
  fclose(log_state->fptr);
    return 0;
  }
  return -1;
}
  

