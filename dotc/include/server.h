#include <stdlib.h>
#include <uv.h>

#if !defined(SERVERSTATE_H)
#define SERVERSTATE_H

struct serverState {
  uv_loop_t* loop;
  char* protocol;
  int port;
};

struct serverState* init_serverState();
struct serverState* destroy_serverState(struct serverState* sv_state);



#endif
