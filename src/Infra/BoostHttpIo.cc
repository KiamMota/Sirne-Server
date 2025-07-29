#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/http/field.hpp>
#include <boost/beast/http/string_body_fwd.hpp>

#include <iostream>

#include "Infra/BoostHttpIo.hh"
BoostHttpIo::BoostHttpIo() {}

void BoostHttpIo::ReadOutput() {
  std::cout << "[" << Request.method_string() << "]";
  std::cout << "  ";
  std::cout << "(" << Request[http::field::host] << ")";
  std::cout << " -> " << Request.target();
}

bool BoostHttpIo::Read(boost::asio::ip::tcp::socket &ClientSocket, bool Out) {
  boost::beast::http::read(ClientSocket, RawBuffer, Request, ErrorCode);
  if (Out)
    ReadOutput();
  if (ErrorCode)
    std::cout << "READ ERROR : " << ErrorCode.message() << std::endl;
  return false;

  return true;
}
 
   
  

