#include <nebinAPI/database/mariadb.hpp>

#if !defined(_INTERPRETER_HPP_)
#define _INTERPRETER_HPP_
class json_interpreter{ 
  private:  
  struct req_elements
  {
    req_elements() : null(""){}
    std::string null;
    std::string method;
    std::string host;
    std::string header;
    std::string json_body; 
  };
  public:
  req_elements ReqElements;
    std::string get_method(std::string string);
    std::string get_host(std::string string);
    std::string get_header(std::string string);
    std::string get_json(std::string string);
  
};



#endif
