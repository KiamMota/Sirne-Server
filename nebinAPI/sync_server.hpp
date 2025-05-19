#include <nebinAPI/src/server/base/server_base.hpp>

#if !defined(SYNC_SERVER)
#define SYNC_SERVER

namespace nebin {
  namespace server {
    class sync_server : protected core::server_base 
      {
      protected:
        boost::asio::ip::tcp::socket sync_socket{*base_io};
        boost::asio::streambuf client_streambuff;
        boost::asio::streambuf server_streambuff;
        boost::asio::ip::tcp::endpoint sync_endpoint{boost::asio::ip::tcp::v4(), default_port};
        boost::asio::ip::tcp::acceptor sync_acceptor{*base_io};
        void clear_server_buffer();
      private:              

      public: 

        sync_server(unsigned short port = 80);
        /*start*/
        void open();
        void accept();
        void close();
        void listen();
        /*formatation*/
        void server_const_message(std::string message);
        void get_client_string(std::string handle_string, const char* delim);
        void clear_client_buffer();

    };
  }
} 


#endif
