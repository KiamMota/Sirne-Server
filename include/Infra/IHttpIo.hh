#ifndef _IHTTPRESPONSE_H_
#define _IHTTPRESPONSE_H_

#include <boost/asio/ip/tcp.hpp>

class IHttpIo /* interface */ {
public:
  virtual bool Read(boost::asio::ip::tcp::socket &socket) = 0;
  virtual bool Send() = 0;
}; // namespace boost::asio::ip::tcp

#endif
