#include <nebinAPI/nebin.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/write.hpp>

#if !defined(SERVER_HPP)
#define SERVER_HPP

namespace nebin {
namespace core{
class server_base{
protected:
  unsigned short default_port = 80;
  std::shared_ptr<boost::asio::io_context>base_io;
  boost::system::error_code boost_error_code;
  server_base(unsigned short port);

};

} // namespace server
} // namespace nebin

#endif
