add_library(storycore STATIC
    Game.cpp
    Entity.cpp
    ConsoleRenderer.cpp
)
target_include_directories(storycore PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}
)
