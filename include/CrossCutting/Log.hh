#ifndef _LOG_H_
#define _LOG_H_

class LogSystem {
private:
public:
  enum FLAG : short { OK = 1, WARNING, ERROR, FATAL_ERROR, THROWED };
  static void Report(FLAG flag, const char *literalString, const char *comment);
  static void LogInfo(const char *literalString);
};

#endif
