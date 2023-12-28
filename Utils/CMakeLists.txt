add_library(Utils Utils.cpp Vec2D.cpp
        FileCommandLoader.cpp
        FileCommandLoader.h)
target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})