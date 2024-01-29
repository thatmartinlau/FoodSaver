cmake_minimum_required(VERSION 3.10)
project(app-release)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick Gui REQUIRED)
qt_standard_project_setup(REQUIRES 6.5)


# Add the source files
set(SOURCES
    Source/fridgemanager.cpp
    Source/RecipeBook.cpp
    Source/recipe.cpp
    Source/recipeconverter.cpp
    main.cpp
    Source/date.cpp
    Source/fridge.cpp
    Source/front.cpp
    Source/ingredient.cpp
    Source/link_pocco.cpp
    Source/Login.cpp
    Source/offer.cpp
    # Add other source files here
)

# Add an executable for the project using the specified source files
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the Qt5 libraries
target_link_libraries(app-release PRIVATE Qt6::Gui Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS app-release
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

