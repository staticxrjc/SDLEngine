add_library(Input GameController.cpp InputController.cpp)
target_link_libraries(Input PUBLIC SDL2::SDL2)
target_include_directories(Input PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})