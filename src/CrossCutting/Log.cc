#include "CrossCutting/Log.hh"

#include <iostream>
#include <stdio.h>

#define DEFAULT_COLORS() printf("\033[0m")
#define RED_COLOR() printf("\033[31m")
#define GREEN_COLOR() printf("\033[32m")
#define YELLOW_COLOR() printf("\033[33m")
#define MAGENTA_COLOR() printf("\033[35m")
#define CYAN_COLOR() printf("\033[36m")

LogSystem *GLog = LogSystem::GetInstance();

LogSystem *LogSystem::Instance = nullptr;

LogSystem::LogSystem() {}

LogSystem *LogSystem::GetInstance() {
  if (LogSystem::Instance == nullptr)
    LogSystem::Instance = new LogSystem{};
  return LogSystem::Instance;
}

LogSystem *LogSystem::InfoPush(std::string literalString) {
  LogInfos.push_back(literalString);
  return Instance;
}

LogSystem *LogSystem::InfoStart() {
  LogInfos.push_back("info : ");
  return LogSystem::Instance;
}

void LogSystem::InfoEnd() {
  for (auto item : LogInfos) {
    std::cout << item;
  }
  std::cout << std::endl;
  LogInfos.clear();
}

void LogSystem::SLog(const char *literalString) {
  std::cout << "info : " << literalString << std::endl;
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
  case THROWN:
    MAGENTA_COLOR();
    std::cout << "[THROWN]";
    DEFAULT_COLORS();
    break;
  case FALLBACK:
    CYAN_COLOR();
    std::cout << "[FALLBACK]";
    DEFAULT_COLORS();
    break;
  }
  std::cout << " : ";
  std::cout << literal_string;
  if (comment == 0) {
    std::cout << ".";
    std::cout << std::endl;
    return;
  }
  std::cout << " -> ";
  std::cout << "\"" << comment << ".\"" << std::endl;
}
