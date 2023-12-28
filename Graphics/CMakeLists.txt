add_library(Graphics Color.cpp ScreenBuffer.cpp Screen.cpp)
target_include_directories(Graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})