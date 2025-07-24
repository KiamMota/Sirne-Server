
#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast.hpp>
#include <boost/beast/core/tcp_stream.hpp>

namespace basio = boost::asio;
namespace bsys = boost::system;
using tcp = boost::asio::ip::tcp;

class	Server 
{	
private:
	basio::io_context io_c{};
	tcp::acceptor accept{io_c, basio::ip::tcp::v4(), 7192};
	bsys::error_code ec{};	
public:


};

#endif
