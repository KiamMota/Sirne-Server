#include "Infra/IHttpIo.hh"
#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/http/string_body_fwd.hpp>

namespace http = boost::beast::http;

class BoostHttpIo : IHttpIo {
private:
  boost::system::error_code ErrorCode;
  boost::beast::http::response<boost::beast::http::string_body> Response;
  boost::beast::flat_buffer RawBuffer;
  http::response<boost::beast::http::string_body> Ok{};
  http::response<boost::beast::http::string_body> NotFound{};
  http::request<boost::beast::http::string_body> NotAllowed{};

public:
  BoostHttpIo();
  bool Read(boost::asio::ip::tcp::socket &ClientSocket);
};
