cmake_minimum_required(VERSION 3.16)
project(hw3)

set(CMAKE_CXX_STANDARD 11)

add_executable(hw3 main.cpp Sim_object.cpp Sim_object.h Moving_object.cpp Moving_object.h Structure.cpp Structure.h Model.cpp Model.h Agent.cpp Agent.h Farm.cpp Farm.h Castle.cpp Castle.h Peasant.cpp Peasant.h Knight.cpp Knight.h Thug.cpp Thug.h Controller.cpp Controller.h View.cpp View.h Geometry.h)