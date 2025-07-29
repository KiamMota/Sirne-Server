#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/http/message_fwd.hpp>
#include <boost/beast/http/string_body_fwd.hpp>

#ifndef _BOOST_HTTP_H_
#define _BOOST_HTTP_H_

namespace http = boost::beast::http;

class BoostHttpIo {
private:
  boost::system::error_code ErrorCode;
  boost::beast::flat_buffer RawBuffer;
  http::request<http::string_body> Request;
  boost::beast::http::response<boost::beast::http::string_body> Response;
  http::response<boost::beast::http::string_body> Ok{};
  http::response<boost::beast::http::string_body> NotFound{};
  http::request<boost::beast::http::string_body> NotAllowed{};

  void ReadOutput();

public:
  BoostHttpIo();

  bool Read(boost::asio::ip::tcp::socket &ClientSocket, bool Out);
};

#endif
