cmake_minimum_required(VERSION 3.31)
project(untitled7)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled7 main.cpp
        figures/figure.h
        figures/Rectangle.h
        figures/Circle.h
        figures/Triangle.h
        Canvas.h
        args_structs.h
        Fabrics/FigureFabric.h
        Fabrics/TriangleFabric.h
        Fabrics/SquareFabric.h
        Fabrics/RectangleFabric.h
        Fabrics/CircleFabric.h
        Interpritator.h
        figures/figure.cpp
        Fabrics/fabric.cpp
)
