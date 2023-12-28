add_library(Shapes Line2D.cpp Star2D.cpp Shape.cpp AARectangle.cpp Circle.cpp Triangle.cpp)
target_include_directories(Shapes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
