#include <Infra/BoostHttpIo.hh>

#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <iostream>

int main() {
  BoostHttpIo httpIo{};
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

    MainAcceptor.accept(ClientSocket);

    httpIo.Read(ClientSocket, true);

    if (ClientSocket.is_open()) {
      ClientSocket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
      std::cout << "[FINALIZADO]" << std::endl;
      ClientSocket.close();
    }
  }

  return 0;
}
