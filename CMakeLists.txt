cmake_minimum_required(VERSION 3.10)
project(assethasher)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets)


add_executable(assethasher WIN32 MACOSX_BUNDLE
    MainWindow.ui MainWindow.hpp MainWindow.cpp
    CRC32.hpp CRC32.cpp
    main.cpp)

target_link_libraries(assethasher ${Qt5Widgets_LIBRARIES})
