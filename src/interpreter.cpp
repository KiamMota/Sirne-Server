#include "include/interpreter.hpp"
#include <cstddef>
#include <string>

std::string json_interpreter::get_method(std::string string) {
  size_t space = string.find(" ");
  if (space != std::string::npos) {
    std::string method = string.substr(0, space);
    ReqElements.method = method;
    return method;
  }
  return ReqElements.null;
}

std::string json_interpreter::get_host(std::string string) {
  size_t host_str = string.find("Host: ");
  if (host_str != std::string::npos) {
    host_str = host_str + 6;
    size_t real_host = string.find("\r\n", host_str);
    std::string ip = string.substr(host_str, real_host - host_str);
    ReqElements.host = ip;
    return ip;
  }
  return ReqElements.null;
}

std::string json_interpreter::get_header(std::string string) {
  size_t end_header = string.find("\r\n\r\n");
  if (end_header != std::string::npos) {
    std::string header = string.substr(0, end_header);
    ReqElements.header = header;
  }
  return ReqElements.null;
}

std::string json_interpreter::get_json(std::string string) {
  size_t json_start = string.find("{");
  size_t json_end = string.find("}");
  if (json_start != std::string::npos)
    if (json_end != std::string::npos) {
      std::string json_body = string.substr(json_start, json_end - json_start + 1);
      ReqElements.json_body = json_body;
      return json_body;
    }

  return ReqElements.null;
}
