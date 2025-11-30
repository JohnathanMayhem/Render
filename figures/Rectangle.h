#pragma once

#include "../args_structs.h"
#include "figure.h"

class Rectangle : public Figure {
private:
    long double a_;
    long double b_;

public:
    explicit Rectangle(const RectangleArgs &params)
        : Figure(params.x, params.y, params.color), a_(params.a), b_(params.b) {}

    explicit Rectangle(const SquareArgs &argv)
        : Figure(argv.x, argv.y, argv.color), a_(argv.a), b_(argv.a) {}

    ~Rectangle() override = default;

    std::vector<std::pair<std::pair<long double, long double>, Color>> Circle::locate() const override ;
};
