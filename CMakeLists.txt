add_subdirectory(Graphics)
add_subdirectory(Shapes)
add_subdirectory(Utils)
add_subdirectory(App)

add_library(Engine INTERFACE
        Games/IGame.h)
target_include_directories(Engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Engine INTERFACE Graphics Shapes Utils)