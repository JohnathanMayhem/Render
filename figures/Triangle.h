#pragma once

#include "../args_structs.h"
#include "figure.h"

class Triangle : public Figure {
private:
    long double a_; //x
    long double b_; //y

public:
    explicit Triangle(const TriangleArgs &params) : Figure(params.x, params.y, params.color),
                                                    a_(params.a), b_(params.b) {
    }

    std::vector<std::pair<std::pair<long double, long double>, Color>> Circle::locate() const override ;
};
