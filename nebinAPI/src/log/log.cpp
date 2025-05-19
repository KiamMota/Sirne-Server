#include <cstdio>
#include <cstring>
#include <nebinAPI/log.hpp>

namespace nebin {
namespace log {
int File::write(const char *string, short break_line) {
  file = fopen(file_name, "a");
  if (!fopen(file_name, "a"))
    return -1;
  fwrite(string, strlen(string), 1, file);
  if (break_line == 1)
    fwrite("\n", 2, 1, file);
  if (break_line >= 2) {
    for (int i = 0; i < break_line; i++)
      fwrite("\n", 1, 1, file);
  }
  fflush(file);
  fclose(file);
  return 0;
}

void File::rename(const char *new_name) {
  ::rename(file_name, new_name);
  if (file_name)
    delete[] file_name;
  file_name = new char[strlen(new_name)];
  strcpy(file_name, new_name);
}

} // namespace log
} // namespace nebin
