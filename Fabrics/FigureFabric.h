#pragma once

#include "../figures/figure.h"
#include "../args_structs.h"

class FigureFabric {
protected:
    uint32_t layer_;
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

    explicit FigureFabric(const uint32_t layer): dx_(0), dy_(0),
                                                                 color_{0, 0, 0},
                                                                 layer_(layer), scale_(1) {
    }

    void changeLayer(const uint32_t layer);

    void scale(const long double scale);

    void move(const long double dx, const long double dy);

    void setColor(const Color color);

    [[nodiscard]] virtual Figure *createFigure(long double view_x, long double view_y);

    virtual ~FigureFabric();
};
