cmake_minimum_required(VERSION 3.10.2)

STRING(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("current project: " ${CURRENT_FOLDER})

set(CMAKE_SYSTEM_NAME Linux)

cmake_host_system_information(RESULT arch_value QUERY OS_PLATFORM)
message(STATUS "architecture: " ${arch_value})

if("${arch_value}" STREQUAL "armv7l")
    set(CMAKE_C_COMPILER "gcc")
    set(CMAKE_CXX_COMPILER "g++")
else()
    include ($ENV{HOME}/configs/cross.cmake)
endif()

project(${CURRENT_FOLDER})

add_definitions(-Wall -fPIC)

set(toolkit_root ${CMAKE_CURRENT_SOURCE_DIR}/../EASY-EAI-Toolkit/EASY-EAI-Toolkit-C-SDK/easyeai-api)

set(api_inc
        ${toolkit_root}/peripheral_api/camera
        ${toolkit_root}/peripheral_api/display
        ${CMAKE_SYSROOT}/usr/include/rkfacial
        ${CMAKE_SYSROOT}/usr/include/rkmedia
)

link_directories(
        ${toolkit_root}/peripheral_api/camera
        ${toolkit_root}/peripheral_api/display
        ${toolkit_root}/peripheral_api/display
)

find_package(OpenCV REQUIRED)

file(GLOB_RECURSE APP_SRC
        core/*.cpp
        media/*.cpp
        display/*.cpp
)

add_executable(barcode_app main.cpp ${APP_SRC})

target_include_directories(barcode_app PRIVATE ${api_inc} ${OpenCV_INCLUDE_DIRS})

target_link_libraries(barcode_app pthread camera display easymedia rga ocr rknn_api ${OpenCV_LIBS})