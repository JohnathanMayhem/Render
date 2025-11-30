#pragma once
#include "FigureFabric.h"
#include "../figures/Circle.h"

class CircleFabric : public FigureFabric {
private:
    CircleArgs parameters_;
public:
    CircleFabric(uint32_t layer, const CircleArgs &figure_args) : FigureFabric(layer), parameters_(figure_args) {};

    [[nodiscard]] Figure* createFigure(long double view_x, long double view_y) override;
};
