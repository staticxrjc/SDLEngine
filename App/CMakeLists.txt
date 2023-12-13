find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_subdirectory(Scenes)
add_subdirectory(Input)

add_library(App App.cpp)
target_link_libraries(App Scenes Input ${SDL2_LIBRARIES})