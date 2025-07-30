#include "CrossCutting/Log.hh"
#include "Infra/Network/BoostConnection.hh"
#include "Infra/Network/BoostHttpIo.hh"

#include <CrossCutting/Log.hh>
#include <CrossCutting/Terminal.hh>

#include <iostream>

int main() {
  Terminal::ClearScreen();
  BoostConnection boostCon;
  BoostHttpIo httpIo{};

  boostCon.Start();

  std::cout << "info : " << "Listening on " << boostCon.GetAdress() << ":"
            << boostCon.GetPort() << std::endl;

  while (1) {
    boostCon.Run();

    httpIo.Read(boostCon.ClientSocket, true);
    if (httpIo.GetWebEnpoint() == "/api/test") {
    }
    if (boostCon.SocketIsOpen()) {
      boostCon.SocketClose();
    }
  }

  return 0;
}
