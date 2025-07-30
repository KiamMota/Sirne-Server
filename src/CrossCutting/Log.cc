#include "CrossCutting/Log.hh"

#include <iostream>
#include <stdio.h>

#define DEFAULT_COLORS() printf("\033[0m")
#define RED_COLOR() printf("\033[31m")
#define GREEN_COLOR() printf("\033[32m")
#define YELLOW_COLOR() printf("\033[33m")
#define MAGENTA_COLOR() printf("\033[35m")

void LogSystem::LogInfo(const char *literalString) {
  std::cout << "info";
  std::cout << " : ";
  std::cout << "\"" << literalString << "\".";
  std::cout << std::endl;
}

void LogSystem::Report(FLAG flag, const char *literal_string,
                       const char *comment) {

  switch (flag) {
  default:
    std::cout << "[UNCANNY]";
    break;
  case OK:
    GREEN_COLOR();
    std::cout << "[OK]";
    DEFAULT_COLORS();
    break;
  case WARNING:
    YELLOW_COLOR();
    std::cout << "[WARNING]";
    DEFAULT_COLORS();
    break;
  case ERROR:
    RED_COLOR();
    std::cout << "[ERROR]";
    DEFAULT_COLORS();
    break;
  case THROWED:
    MAGENTA_COLOR();
    std::cout << "[THROWED]";
    DEFAULT_COLORS();
    break;
  }
  std::cout << " : ";
  std::cout << literal_string;
  if (comment == 0) {
    std::cout << ".";
    return;
  }
  std::cout << " : ";
  std::cout << "\"" << comment << ".\"" << std::endl;
}
