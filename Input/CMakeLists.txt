add_library(Input GameController.cpp InputController.cpp)
target_include_directories(Input PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})