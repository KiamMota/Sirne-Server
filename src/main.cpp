#include <iostream>

#include <boost/asio/io_context.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio.hpp>

int main()
{
	std::cout << "info : SS - (SIRNE Server) Kiam Mota (2025)." << std::endl; 
		
	boost::asio::io_context IoContext;
	boost::asio::ip::tcp::endpoint MainEPoint{boost::asio::ip::tcp::v4(), 8080};
	boost::asio::ip::tcp::acceptor MainAcceptor{IoContext};

	std::cout << "info : Setup server\n"; 

	MainAcceptor.open(MainEPoint.protocol());

	std::cout << "info : Open listener socket.\n";

	MainAcceptor.bind(MainEPoint);

	std::cout << "info : Bind with server endpoint.\n";
	
	MainAcceptor.listen();

	std::cout << "info : Listening.\n";
	std::cout << "info : Waiting connections.\n";

	boost::beast::flat_buffer RawBuffer;
	boost::beast::http::request<boost::beast::http::string_body> RequestBody;

	while(1)
	{	
		boost::asio::ip::tcp::socket ClientSocket{IoContext};

		MainAcceptor.accept(ClientSocket);
		
		std::cout << "-> connection recieved. [" << ClientSocket.remote_endpoint() << "]\n";
		ClientSocket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
		std::cout << "-> closed connection.\n";
		ClientSocket.close();
	}


	return 0;
}
