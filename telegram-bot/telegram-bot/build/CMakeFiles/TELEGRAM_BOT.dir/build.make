# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/build

# Include any dependencies generated for this target.
include CMakeFiles/TELEGRAM_BOT.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TELEGRAM_BOT.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TELEGRAM_BOT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TELEGRAM_BOT.dir/flags.make

CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.o: CMakeFiles/TELEGRAM_BOT.dir/flags.make
CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.o: /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/telegram_bot.cpp
CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.o: CMakeFiles/TELEGRAM_BOT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.o -MF CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.o.d -o CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.o -c /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/telegram_bot.cpp

CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/telegram_bot.cpp > CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.i

CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/telegram_bot.cpp -o CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.s

# Object files for target TELEGRAM_BOT
TELEGRAM_BOT_OBJECTS = \
"CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.o"

# External object files for target TELEGRAM_BOT
TELEGRAM_BOT_EXTERNAL_OBJECTS =

TELEGRAM_BOT: CMakeFiles/TELEGRAM_BOT.dir/telegram_bot.cpp.o
TELEGRAM_BOT: CMakeFiles/TELEGRAM_BOT.dir/build.make
TELEGRAM_BOT: /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/./vcpkg/packages/tgbot-cpp_arm64-osx/lib/libTgBot.a
TELEGRAM_BOT: /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/vcpkg/installed/arm64-osx/lib/libssl.a
TELEGRAM_BOT: /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/vcpkg/installed/arm64-osx/lib/libcrypto.a
TELEGRAM_BOT: /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/vcpkg/installed/arm64-osx/lib/libboost_system.a
TELEGRAM_BOT: /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/vcpkg/installed/arm64-osx/debug/lib/librpc.a
TELEGRAM_BOT: CMakeFiles/TELEGRAM_BOT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TELEGRAM_BOT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TELEGRAM_BOT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TELEGRAM_BOT.dir/build: TELEGRAM_BOT
.PHONY : CMakeFiles/TELEGRAM_BOT.dir/build

CMakeFiles/TELEGRAM_BOT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TELEGRAM_BOT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TELEGRAM_BOT.dir/clean

CMakeFiles/TELEGRAM_BOT.dir/depend:
	cd /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/build /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/build /Users/williamqiu/Desktop/C++_Project/FoodSaver/telegram-bot/telegram-bot/build/CMakeFiles/TELEGRAM_BOT.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TELEGRAM_BOT.dir/depend

