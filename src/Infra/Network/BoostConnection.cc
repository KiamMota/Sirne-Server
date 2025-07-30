#include <Infra/Network/BoostConnection.hh>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/basic_endpoint.hpp>
#include <boost/system/detail/error_code.hpp>

#include "CrossCutting/Log.hh"

#include <iostream>

BoostConnection::BoostConnection() {}

void BoostConnection::Open() {
  try {
    MainAcceptor.open(MainEPoint.protocol(), MainErrorClass);
    if (MainErrorClass)
      throw MainErrorClass;
  } catch (const boost::system::error_code &Error) {

    std::cout << MainErrorClass.message();
  }
}

void BoostConnection::Bind() {
  try {
    MainAcceptor.bind(MainEPoint, MainErrorClass);
    if (MainErrorClass)
      throw MainErrorClass;
  } catch (boost::system::error_code &Ec) {
    Port++;
    MainEPoint.port(Port);
    MainAcceptor.bind(MainEPoint, MainErrorClass);
    if (!MainErrorClass)
      return;
    exit(-1);
  }
}

void BoostConnection::Listen() { MainAcceptor.listen(); }

void BoostConnection::Start() {
  Open();
  Bind();
  Listen();
}

void BoostConnection::SocketOpen() {
  ClientSocket.open(boost::asio::ip::tcp::v4());
}
void BoostConnection::Run() { MainAcceptor.accept(ClientSocket); }
bool BoostConnection::SocketIsOpen() { return ClientSocket.is_open(); }
void BoostConnection::SocketClose() {
  ClientSocket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
  ClientSocket.close();
}

boost::asio::ip::address BoostConnection::GetAdress() {
  return MainEPoint.address();
}
boost::asio::ip::port_type BoostConnection::GetPort() {
  return MainEPoint.port();
}
