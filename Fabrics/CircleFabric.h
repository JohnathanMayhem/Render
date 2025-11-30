#pragma once
#include "FigureFabric.h"
#include "../figures/Circle.h"

class CircleFabric : public FigureFabric {
private:
    CircleArgs parameters_;
public:
    CircleFabric(uint32_t layer, const CircleArgs &figure_args) : FigureFabric(layer), parameters_(figure_args) {};

    [[nodiscard]] Figure* createFigure() override {
        CircleArgs circle_args = parameters_;
        circle_args.x += scene_x_ + dx_;
        circle_args.y += scene_y_ + dy_;
        circle_args.r *= scale_;
        circle_args.color = color_;

        return new Circle(circle_args);
    }
};
