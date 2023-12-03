#ifndef SHAPES_SHAPE_H
#define SHAPES_SHAPE_H
#include "../Utils/Vec2D.h"
#include <vector>

class Shape {
   public:
    virtual ~Shape() {}
    virtual Vec2D GetCenterPoint() const = 0;
    virtual inline std::vector<Vec2D> GetPoints() const { return mPoints; }
    void MoveBy(const Vec2D& delta);

   protected:
    std::vector<Vec2D> mPoints;
};

#endif  // SHAPES_SHAPE_H