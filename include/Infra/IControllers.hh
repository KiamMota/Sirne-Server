#include <string>

#ifndef _CONTROLLERS_H_
#define _CONTROLLERS_H_

class IControllers {
public:
  static bool Dispatch(std::string endpoint);
};

#endif
