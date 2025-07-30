#ifndef _TERMINAL_H_
#define _TERMINAL_H_

#include <termios.h>
class Terminal {
public:
  Terminal();
  static void ClearScreen();
  static void DisableInput();
};
#endif
