cmake_minimum_required(VERSION 3.5)

project(Server_to_run_website LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(rpclib-master)
include_directories(rpclib-master/include)

add_executable(Server_to_run_website client_file.cpp
		common_characteristics.hpp	
)

target_link_directories(Server_to_run_website PRIVATE rpc)

include(GNUInstallDirs)
install(TARGETS Server_to_run_website
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
