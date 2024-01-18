cmake_minimum_required(VERSION 3.5)

project(Server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(rpclib-master)
include_directories(rpclib-master/include)

include_directories(../../../test3)


add_executable(Server rpc_server_side.cpp
	rpc_client_side_tester_file.cpp
	rpc_client_side_tester_file.hpp
	common_characteristics.hpp
	
	../../../test3/user.cpp
	../../../test3/fridge.cpp
	../../../test3/front.cpp
	../../../test3/ingredient.cpp
	../../../test3/date.cpp
	../../../test3/offer.cpp	
	
	
)

target_link_libraries(Server PRIVATE rpc)

include(GNUInstallDirs)
install(TARGETS Server
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
