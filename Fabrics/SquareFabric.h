#pragma once

#include "FigureFabric.h"
#include "../figures/Rectangle.h"

class SquareFabric: public FigureFabric {
private:
    SquareArgs parameters_;
public:
    SquareFabric(const uint32_t layer, const SquareArgs &args) : FigureFabric(layer), parameters_(args) {}
    [[nodiscard]] Figure* createFigure() override;
};