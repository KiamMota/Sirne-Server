#include "include/interpreter.hpp"
#include <cstring>
#include <string>

std::string HttpInterpreter::get_method(std::string string) {
  size_t space = string.find(" ");
  if (space != std::string::npos) {
    std::string method = string.substr(0, space);
    return method;
  }
  return "null";
}

std::string HttpInterpreter::get_host(std::string string) {
  size_t host_str = string.find("Host: ");
  if (host_str != std::string::npos) {
    host_str = host_str + 6;
    size_t real_host = string.find("\r\n", host_str);
    std::string ip = string.substr(host_str, real_host - host_str);
    return ip;
  }
  return "null";
}

std::string HttpInterpreter::get_header(std::string string) {
  size_t end_header = string.find("\r\n\r\n");
  if (end_header != std::string::npos) {
    std::string header = string.substr(0, end_header);
    return string.substr(0, end_header);
  }
  return "null";
}

std::string HttpInterpreter::get_json(std::string string) {
  size_t json_start = string.find("{");
  size_t json_end = string.find("}");
  if (json_start != std::string::npos)
    if (json_end != std::string::npos) {
      std::string json_body = string.substr(json_start, json_end - json_start + 1);
      return json_body;
    }
  return "null";
}

size_t HttpInterpreter::get_cnt_length(std::string str)
{
  size_t length = str.find("Content-Length: ");
  if(length != std::string::npos)
  {
  size_t end_lenght = str.find("\r\n", length);
  length += strlen("Content-Length: ");
  std::string str_length = str.substr(length, end_lenght - length);
  size_t real_length = std::stoi(str_length);
  return real_length;
  }
  return 0;
}

HttpInterpreter::Elements HttpInterpreter::interpretation(std::string& handle_string)
{
  HttpInterpreter http;
  Elements  RequestElements{};
  RequestElements.header = http.get_header(handle_string);
  RequestElements.method = http.get_method(RequestElements.header);
  RequestElements.host = http.get_host(RequestElements.header);
  RequestElements.content_length = http.get_cnt_length(RequestElements.header);
  if(RequestElements.content_length != 0)
    RequestElements.json_body = http.get_json(handle_string);
  return RequestElements;
}

HttpInterpreter::Elements HttpInterpreter::off_interpretation(Elements El)
{
  El.method.clear();
  El.header.clear();
  El.host.clear();
  El.json_body.clear();
  El.content_length = 0;

  return El;
}
