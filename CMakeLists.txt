CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)

PROJECT(Bomberman)

# Debug
ADD_DEFINITIONS(-D_DEBUG)
ADD_DEFINITIONS(-Wall)

# Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Ouput directories
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# GLUT
FIND_PACKAGE(GLUT REQUIRED)
INCLUDE_DIRECTORIES(${GLUT_INCLUDE_DIRS})
LINK_DIRECTORIES(${GLUT_LIBRARY_DIRS})
ADD_DEFINITIONS(${GLUT_DEFINITIONS})
IF(NOT GLUT_FOUND)
    MESSAGE(ERROR " GLUT not found!")
ENDIF(NOT GLUT_FOUND)

# OpenGL
FIND_PACKAGE(OpenGL REQUIRED)
INCLUDE_DIRECTORIES(${OpenGL_INCLUDE_DIRS})
LINK_DIRECTORIES(${OpenGL_LIBRARY_DIRS})
ADD_DEFINITIONS(${OpenGL_DEFINITIONS})
IF(NOT OPENGL_FOUND)
    MESSAGE(ERROR " OPENGL not found!")
ENDIF(NOT OPENGL_FOUND)

# DevIL
FIND_PACKAGE(DevIL REQUIRED)
IF(NOT IL_FOUND)
    MESSAGE(ERROR " DevIL not found!")
ENDIF(NOT IL_FOUND)

# Xerces-C
FIND_PACKAGE(XercesC REQUIRED)
IF(NOT XERCESC_FOUND)
    MESSAGE(ERROR " Xerces-C not found!")
ENDIF(NOT XERCESC_FOUND)


# SDL2
FIND_PACKAGE(SDL2 REQUIRED)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR})
IF(NOT SDL2_FOUND)
    MESSAGE(ERROR " SDL2 not found!")
ENDIF(NOT SDL2_FOUND)

# OpenAL
#FIND_PACKAGE(OPENAL REQUIRED)
#IF(NOT OPENAL_FOUND)
#    MESSAGE(ERROR " OPENAL not found!")
#ENDIF(NOT OPENAL_FOUND)

# ALUT
#FIND_PACKAGE(ALUT REQUIRED)
#IF(NOT ALUT_FOUND)
#    MESSAGE(ERROR " ALUT not found!")
#ENDIF(NOT ALUT_FOUND)

# C++11
INCLUDE(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    MESSAGE(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
endif()

ADD_EXECUTABLE(
    ${PROJECT_NAME}
    src/main.cpp
    src/utility/Texture.cpp
    src/utility/SpriteSheet.cpp
    src/utility/SpriteSheetXMLParser.cxx
    src/utility/Drawing.cpp
    src/utility/BitmapFont.cpp
    src/utility/BitmapFontXMLParser.cxx
    src/utility/Vector2.cpp
    src/utility/MathUtilities.cpp
    src/utility/TileManager.cpp
    src/utility/SpriteAnimation.cpp
    src/utility/AABB2.cpp
    src/utility/TileMap.cpp
    src/utility/Game.cpp
    src/Actor.cpp
    src/Player.cpp
    src/World.cpp
    src/Block.cpp
    src/Bomb.cpp
    src/Fire.cpp
    src/ActorManager.cpp
    src/BlockManager.cpp
    src/BombManager.cpp
    src/FireManager.cpp
    src/BombermanGame.cpp
    src/BaseEvent.cpp
    src/EventManager.cpp
    src/BombExplodedEvent.cpp
    src/FireExtinguishedEvent.cpp
    src/FireFactory.cpp
)

TARGET_LINK_LIBRARIES(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
#   ${GLUT_LIBRARY}
    ${IL_LIBRARIES}
    ${ILU_LIBRARIES}
    ${ILUT_LIBRARIES}
    ${XERCESC_LIBRARY}
    ${SDL2_LIBRARY}
#   ${OPENAL_LIBRARY}
#   ${ALUT_LIBRARY}
)
