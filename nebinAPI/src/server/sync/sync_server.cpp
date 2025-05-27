#include <boost/asio/buffer.hpp>
#include <boost/asio/socket_base.hpp>
#include <boost/system/detail/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <nebinAPI/src/server/base/server_base.hpp>

#include <nebinAPI/sync_server.hpp>

namespace nebin {
namespace server {

sync_server::sync_server(unsigned short sync_port) : core::server_base(sync_port) {}

void sync_server::clear_client_buffer() {
  if (client_streambuff.size() != 0)
    client_streambuff.consume(client_streambuff.size());
  else
    return;
}

void sync_server::clear_server_buffer() {
  if (server_streambuff.size() != 0)
    server_streambuff.consume(server_streambuff.size());
  else
    return;
}

void sync_server::open() {
  try{
  sync_acceptor.open(sync_endpoint.protocol());
  sync_acceptor.bind(sync_endpoint);
  sync_acceptor.set_option(boost::asio::socket_base::reuse_address(true));
  }catch(boost::system::error_code)
  {
    std::cout << "porta: " << sync_endpoint.port() << "deve-se ter elevação para abrir o executável" <<  std::endl;
  }
}

void sync_server::listen() { sync_acceptor.listen(); }

void sync_server::accept() { sync_acceptor.accept(sync_socket); }

void sync_server::close() { sync_socket.close(); }

void sync_server::server_const_message(std::string message) {
  if (message.size() == 0)
    return;
  std::ostream message_str(&server_streambuff);
  message_str << message << std::endl;
  boost::asio::write(sync_socket, server_streambuff);
  clear_server_buffer();
}

void sync_server::get_client_string(std::string& handle_string, const char* delim ) {
    char buffer[1024];
      try{
      auto buf  = boost::asio::buffer(buffer, sizeof(buffer));
      size_t n = sync_socket.read_some(buf);
      handle_string.assign(buffer, n);
      }catch(boost::system::system_error& a)
      {
        std::cout << "erro de leitura" << std::endl;
        return;
      }
      }

} // namespace server
} // namespace nebin
