cmake_minimum_required(VERSION 3.17)

project(CNN)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

set(Torch_DIR "C:/CNN/libtorch/share/cmake/Torch")
set(OpenCV_DIR "C:/CNN/opencv/build/x64/vc16/lib")
find_package(Torch REQUIRED)
find_package(OpenCV 4.0 REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

include_directories("C:/CNN/libtorch/include")
include_directories("C:/CNN/libtorch/include/torch/csrc/api/include")
include_directories("C:/CNN/opencv/build/include")

add_executable(CNNT cnn_train.cpp)


message(${TORCH_LIBRARIES})
target_link_libraries(CNNT "${TORCH_LIBRARIES}" "${OpenCV_LIBS}")

set_property(TARGET CNNT PROPERTY CXX_STANDARD 17)

if (MSVC)
  file(GLOB TORCH_DLLS "C:/CNN/libtorch/lib/*.dll")
  add_custom_command(TARGET CNNT
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:CNNT>) 
  
  file(GLOB TORCH_DLLS "C:/CNN/opencv/build/x64/vc16/bin/*.dll")
  add_custom_command(TARGET CNNT
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:CNNT>) 
endif (MSVC)

message(STATUS "Torch libraries: ${TORCH_LIBRARIES}")


