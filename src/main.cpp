#include <Infra/BoostConnection.hh>
#include <Infra/BoostHttpIo.hh>
#include <Infra/Terminal.hh>

#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/basic_endpoint.hpp>
#include <boost/system/detail/error_code.hpp>
#include <iostream>

int main() {
  Terminal::ClearScreen();

  BoostConnection boostCon{};
  BoostHttpIo httpIo{};

  std::cout << "info : SS - (SIRNE Server) Kiam Mota (2025)." << std::endl;

  boostCon.Start();

  std::cout << "info : Listening in " << boostCon.GetAdress() << ":"
            << boostCon.GetPort() << std::endl;

  while (1) {
    boostCon.Run();
    httpIo.Read(boostCon.ClientSocket, true);

    std::cout << "[FINALIZADO]" << std::endl;
    if (boostCon.SocketIsOpen()) {
      std::cout << "-- Socket closed." << std::endl;
      boostCon.SocketClose();
    }
  }

  return 0;
}
