#pragma once

#include "FigureFabric.h"
#include "../figures/Triangle.h"

class TriangleFabric final : public FigureFabric {
    private:
    TriangleArgs parameters_;
public:
    TriangleFabric(uint32_t layer, const TriangleArgs args) : FigureFabric(layer), parameters_(args) {}
    [[nodiscard]] Figure* createFigure(long double view_x, long double view_y) override;
};

