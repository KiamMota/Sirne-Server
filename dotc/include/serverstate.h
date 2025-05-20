

struct serverState {
  int state;
  char* protocol;
  int port;
};

struct serverState* init_serverState();
struct serverState* destroy_serverState(struct serverState* sv_state);
