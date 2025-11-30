#pragma once
#include "Canvas.h"

class Iterpritator {
private:
    Canvas canvas_;
    std::istream file_;

public:
    Iterpritator(const std::ostream& file) : canvas_(), file_(file) {}

    void interpret() {
        std::ifstream file(fileName_);
        if (file.is_open()) {}
    }
};
