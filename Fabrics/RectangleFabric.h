#pragma once
#include "FigureFabric.h"
#include "../figures/Rectangle.h"

class RectangleFabric final : public FigureFabric {
private:
    RectangleArgs parameters_;

public:
    RectangleFabric(const uint32_t layer, RectangleArgs args) : FigureFabric(layer), parameters_(args) {
    };

    [[nodiscard]] Figure *createFigure() override;
};
