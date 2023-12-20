cmake_minimum_required(VERSION 2.8)

project(CNN)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

set(CMAKE_PREFIX_PATH C:/CNN/libtorch)
set(OpenCV_DIR "C:/CNN/opencv/build/x64/vc16/lib")
find_package(Torch REQUIRED)
find_package(OpenCV 4.0 REQUIRED)

include_directories("C:/CNN/libtorch/include")
include_directories("C:/CNN/libtorch/include/torch/csrc/api/include")
include_directories("C:/CNN/opencv/build/include")

#libtorch
add_executable(CNNMODEL cnn_model.cpp)
add_executable(CNNT cnn_train.cpp)
#add_executable(CNN test_model.cpp)
#add_executable(CNN load_data.cpp)

#libtorch
message(${TORCH_LIBRARIES})
target_link_libraries(CNNMODEL "${TORCH_LIBRARIES}")
target_link_libraries(CNNT "${TORCH_LIBRARIES}")
#target_link_libraries(test_model "${TORCH_LIBRARIES}")
#target_link_libraries(load_data "${TORCH_LIBRARIE  S}")

# opencv
target_link_libraries(CNNT "${OpenCV_LIBS}")

set_property(TARGET CNNMODEL PROPERTY CXX_STANDARD 17)
set_property(TARGET CNNT PROPERTY CXX_STANDARD 17)
#set_property(TARGET test_model PROPERTY CXX_STANDARD 14)
#set_property(TARGET load_data PROPERTY CXX_STANDARD 14)

if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET CNNMODEL
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:CNNMODEL>)
endif (MSVC)


