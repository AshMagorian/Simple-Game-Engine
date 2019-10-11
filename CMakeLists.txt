cmake_minimum_required(VERSION 2.6)
project(MYENGINE)

add_library(myEngine
	src/myEngine/Component.cpp
	src/myEngine/Component.h
	src/myEngine/Application.cpp
	src/myEngine/Application.h
	src/myEngine/Entity.h
	src/myEngine/Entity.cpp
)	

add_executable(game
  src/game/main.cpp
)