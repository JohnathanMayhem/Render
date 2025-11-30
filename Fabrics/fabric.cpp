#include "CircleFabric.h"
#include "FigureFabric.h"
#include "RectangleFabric.h"
#include "SquareFabric.h"
#include "TriangleFabric.h"

[[nodiscard]] Figure* CircleFabric::createFigure() override {
    CircleArgs circle_args = parameters_;
    circle_args.x += scene_x_ + dx_;
    circle_args.y += scene_y_ + dy_;
    circle_args.r *= scale_;
    circle_args.color = color_;

    return new Circle(circle_args);
}

[[nodiscard]] Figure *RectangleFabric::createFigure() override {
    RectangleArgs args = parameters_;
    args.x += scene_x_ + dx_;
    args.y += scene_y_ + dy_;
    args.a *= scale_;
    args.b *= scale_;
    args.color = color_;

    return new Rectangle(args);
}

[[nodiscard]] Figure* SquareFabric::createFigure() override {
    SquareArgs square_args = parameters_;

    square_args.x += scene_x_ + dx_;
    square_args.y += scene_y_ + dy_;
    square_args.a *= scale_;
    square_args.color = color_;

    return new Rectangle(square_args);
}

[[nodiscard]] Figure* TriangleFabric::createFigure() override {
    TriangleArgs triangle_args = parameters_;
    triangle_args.x += scene_x_ + dx_;
    triangle_args.y += scene_y_ + dy_;
    triangle_args.a *= scale_;
    triangle_args.color = color_;

    return new Triangle(triangle_args);
}

void FigureFabric::changeLayer(const uint32_t layer) {
    layer_ = layer;
}

void FigureFabric::setScene(const long double scene_x, const long double scene_y) {
    scene_x_ = scene_x;
    scene_y_ = scene_y;
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