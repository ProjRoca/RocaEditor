cmake_minimum_required(VERSION 3.0)
project(RocaEditor)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

file(GLOB_RECURSE ROCAEDITOR_SRC RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.cpp" "src/*.h" "assets/*.qrc")
add_executable(RocaEditor WIN32 ${ROCAEDITOR_SRC})
set_target_properties(RocaEditor PROPERTIES
    CXX_STANDARD 11 POSITION_INDEPENDENT_CODE ON)

find_package(Qt5Widgets)
target_link_libraries(RocaEditor PUBLIC Qt5::Widgets)

add_subdirectory(lib/QRockyStyle)
target_link_libraries(RocaEditor PUBLIC QRockyStyle_s)
