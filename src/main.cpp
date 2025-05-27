#include "nebinAPI/sync_server.hpp"
#include "include/interpreter.hpp"
#include <string>

int main() {
    nebin::server::sync_server server{};
    server.open();
    server.listen();


int code = 0;  
std::string OK = "{ \"resposte\": \"ok, my friend\" }";



std::string CORS = 
  "HTTP/1.1 "+ std::to_string(code) + "\r\n"
  "Content-Type: application/json\r\n"
  "Access-Control-Allow-Origin: *\r\n"
  "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
  "Access-Control-Allow-Headers: Content-Type\r\n"
  "Content-Length: " + std::to_string(OK.size()) + "\r\n\r\n";

    std::string handle_string = "nulinho";

HttpInterpreter::Elements Elements;

  std::string foo = "------>";

    while(1)
    {
        server.accept();
        server.get_client_string(handle_string);
        std::cout << handle_string << std::endl;
  Elements = HttpInterpreter::interpretation(handle_string);
      std::cout << foo << Elements.method << std::endl;
      std::cout << foo << Elements.host << std::endl;
      std::cout << foo << Elements.content_length << std::endl;
      std::cout << foo << Elements.header << std::endl;
    Elements = HttpInterpreter::off_interpretation(Elements);
    server.close();
     
    }


    
    return 0;  
}
