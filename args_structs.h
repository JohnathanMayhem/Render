#pragma once

#include <cstdint>

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct RectangleArgs {
    long double x;
    long double y;
    Color color;
    long double a;
    long double b;
};

struct SquareArgs {
    long double x;
    long double y;
    Color color;
    long double a;
};

struct CircleArgs {
    long double x;
    long double y;
    Color color;
    long double r;
};

struct TriangleArgs {
    long double x;
    long double y;
    Color color;
    long double a;
    long double b;
};