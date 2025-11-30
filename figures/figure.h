#pragma once

#include <vector>
#include <bits/stdc++.h>
#include "../args_structs.h"

class Figure {

protected:
    Color color_;
    long double x_;
    long double y_;

public:

    Figure(long double x, long double y, Color color) : x_(x), y_(y), color_(color) {};

    virtual ~Figure() = default;

    virtual void locate(std::vector<Color> &canva, long long rows, long long cols) const;
};
