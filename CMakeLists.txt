# add -G "MinGW Makefiles" if built the first time i think when running cmake -S (source) -B (build)
cmake_minimum_required(VERSION 3.20.0)
set (CMAKE_CXX_STANDARD 11)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra") # add -O3 for performance

# uncomment for debug
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUGpong")


SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")


project(Cpp_Pong) 


add_executable(${PROJECT_NAME} 
src/main.cpp
src/InputHandler.cpp
src/GameLogic.cpp
src/Renderer.cpp
src/Slider.cpp
src/Ball.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

#copy .exe to bin
add_custom_command(TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ../bin)