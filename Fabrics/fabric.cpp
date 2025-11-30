#include "CircleFabric.h"
#include "FigureFabric.h"
#include "RectangleFabric.h"
#include "SquareFabric.h"
#include "TriangleFabric.h"

[[nodiscard]] Figure* CircleFabric::createFigure(long double view_x, long double view_y, long double view_width,
                                               long double view_height) const override {
    CircleArgs circle_args = parameters_;
    circle_args.x += view_x + dx_;
    circle_args.y += view_y + dy_;
    circle_args.r *= scale_;
    circle_args.color = color_;

    return new Circle(circle_args);
}

[[nodiscard]] Figure *RectangleFabric::createFigure(long double view_x, long double view_y, long double view_width,
                                               long double view_height) const override {
    RectangleArgs args = parameters_;
    args.x += view_x + dx_;
    args.y += view_y + dy_;
    args.a *= scale_;
    args.b *= scale_;
    args.color = color_;

    return new Rectangle(args);
}

[[nodiscard]] Figure* SquareFabric::createFigure(long double view_x, long double view_y, long double view_width,
                                               long double view_height) const override {
    SquareArgs square_args = parameters_;

    square_args.x += view_x + dx_;
    square_args.y += view_y + dy_;
    square_args.a *= scale_;
    square_args.color = color_;

    return new Rectangle(square_args);
}

[[nodiscard]] Figure* TriangleFabric::createFigure(long double view_x, long double view_y, long double view_width,
                                               long double view_height) const override {
    TriangleArgs triangle_args = parameters_;
    triangle_args.x += view_x + dx_;
    triangle_args.y += view_y + dy_;
    triangle_args.a *= scale_;
    triangle_args.color = color_;

    return new Triangle(triangle_args);
}

void FigureFabric::changeLayer(const uint32_t layer) {
    layer_ = layer;
}

void FigureFabric::scale(const long double scale) {
    scale_ *= scale;
}

void FigureFabric::move(const long double dx, const long double dy) {
    dx_ += dx;
    dy_ += dy;
}

void FigureFabric::setColor(const Color color) {
    color_ = color;
}