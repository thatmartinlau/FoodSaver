cmake_minimum_required(VERSION 3.10)
project(app-release)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)
find_package(Qt6 6.2 COMPONENTS Quick Gui REQUIRED)
qt_standard_project_setup(REQUIRES 6.5)

include_directories(../../test3 Header Source ../../server/POCOSocket/Server/web_teste)
#add_subdirectory(../../test3 ../../test3)

add_subdirectory(../../server/POCOSocket/Server/web_teste/rpclib-master/ ../../server/POCOSocket/Server/web_teste/rpclib-master/)

# Add the source files



qt_add_resources(RESOURCES qml.qrc)
# Add an executable for the project using the specified source files
add_executable(${PROJECT_NAME} main.cpp
	Header/currentUser.h
	Header/fridgemanager.h
	Header/Login.h
	Header/profilemanager.h
#	Header/RecipeBook.h
	Header/settingsmanager.h
	Header/Signin.h
	Header/SigninInformation.h
	
	Source/currentUser.cpp
	Source/fridgemanager.cpp
	Source/Login.cpp
	Source/profilemanager.cpp
#	Source/RecipeBook.cpp
	Source/settingsmanager.cpp
	Source/Signin.cpp
	Source/SigninInformation.cpp
	Source/recipeconverter.cpp
	
	../../test3/date.h 
	../../test3/fridge.h 
	../../test3/ingredient.h
	../../test3/offer.h 
	../../test3/recipe.h 
	../../test3/user.h
	../../test3/main.cpp
	../../test3/date.cpp 
	../../test3/fridge.cpp
	../../test3/ingredient.cpp
	../../test3/offer.cpp
	../../test3/user.cpp
	../../test3/recipe.cpp
	
	../../server/POCOSocket/Server/web_teste/rpc_client_side.hpp
	../../server/POCOSocket/Server/web_teste/rpc_client_side.cpp
	
	qml.qrc
)

# Link the Qt5 libraries
target_link_libraries(app-release PRIVATE Qt6::Gui Qt6::Quick rpc)

include(GNUInstallDirs)
install(TARGETS app-release
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

