cmake_minimum_required(VERSION 3.11)

project(ss VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(START src/Program.cpp)

set(CROSSCUTTING_SRC
  src/CrossCutting/Log.cc
  src/CrossCutting/Terminal.cc
)

set(NETWORK_SRC 
  src/Infra/Network/BoostHttpIo.cc
  src/Infra/Network/BoostConnection.cc
)
set(INFRA
  ${NETWORK_SRC}
  ${CROSSCUTTING_SRC}
)

add_executable(${PROJECT_NAME} ${INFRA} ${START})
include_directories(include)
