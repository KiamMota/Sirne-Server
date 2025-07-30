#include "Infra/Terminal.hh"
#include <iostream>

#if defined(__unix__)
#include <termios.h>
#include <unistd.h>
#endif

void Terminal::DisableInput() {
#if defined(__unix__)
  struct termios CurrentTerm, NewTerm;
  tcgetattr(STDIN_FILENO, &CurrentTerm);
  CurrentTerm = NewTerm;
  NewTerm.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &NewTerm);
#endif
}

void Terminal::ClearScreen() { std::cout << "\033[3J\033[H\033[2J"; }
