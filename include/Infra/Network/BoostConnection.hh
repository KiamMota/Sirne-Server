#ifndef _BOOSTCONNECTION_H_
#define _BOOSTCONNECTION_H_

#include <boost/asio/detail/epoll_reactor.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/basic_endpoint.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/system/detail/error_code.hpp>

namespace ip = boost::asio::ip;

class BoostConnection {
private:
  boost::asio::io_context IoContext;
  boost::system::error_code MainErrorClass;

  ip::tcp Adress = ip::tcp::v4();
  ip::port_type Port = 8080;

  ip::tcp::endpoint MainEPoint{Adress, Port};
  ip::tcp::acceptor MainAcceptor{IoContext};

public:
  BoostConnection();

  ip::tcp::socket ClientSocket{IoContext};

  ip::tcp::socket GetClientSocket();
  ip::address GetAdress();
  ip::port_type GetPort();

  std::string GetEndpoint();
  void Start();
  void Run();

  void Open();
  void Bind();
  void Listen();

  void SocketOpen();
  bool SocketIsOpen();
  void SocketClose();
};

#endif
