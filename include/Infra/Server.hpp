#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include <boost/asio/io_context.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio.hpp>

class	Server 
{	

private:
	boost::asio::io_context IoContext;
	boost::asio::ip::tcp::endpoint MainEPoint{boost::asio::ip::tcp::v4(), 8080};
	boost::asio::ip::tcp::socket MainSocket{IoContext};
	

public:


};

#endif
