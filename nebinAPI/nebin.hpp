#include <boost/asio/ip/tcp.hpp>
#include <fstream>
#include <memory>
#include <iostream>


#define LOG_ERROR(num, literal_string) std::cout << "NB ERR ~[" << num << "]: " << #literal_string << std::endl;
#define NEBINVER "[nb: dev-0.20]"
#define DEBUG 

#ifdef DEBUG 
#define CEBUG(literal_string) std::cout << NEBINVER << " DEBUG: " << #literal_string << std::endl 
#endif
#if !defined(NEBIN_HPP)
#define NEBIN_HPP


#define _TC_DEFAULT "\033[37m"
#define _TC_GREEN "\033[32m"
#define _TC_YELLOW "\033[33m"
#define _TC_RED "\033[31m"

namespace nebin {
namespace core {

}; // namespace core
} // namespace nebin
#endif
