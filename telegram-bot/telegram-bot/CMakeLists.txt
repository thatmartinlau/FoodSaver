cmake_minimum_required(VERSION 3.10.2)
project(TELEGRAM_BOT)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(Boost_USE_MULTITHREADED ON)

add_subdirectory(rpclib-master)
include_directories(rpclib-master/include)
add_subdirectory(tgbot-cpp-1.7.2)
include_directories(tgbot-cpp-1.7.2/include)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})

add_executable(TELEGRAM_BOT telegram_bot.cpp)

target_link_libraries(TELEGRAM_BOT tgbot-cpp ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(TELEGRAM_BOT PRIVATE rpc)