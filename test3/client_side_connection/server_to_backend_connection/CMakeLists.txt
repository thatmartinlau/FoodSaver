cmake_minimum_required(VERSION 3.5)

project(server_to_backend_connection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server_to_backend_connection rpc_client_side.cpp
	rpc_client_side.hpp
	
)


add_subdirectory(rpclib-master)
include_directories(rpclib-master/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../test3)

target_link_libraries(server_to_backend_connection PRIVATE rpc)

include(GNUInstallDirs)
install(TARGETS server_to_backend_connection
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
