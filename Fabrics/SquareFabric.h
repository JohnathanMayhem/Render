#pragma once

#include "FigureFabric.h"
#include "../figures/Rectangle.h"

class SquareFabric: public FigureFabric {
private:
    SquareArgs parameters_;
public:
    SquareFabric(const uint32_t layer, const SquareArgs &args) : FigureFabric(layer), parameters_(args) {}
    [[nodiscard]] Figure* createFigure() override {
        SquareArgs square_args = parameters_;

        square_args.x += scene_x_ + dx_;
        square_args.y += scene_y_ + dy_;
        square_args.a *= scale_;
        square_args.color = color_;

        return new Rectangle(square_args);
    }
};