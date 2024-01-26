cmake_minimum_required(VERSION 3.10.2)
project(TELEGRAM_BOT)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(Boost_USE_MULTITHREADED ON)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(rpclib CONFIG REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})

file(GLOB TGBOT_CPP_LIB ./vcpkg/packages/tgbot-cpp*/lib/libTgBot.a)

add_executable(TELEGRAM_BOT telegram_bot.cpp)

#"-DCMAKE_TOOLCHAIN_FILE=/Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/vcpkg/scripts/buildsystems/vcpkg.cmake"

target_link_libraries(TELEGRAM_BOT path_to_your_library ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES})