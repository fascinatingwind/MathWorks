cmake_minimum_required(VERSION 3.16)
project(CameraMove VERSION 0.1)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Vulkan REQUIRED)

find_package(GLFW3 REQUIRED)
if (GLFW3_FOUND)
  message(STATUS "${PROJECT_NAME} GLFW found")
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
	"include/window.h"
	"include/vulkan_instance.h"
	"include/stb_image.h"
)

set(SOURCE_FILES ${SOURCE_FILES}
	"src/camera.cpp"
	"src/window.cpp"
	"src/vulkan_instance.cpp"
)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
	${Vulkan_LIBRARIES}
	${GLFW3_LIBRARY}
)

target_include_directories(${PROJECT_NAME} PUBLIC
	"include"
	${Vulkan_INCLUDE_DIR}
	${GLFW3_INCLUDE_DIR}
)


find_package(Vulkan REQUIRED COMPONENTS glslc)
find_program(glslc_executable NAMES glslc HINTS Vulkan::glslc)

#==============================================================================
# COMPILE SHADERS
#

set(SHADER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/shaders)
set(SHADER_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/shaders)

file(GLOB SHADERS
  ${SHADER_SOURCE_DIR}/*.vert
  ${SHADER_SOURCE_DIR}/*.frag
  ${SHADER_SOURCE_DIR}/*.comp
  ${SHADER_SOURCE_DIR}/*.geom
  ${SHADER_SOURCE_DIR}/*.tesc
  ${SHADER_SOURCE_DIR}/*.tese
  ${SHADER_SOURCE_DIR}/*.mesh
  ${SHADER_SOURCE_DIR}/*.task
  ${SHADER_SOURCE_DIR}/*.rgen
  ${SHADER_SOURCE_DIR}/*.rchit
  ${SHADER_SOURCE_DIR}/*.rmiss)

add_custom_command(
  COMMAND
    ${CMAKE_COMMAND} -E make_directory ${SHADER_BINARY_DIR}
  OUTPUT ${SHADER_BINARY_DIR}
  COMMENT "Creating ${SHADER_BINARY_DIR}"
)

foreach(source IN LISTS SHADERS)
  get_filename_component(FILENAME ${source} NAME)
  add_custom_command(
    COMMAND
      ${glslc_executable}
      #      -MD -MF ${SHADER_BINARY_DIR}/${FILENAME}.d
      -o ${SHADER_BINARY_DIR}/${FILENAME}.spv
      ${source}
    OUTPUT ${SHADER_BINARY_DIR}/${FILENAME}.spv
    DEPENDS ${source} ${SHADER_BINARY_DIR}
    COMMENT "Compiling ${FILENAME}"
  )
  list(APPEND SPV_SHADERS ${SHADER_BINARY_DIR}/${FILENAME}.spv)
endforeach()

add_custom_target(shaders_build ALL DEPENDS ${SPV_SHADERS})