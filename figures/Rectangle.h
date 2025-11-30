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

    void locate(std::vector<Color>& canva, long long rows, long long cols) const override {
        for (long long row = std::llround(y_); row < std::round(y_ + a_); row++) {
            for (long long col = std::llround(x_); col < std::llround(x_ + b_); col++) {
                if (row > 0 && col > 0) {
                    canva[row * cols + col] = color_;
                }
            }
        }
    }


};
