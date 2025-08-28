cmake_minimum_required(VERSION 4.1.0)
project(Astra)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 

include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4 
)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG        master
)

FetchContent_MakeAvailable(glfw glm)

add_library(glad STATIC libs/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/include)

file(GLOB IMGUI_SOURCES
  "libs/imgui/*.cpp"
  "libs/imgui/backends/*.cpp"
)
add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui
  ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/backends
  ${glfw_SOURCE_DIR}/include
)

find_package(OpenGL REQUIRED)

add_executable(Astra 
  src/Astra.cpp
  src/core/Application.cpp
  src/core/Mesh.cpp
  src/core/Shader.cpp
  src/graphics/Graphics.cpp
  src/graphics/Object.cpp
  src/graphics/Texture.cpp


)

target_link_libraries(Astra PRIVATE
  glm
  glad
  glfw
  imgui
  OpenGL::GL
)