#include <cstddef>
#include <string>

#if !defined(_INTERPRETER_HPP_)
#define _INTERPRETER_HPP_
class HttpInterpreter{ 
  public:
  struct Elements
  {
    std::string null;
    std::string method;
    std::string host;
    std::string header;
    std::string json_body;
    size_t content_length; 
    Elements()
    {
      null = "null";
      method = null;
      host = null;
      header = null;
      json_body = null;
      content_length = 0;
    }
  };

  static Elements interpretation(std::string& handle_string);
  static Elements off_interpretation(Elements El);
    std::string get_method(std::string string);
    std::string get_host(std::string string);
    std::string get_header(std::string string);
    std::string get_json(std::string string);
    size_t get_cnt_length(std::string string);
  
};

class JsonInterpreter{
  public:
    


  private:

  



  
};



#endif
