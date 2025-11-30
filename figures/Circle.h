#pragma once

#include <cmath>

#include "../args_structs.h"
#include "figure.h"

class Circle: public Figure{
private:
    long double r_;
public:
    explicit Circle(const CircleArgs& params)
        : Figure(params.x, params.y, params.color),
          r_(params.r) {}

    std::vector<std::pair<std::pair<long double, long double>, Color>> Circle::locate() const override;
};
