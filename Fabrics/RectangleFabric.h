#pragma once
#include "FigureFabric.h"
#include "../figures/Rectangle.h"

class RectangleFabric final : public FigureFabric {
private:
    RectangleArgs parameters_;

public:
    RectangleFabric(const uint32_t layer, RectangleArgs args) : FigureFabric(layer), parameters_(args) {
    };

    [[nodiscard]] Figure *createFigure() override {
        RectangleArgs args = parameters_;
        args.x += scene_x_ + dx_;
        args.y += scene_y_ + dy_;
        args.a *= scale_;
        args.b *= scale_;
        args.color = color_;

        return new Rectangle(args);
    }
};
