#include "Infra/IControllers.hh"

bool IControllers::Dispatch(std::string endpoint) {
  if (endpoint.empty())
    return false;
  return true;
}
