cmake_minimum_required(VERSION 3.16)

add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE debug)

file(GLOB_RECURSE srcs ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE tests ${CMAKE_SOURCE_DIR}/tests/*.cpp)
file(GLOB_RECURSE headers ${CMAKE_SOURCE_DIR}/include/*.h)

add_library(MyLib ${srcs} ${headers})
target_include_directories(MyLib PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_link_libraries(main MyLib)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.13.1
)

FetchContent_MakeAvailable(Catch2)
add_executable(test ${tests} ${srcs})
# target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/include Catch2::Catch2)
target_link_libraries(test MyLib Catch2::Catch2)