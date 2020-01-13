cmake_minimum_required(VERSION 2.6)
project(MYENGINE)

include_directories(
src
contrib
)

if(MSVC)
  include_directories(
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(myEngine
	src/myEngine/Component.cpp
	src/myEngine/Application.cpp
	src/myEngine/Entity.cpp
	src/myEngine/Component.h
	src/myEngine/Application.h
	src/myEngine/Entity.h
	src/myEngine/VertexBuffer.cpp
	src/myEngine/VertexArray.cpp
	src/myEngine/VertexBuffer.h
	src/myEngine/VertexArray.h
	src/myEngine/ShaderProgram.h
	src/myEngine/ShaderProgram.cpp
	src/myEngine/Renderer.h
	src/myEngine/Renderer.cpp
	src/myEngine/Transform.h
	src/myEngine/Transform.cpp
	src/myEngine/stb_image.h
	src/myEngine/stb_image.cpp
	src/myEngine/Texture.h
	src/myEngine/Texture.cpp
	src/myEngine/Camera.h
	src/myEngine/Camera.cpp
	src/myEngine/Environment.h
	src/myEngine/Environment.cpp
)	

if(MSVC)
  target_link_libraries(myEngine
    SDL2 glew32 opengl32
  )
else()
  target_link_libraries(myEngine
    SDL2 GLU GLEW GL
  )
endif()

add_executable(game
	src/game/main.cpp
	src/game/Camera_FirstPerson.h
	src/game/Camera_FirstPerson.cpp
)

target_link_libraries(game myEngine)

if(MSVC)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:game>"
  )

  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:game>"
  )
endif()