#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/http/field.hpp>
#include <boost/beast/http/string_body_fwd.hpp>

#include <iostream>

#include "Infra/Network/BoostHttpIo.hh"
BoostHttpIo::BoostHttpIo() {}

void BoostHttpIo::ReadOutput() {
  std::cout << "[" << Request.method_string() << "]";
  std::cout << "  ";
  std::cout << "(" << Request[http::field::host] << ")";
  std::cout << " -> " << Request.target() << std::endl;
  std::cout << Request.body();
}

bool BoostHttpIo::Read(boost::asio::ip::tcp::socket &ClientSocket, bool Out) {
  boost::beast::http::read(ClientSocket, RawBuffer, Request, ErrorCode);
  if (ErrorCode)
    std::cout << "READ ERROR : " << ErrorCode.message() << std::endl;
  return false;
  if (Out)
    ReadOutput();
  return true;
}

void BoostHttpIo::RequestClean() { Request.clear(); }
std::string BoostHttpIo::GetWebEnpoint() { return Request.target(); }
