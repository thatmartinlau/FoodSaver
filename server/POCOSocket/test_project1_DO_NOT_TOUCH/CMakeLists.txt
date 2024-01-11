cmake_minimum_required(VERSION 3.5)

project(test_project1_DO_NOT_TOUCH LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(rpclib-master)
include_directories(rpclib-master/include)

add_executable(test_project1_DO_NOT_TOUCH server_testing.cpp)


target_link_libraries(test_project1_DO_NOT_TOUCH PRIVATE rpc)


include(GNUInstallDirs)
install(TARGETS test_project1_DO_NOT_TOUCH
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


