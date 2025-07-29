#include "Infra/BoostHttpIo.hh"
#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/http/string_body_fwd.hpp>

bool BoostHttpIo::Read(boost::asio::ip::tcp::socket &ClientSocket) {
  boost::beast::http::read(ClientSocket, RawBuffer, Response, ErrorCode);
  if (ErrorCode)
    return false;
  return true;
}
