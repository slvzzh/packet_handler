cmake_minimum_required(VERSION 3.5)

project(tddProject LANGUAGES CXX)
include_directories(${CMAKE_SOURCE_DIR}/TestTask/libs/PacketHandler/include)

SET(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(UNITTEST ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY   ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/binaries)

if(UNIX)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/binaries/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/binaries/lib)
elseif(WIN32)
    set(TEST_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/binaries)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY   ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/binaries)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/binaries)
endif()

if(UNITTEST)
    add_subdirectory(googletests/)
endif()



add_subdirectory(TestTask/libs/PacketHandler)

if(UNITTEST)
    message(" output lib dir " ${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG})
    enable_testing()
endif()

add_executable(tddProject main.cpp)


target_link_libraries(tddProject PRIVATE exampleProject)
target_include_directories(tddProject PRIVATE
    ${CMAKE_SOURCE_DIR}/TestTask/libs/PacketHandler/include
)
