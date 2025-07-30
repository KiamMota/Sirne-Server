#ifndef _LOG_H_
#define _LOG_H_

#include <iostream>
#include <queue>
#include <stack>

class LogSystem {
private:
  LogSystem();
  static LogSystem *Instance;
  std::vector<std::string> LogInfos;

public:
  static LogSystem *GetInstance();
  enum FLAG : short { OK = 1, WARNING, ERROR, FATAL_ERROR, THROWN };
  void Report(FLAG flag, const char *literalString, const char *comment);
  void SLog(const char *literalString);
  LogSystem *InfoStart();
  LogSystem *InfoPush(std::string literalString);
  void InfoEnd();
};

extern LogSystem *GLog;

#endif
