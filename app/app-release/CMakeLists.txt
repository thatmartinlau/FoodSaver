cmake_minimum_required(VERSION 3.5)

project(app-release LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick Gui REQUIRED)
qt_standard_project_setup(REQUIRES 6.5)


add_executable(app-release main.cpp
		


)

target_link_libraries(app-release PRIVATE Qt6::Gui Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS app-release
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
