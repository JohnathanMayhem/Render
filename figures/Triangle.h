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

    void locate(std::vector<Color> &canva, long long rows, long long cols) const override {
        long double k = b_ / a_;
        long double c = b_ - k * a_;
        for (long long row = std::llround(x_); row < std::llround(x_ + a_); row++) {
            for (long long col = 0; col <= std::round(k * row + c); col++) {
                canva[row * col + col] = color_;
            }
        }
    }
};
