#include "figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

void Circle::locate(std::vector<Color> &canva, long long rows, long long cols) const override {
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

void Rectangle::locate(std::vector<Color>& canva, long long rows, long long cols) const override {
    for (long long row = std::llround(y_); row < std::round(y_ + a_); row++) {
        for (long long col = std::llround(x_); col < std::llround(x_ + b_); col++) {
            if (row > 0 && col > 0) {
                canva[row * cols + col] = color_;
            }
        }
    }
}

void Triangle::locate(std::vector<Color> &canva, long long rows, long long cols) const override {
    long double k = b_ / a_;
    long double c = b_ - k * a_;
    for (long long row = std::llround(x_); row < std::llround(x_ + a_); row++) {
        for (long long col = 0; col <= std::round(k * row + c); col++) {
            canva[row * col + col] = color_;
        }
    }
}

