#include <nebinAPI/src/server/base/server_base.hpp>


namespace nebin{
    namespace core{
    server_base::server_base(unsigned short port)
    : base_io(std::make_shared<boost::asio::io_context>())
    {}
    }
}
