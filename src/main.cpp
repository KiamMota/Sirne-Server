#include <Infra/BoostHttpIo.hh>

#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <iostream>

int main() {
  BoostHttpIo httpIo{};
  static int total_connections = 0;
  std::cout << "info : SS - (SIRNE Server) Kiam Mota (2025)." << std::endl;

  boost::asio::io_context IoContext;
  boost::asio::ip::tcp::endpoint MainEPoint{boost::asio::ip::tcp::v4(), 8080};
  boost::asio::ip::tcp::acceptor MainAcceptor{IoContext};
  boost::asio::ip::tcp::socket ClientSocket{IoContext};
  std::cout << "info : Sarting SS\n";

  MainAcceptor.open(MainEPoint.protocol());

  std::cout << "info : Open listener socket.\n";

  MainAcceptor.bind(MainEPoint);

  std::cout << "info : Bind with server endpoint.\n";

  MainAcceptor.listen();

  std::cout << "info : Listening.\n";

  boost::beast::flat_buffer RawBuffer;

  while (1) {
    boost::beast::http::request<boost::beast::http::string_body> RequestBody;

    MainAcceptor.accept(ClientSocket);
    httpIo.Read(ClientSocket, true);

    if (ClientSocket.is_open()) {
      ClientSocket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
      std::cout << "-> closed connection.\n";
      ClientSocket.close();
    }
  }

  return 0;
}
