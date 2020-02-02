cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 11)

project(phoenix-down)
include(FetchContent)

FetchContent_Declare(
    powderpuff
    GIT_REPOSITORY https://github.com/zpshank/powderpuff.git
)

FetchContent_GetProperties(powderpuff)
if(NOT powderpuff_POPULATED)
    FetchContent_Populate(powderpuff)

    add_subdirectory(${powderpuff_SOURCE_DIR} ${powderpuff_BINARY_DIR})
endif()

set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(phoenix_down)
target_sources(phoenix_down
    PRIVATE
        ${SRC}/main.cpp
        # ---- INC ----
        ${INC}/PhoenixDownGame.h
        ${INC}/Creature.h
        ${INC}/Phoenix.h
        ${INC}/SpriteStore.h
        ${INC}/Constants.h
        ${INC}/Slime.h
        ${INC}/Skeleton.h
        ${INC}/Wolf.h
        ${INC}/Ghost.h
        ${INC}/GameScreen.h
        ${INC}/DungeonScreen.h
        # ---- SRC ----
        ${SRC}/PhoenixDownGame.cpp
        ${SRC}/Creature.cpp
        ${SRC}/Phoenix.cpp
        ${SRC}/SpriteStore.cpp
        ${SRC}/Constants.cpp
        ${SRC}/Slime.cpp
        ${SRC}/Skeleton.cpp
        ${SRC}/Wolf.cpp
        ${SRC}/Ghost.cpp
        ${SRC}/DungeonScreen.cpp
)
target_include_directories(phoenix_down
    PRIVATE
        ${INC}
)
target_link_libraries(phoenix_down
    PRIVATE
        powderpuff
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
)

add_custom_command(TARGET phoenix_down PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets/ $<TARGET_FILE_DIR:phoenix_down>/assets)