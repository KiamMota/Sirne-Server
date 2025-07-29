#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include "Infra/IHttpResponse.hh"
#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/http/status.hpp>

namespace http = boost::beast::http;

class HttpReponse : IHttpResponse {
private:
  http::response<boost::beast::http::string_body> Ok{};
  http::response<boost::beast::http::string_body> NotFound{};
  http::request<boost::beast::http::string_body> NotAllowed{};

public:
  HttpReponse();
};

#endif
