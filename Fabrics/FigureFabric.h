#pragma once

#include "../figures/figure.h"
#include "../args_structs.h"

class FigureFabric {
protected:
    uint32_t layer_;
    long double scene_x_;
    long double scene_y_;
    long double scale_;
    long double dx_;
    long double dy_;
    Color color_;

public:
    struct Comparator {
        bool operator()(const FigureFabric *f1, const FigureFabric *f2) const {
            return f1->layer_ < f2->layer_;
        }
    };

    explicit FigureFabric(const uint32_t layer): scene_x_(0), scene_y_(0), dx_(0), dy_(0),
                                                                 color_{0, 0, 0},
                                                                 layer_(layer), scale_(1) {
    }

    void changeLayer(const uint32_t layer) {
        layer_ = layer;
    }

    void setScene(const long double scene_x, const long double scene_y) {
        scene_x_ = scene_x;
        scene_y_ = scene_y;
    }

    void scale(const long double scale) {
        scale_ *= scale;
    }

    void move(const long double dx, const long double dy) {
        dx_ += dx;
        dy_ += dy;
    }

    void setColor(const Color color) {
        color_ = color;
    }

    [[nodiscard]] virtual Figure *createFigure();

    virtual ~FigureFabric();
};
