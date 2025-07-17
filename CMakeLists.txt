cmake_minimum_required(VERSION 3.25)
project(main)
file(GLOB SOURCE CONFIGURE_DEPENDS "src/main.cpp")
add_executable(main ${SOURCE})