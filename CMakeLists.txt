add_subdirectory(Graphics)
add_subdirectory(Input)
add_subdirectory(Scene)
add_subdirectory(Shapes)
add_subdirectory(Utils)

include(FetchContent)
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.30.2)
FetchContent_MakeAvailable(SDL2)

add_library(Engine INTERFACE)
target_include_directories(Engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Engine INTERFACE Graphics Input Shapes Utils SDL2::SDL2)