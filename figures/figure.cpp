#include "figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

std::vector<std::pair<std::pair<long double, long double>, Color>> Circle::locate() const override {
    std::vector<std::pair<std::pair<long double, long double>, Color>> circle;
    for (long double x = -r_; x <= r_; x += 1) {
        long double y1 = sqrt(r_ * r_ - x * x);
        long double y2 = -sqrt(r_ * r_ - x * x);
        circle.push_back(std::make_pair(std::make_pair(x, y1), color_));
        circle.push_back(std::make_pair(std::make_pair(x, y1), color_));
    }
    return circle;
}

std::vector<std::pair<std::pair<long double, long double>, Color>> Rectangle::locate() const override {
    std::vector<std::pair<std::pair<long double, long double>, Color>> rectancle;
    for (long double y = y_; y < y + a_; y++) {
        for (long double x = x_; x < x_ + b_; x++) {
            rectancle.push_back(std::make_pair(std::make_pair(x, y), color_));
        }
    }
    return rectancle;
}

std::vector<std::pair<std::pair<long double, long double>, Color>> Triangle::locate() const override {
    std::vector<std::pair<std::pair<long double, long double>, Color>> triangle;
    long double k = b_ / a_;
    long double c = b_ - k * a_;
    for (long double x = std::llround(x_); x < std::llround(x_ + a_); x++) {
        for (long double y = 0; y <= k * x + c; y++) {
            triangle.push_back(std::make_pair(std::make_pair(x, y), color_));
        }
    }
    return triangle;
}

