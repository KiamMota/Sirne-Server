#include "server.h"
#include "uv.h"

struct serverState* init_serverState()
{
  struct serverState* sv_state = (struct serverState*)malloc(sizeof(struct serverState));
  sv_state->loop = (uv_loop_t *)malloc(sizeof(uv_loop_t));
  sv_state->port = 0;
  sv_state->protocol = "no protocol";
  return sv_state;
}

struct serverState* destroy_serverState(struct serverState* sv_state)
{
  if(sv_state) free(sv_state);
  sv_state = NULL;

  return sv_state;
}

