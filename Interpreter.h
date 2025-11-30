#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Canvas.h"

class Interpreter {
public:
    void run(std::istream& in);

private:
    Canvas canvas_;

    Color readColor(std::stringstream& ss);
    void checkStream(std::stringstream& ss);

    void handleCreateCircle(std::stringstream& ss);
    void handleCreateRectangle(std::stringstream& ss);
    void handleCreateSquare(std::stringstream& ss);
    void handleCreateTriangle(std::stringstream& ss);
    void handleDelete(std::stringstream& ss);
    void handleSetColor(std::stringstream& ss);
    void handleMove(std::stringstream& ss);
    void handleScale(std::stringstream& ss);
    void handleBringToBack(std::stringstream& ss);
    void handleBringToFront(std::stringstream& ss);
    void handleRender(std::stringstream& ss);
};