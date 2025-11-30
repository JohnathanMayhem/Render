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

    virtual std::vector<std::pair<std::pair<long double, long double>, Color>> locate() const;
};
