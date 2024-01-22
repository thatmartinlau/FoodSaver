cmake_minimum_required(VERSION 3.5)

project(test3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(../server/POCOSocket/Server/web_teste ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(../server/POCOSocket/Server/web_teste)

add_executable(test3	main.cpp
			date.cpp 
			fridge.cpp
			front.cpp
			ingredient.cpp
			main.cpp
			offer.cpp
			recipe.cpp
			user.cpp
			
			date.h 
		        fridge.h 
		        front.hpp 
		        ingredient.h
		        offer.h 
		        recipe.h 
		        user.h

)

#target_link_libraries(test3 PRIVATE web_teste)

include(GNUInstallDirs)
install(TARGETS test3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
