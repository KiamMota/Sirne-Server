#include "Infra/HttpResponse.hh"
#include "Infra/IHttpResponse.hh"
#include <boost/beast/http/field.hpp>
#include <boost/beast/http/message_fwd.hpp>
#include <boost/system/detail/error_code.hpp>
#include <exception>
#include <iostream>

#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
int main() {
  static int total_connections = 0;
  std::cout << "info : SS - (SIRNE Server) Kiam Mota (2025)." << std::endl;

  boost::asio::io_context IoContext;
  boost::asio::ip::tcp::endpoint MainEPoint{boost::asio::ip::tcp::v4(), 8080};
  boost::asio::ip::tcp::acceptor MainAcceptor{IoContext};
  std::cout << "info : Setup server\n";

  MainAcceptor.open(MainEPoint.protocol());

  std::cout << "info : Open listener socket.\n";

  MainAcceptor.bind(MainEPoint);

  std::cout << "info : Bind with server endpoint.\n";

  MainAcceptor.listen();

  std::cout << "info : Listening.\n";
  std::cout << "info : Waiting connections.\n";

  boost::beast::flat_buffer RawBuffer;

  while (1) {
    boost::asio::ip::tcp::socket ClientSocket{IoContext};
    boost::beast::http::request<boost::beast::http::string_body> RequestBody;
    boost::system::error_code ec;
    boost::beast::http::response<boost::beast::http::string_body> Response;

    MainAcceptor.accept(ClientSocket);
    total_connections++;
    std::cout << "#" << total_connections << ": ";
    std::cout << "-> connection recieved. [" << ClientSocket.remote_endpoint()
              << "]" << std::endl;

    std::cout << "-> reading buffer." << std::endl;
    boost::beast::http::read(ClientSocket, RawBuffer, Response, ec);

    if (ec) {
      std::cerr << "error : " << ec.message() << std::endl;
      continue;
    }
    std::cout << "-> readed. " << std::endl;
    if (ClientSocket.is_open()) {
      ClientSocket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
      std::cout << "-> closed connection.\n";
      ClientSocket.close();
    }
  }

  return 0;
}
