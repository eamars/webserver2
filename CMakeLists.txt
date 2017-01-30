cmake_minimum_required(VERSION 3.7)
project(webserver2)

# set c++11 standard
set(CMAKE_CXX_STANDARD 11)

# include cmake/ as path for modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# add jsoncpp into project
find_package(JsonCpp REQUIRED)

# build all source files
set(SOURCE_FILES src/Config.cpp src/Config.h src/webhttpd2.cpp)
add_executable(webserver2.out ${SOURCE_FILES})

# link libraries
target_link_libraries( webserver2.out ${JSONCPP_LIBRARY} )