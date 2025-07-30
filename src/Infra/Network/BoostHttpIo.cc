#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/http/field.hpp>
#include <boost/beast/http/fields_fwd.hpp>
#include <boost/beast/http/string_body_fwd.hpp>

#include <iostream>

#include "CrossCutting/Log.hh"
#include "Infra/Network/BoostHttpIo.hh"
BoostHttpIo::BoostHttpIo() {}

void BoostHttpIo::ReadOutput() {
  std::cout << "[" << Request.method_string() << "]";
  std::cout << "  ";
  std::cout << "(" << Request[http::field::host] << ")";
  std::cout << " -> " << Request.target() << std::endl;
}

bool BoostHttpIo::Read(boost::asio::ip::tcp::socket &ClientSocket, bool Out) {
  boost::beast::http::read(ClientSocket, RawBuffer, Request, ErrorCode);
  if (ErrorCode) {
    GLog->Report(LogSystem::ERROR, "Error reading buffer",
                 ErrorCode.message().c_str());
    return false;
  }
  GLog->Report(LogSystem::OK, "Read buffer successfully", 0);
  if (Out)
    ReadOutput();
  return true;
}

void BoostHttpIo::RequestClean() { Request.clear(); }
std::string BoostHttpIo::GetWebEnpoint() { return Request.target(); }
