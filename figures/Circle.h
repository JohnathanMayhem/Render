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
          r_(params.r) {
    }

    void locate(std::vector<Color> &canva, long long rows, long long cols) const override {
        for (long double row = -r_; row <= r_; row += 1) {
            long double col_circle = std::sqrt(r_ * r_ - row * row);
            long long col_canva1 = std::llround(col_circle + y_);
            long long col_canva2 = std::llround(-col_circle + y_);
            long long row_canva1 = std::llround(col_circle + x_);
            long long row_canva2 = std::llround(-col_circle + x_);
            if (col_canva1 >= 0 && std::llround(row_canva1) >= 0) {
                canva[row_canva1 * cols + col_canva1] = color_;
            }
            if (col_canva2 >= 0 && std::llround(row_canva2) >= 0) {
                canva[row_canva2 * cols + col_canva2] = color_;
            }
        }
    }


};
