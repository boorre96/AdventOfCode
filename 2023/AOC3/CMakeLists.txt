cmake_minimum_required(VERSION 3.5)

project(AOC3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AOC3 main.cpp
    numberstartstop.h numberstartstop.cpp
    symbolstartstop.h symbolstartstop.cpp)

include(GNUInstallDirs)
install(TARGETS AOC3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
