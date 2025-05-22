#include "nebinAPI/log.hpp"
#include "nebinAPI/sync_server.hpp"
#include "include/interpreter.hpp"
int main() {
    nebin::server::sync_server server{};
    server.open();
    server.listen();
    std::string handle_string;
    
    while(1)
    {
        server.accept();
        server.server_const_message("conected");    
        server.get_client_string(handle_string, "\r\n\r\n");
        
    
    }


    
    return 0;  
}
