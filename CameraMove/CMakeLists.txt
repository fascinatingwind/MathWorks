cmake_minimum_required(VERSION 3.16)
project(CameraMove VERSION 0.1)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Vulkan REQUIRED)

find_package(GLFW3 REQUIRED)
if (GLFW3_FOUND)
  message(STATUS "${PROJECT_NAME} Glfw found")
  message(STATUS "${PROJECT_NAME} GLFW include dir [${GLFW3_INCLUDE_DIR}]")
  include_directories(${GLFW3_INCLUDE_DIR})
  message(STATUS "${PROJECT_NAME} GLFW libraries [${GLFW3_LIBRARY}]")
  link_libraries (${GLFW3_LIBRARY})
endif (GLFW3_FOUND)

include_directories("include")
link_directories("src")

set(SOURCE_FILES
	"main.cpp"
)

set(HEADER_FILES
	"include/point.h"
	"include/camera.h"
	"include/size.h"
)

set(SOURCE_FILES ${SOURCE_FILES}
	"src/point.cpp"
	"src/camera.cpp"
	"src/size.cpp"
)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC "include")
target_link_libraries(${PROJECT_NAME}
	${Vulkan_LIBRARIES}
	${GLFW3_LIBRARY})

target_include_directories(${PROJECT_NAME} PUBLIC
	${Vulkan_INCLUDE_DIR}
	${GLFW3_INCLUDE_DIR})