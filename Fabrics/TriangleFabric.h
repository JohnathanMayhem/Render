#pragma once

#include "FigureFabric.h"
#include "../figures/Triangle.h"

class TriangleFabric final : public FigureFabric {
    private:
    TriangleArgs parameters_;
public:
    TriangleFabric(uint32_t layer, const TriangleArgs args) : FigureFabric(layer), parameters_(args) {}
    [[nodiscard]] Figure* createFigure() override {
        TriangleArgs triangle_args = parameters_;
        triangle_args.x += scene_x_ + dx_;
        triangle_args.y += scene_y_ + dy_;
        triangle_args.a *= scale_;
        triangle_args.color = color_;

        return new Triangle(triangle_args);
    }
};

