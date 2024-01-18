cmake_minimum_required(VERSION 3.14)

project(web_teste LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_subdirectory(rpclib-master/)
include_directories(rpclib-master/include)


add_executable(web_teste
  main.cpp
  common_characteristics.hpp
)


target_link_libraries(web_teste Qt${QT_VERSION_MAJOR}::Core rpc)

include(GNUInstallDirs)
install(TARGETS web_teste
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
