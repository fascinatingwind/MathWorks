cmake_minimum_required(VERSION 3.16)
project(CameraMove VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
link_directories(src)

set(SOURCE_FILES
	"main.cpp"
)

set(HEADER_FILES
	"include/point.h"
)

set(SOURCE_FILES
	"src/point.cpp"
)

add_executable(CameraMove ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(CameraMove PUBLIC include)