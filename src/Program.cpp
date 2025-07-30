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

  LogSystem::Report(LogSystem::OK, "SIRNE Server API (SSA). Kiam Mota 2025.",
                    "Starting Application");
  boostCon.Start();

  std::cout << "info : Listening in " << boostCon.GetAdress() << ":"
            << boostCon.GetPort() << std::endl;

  while (1) {
    boostCon.Run();

    httpIo.Read(boostCon.ClientSocket, true);
    if (httpIo.GetWebEnpoint() == "/api/test") {
    }
    if (boostCon.SocketIsOpen()) {
      LogSystem::Report(LogSystem::OK, "Closed Socket", 0);
      boostCon.SocketClose();
    }
  }

  return 0;
}
