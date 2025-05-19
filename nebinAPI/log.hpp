#include <cstring>
#include <stdio.h>

#if !defined(LOG_HPP)
#define LOG_HPP
namespace nebin {
namespace log {
class File {
private:
  FILE *file;
  char *file_name;

public:
  File(const char *file_name) {
    this->file_name = new char[strlen(file_name)];
    strcpy(this->file_name, file_name);
  }
  void rename(const char *new_name);
  int write(const char *string, short break_line = 1);
  int erase(const char *erase);
};
} // namespace log
} // namespace nebin
#endif
