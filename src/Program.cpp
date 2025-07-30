#include "CrossCutting/Log.hh"
#include "Infra/IControllers.hh"
#include "Infra/Network/BoostConnection.hh"
#include "Infra/Network/BoostHttpIo.hh"

#include <CrossCutting/Log.hh>
#include <CrossCutting/Terminal.hh>

#include <iostream>

bool teste(std::string epoint) {
  std::cout << "a string passada eh: " << epoint << std::endl;
  return true;
}

int main() {

  Terminal::ClearScreen();
  BoostConnection boostCon;
  BoostHttpIo httpIo{};

  GLog->SLog("Stating server");
  boostCon.Start();

  std::cout << "info : " << "Listening on " << boostCon.GetAdress() << ":"
            << boostCon.GetPort() << std::endl;

  while (1) {
    boostCon.Run();

    httpIo.Read(boostCon.ClientSocket, true);
    if (httpIo.GetEndpoint() == "/api/cardapio") {
      GLog->SLog("Foo");
    }

    httpIo.RequestClear();

    if (boostCon.SocketIsOpen()) {
      boostCon.SocketClose();
    }
  }

  return 0;
}
