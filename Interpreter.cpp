#include "Interpreter.h"
#include "Fabrics/CircleFabric.h"
#include "Fabrics/RectangleFabric.h"
#include "Fabrics/SquareFabric.h"
#include "Fabrics/TriangleFabric.h"

#include <iostream>
#include <stdexcept>

#define ENSURE_STREAM(ss) if(ss.fail()) throw std::runtime_error("Invalid arguments format");

void Interpreter::run(std::istream& in) {
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;

        size_t first = line.find_first_not_of(" \t\r\n");
        if (first == std::string::npos) continue;

        std::stringstream ss(line);
        std::string command;
        ss >> command;

        try {
            if (command == "create_circle") handleCreateCircle(ss);
            else if (command == "create_rectangle") handleCreateRectangle(ss);
            else if (command == "create_square") handleCreateSquare(ss);
            else if (command == "create_triangle") handleCreateTriangle(ss);
            else if (command == "delete") handleDelete(ss);
            else if (command == "set_color") handleSetColor(ss);
            else if (command == "move") handleMove(ss);
            else if (command == "scale") handleScale(ss);
            else if (command == "bring_to_back") handleBringToBack(ss);
            else if (command == "bring_to_front") handleBringToFront(ss);
            else if (command == "render") handleRender(ss);
            else {
                throw std::runtime_error("Unknown command: " + command);
            }
        } catch (const std::exception& e) {
            std::cerr << "Error in command '" << command << "': " << e.what() << std::endl;
            exit(1);
        }
    }
}

Color Interpreter::readColor(std::stringstream& ss) {
    int r, g, b;
    ss >> r >> g >> b;
    ENSURE_STREAM(ss);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        throw std::invalid_argument("Color components must be between 0 and 255");
    }
    return {static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b)};
}

void Interpreter::handleCreateCircle(std::stringstream& ss) {
    uint64_t id;
    ss >> id;
    Color c = readColor(ss);
    long double x, y, r;
    ss >> x >> y >> r;
    ENSURE_STREAM(ss);

    if (r < 0) throw std::invalid_argument("Radius cannot be negative");

    CircleArgs args{x, y, c, r};
    auto* fabric = new CircleFabric(0, args);
    fabric->setColor(c);
    canvas_.addFigure(id, fabric);
}

void Interpreter::handleCreateRectangle(std::stringstream& ss) {
    uint64_t id;
    ss >> id;
    Color c = readColor(ss);
    long double x, y, w, h;
    ss >> x >> y >> w >> h;
    ENSURE_STREAM(ss);

    if (w < 0 || h < 0) throw std::invalid_argument("Width cannot be negative");
    
    RectangleArgs args{x, y, c, w, h};
    auto* fabric = new RectangleFabric(0, args);
    fabric->setColor(c);
    canvas_.addFigure(id, fabric);
}

void Interpreter::handleCreateSquare(std::stringstream& ss) {
    uint64_t id;
    ss >> id;
    Color c = readColor(ss);
    long double x, y, side;
    ss >> x >> y >> side;
    ENSURE_STREAM(ss);

    if (side < 0) throw std::invalid_argument("Side cannot be negative");

    SquareArgs args{x, y, c, side};
    auto* fabric = new SquareFabric(0, args);
    fabric->setColor(c);
    canvas_.addFigure(id, fabric);
}

void Interpreter::handleCreateTriangle(std::stringstream& ss) {
    uint64_t id;
    ss >> id;
    Color c = readColor(ss);
    long double x, y, a, b;
    ss >> x >> y >> a >> b;
    ENSURE_STREAM(ss);

    if (a < 0 || b < 0) throw std::invalid_argument("sides cannot be negative");

    TriangleArgs args{x, y, c, a, b};
    auto* fabric = new TriangleFabric(0, args);
    fabric->setColor(c);
    canvas_.addFigure(id, fabric);
}

void Interpreter::handleDelete(std::stringstream& ss) {
    uint64_t id;
    ss >> id;
    ENSURE_STREAM(ss);
    canvas_.deleteFigure(id);
}

void Interpreter::handleSetColor(std::stringstream& ss) {
    uint64_t id;
    ss >> id;
    Color c = readColor(ss);
    ENSURE_STREAM(ss);
    canvas_.set_color(id, c);
}

void Interpreter::handleMove(std::stringstream& ss) {
    uint64_t id;
    long double dx, dy;
    ss >> id >> dx >> dy;
    ENSURE_STREAM(ss);
    canvas_.move(id, dx, dy);
}

void Interpreter::handleScale(std::stringstream& ss) {
    uint64_t id;
    long double s;
    ss >> id >> s;
    ENSURE_STREAM(ss);
    if (s <= 0) throw std::invalid_argument("Scale must be > 0");
    canvas_.scale(id, s);
}

void Interpreter::handleBringToBack(std::stringstream& ss) {
    uint64_t id;
    ss >> id;
    ENSURE_STREAM(ss);
    canvas_.bring_to_back(id);
}

void Interpreter::handleBringToFront(std::stringstream& ss) {
    uint64_t id;
    ss >> id;
    ENSURE_STREAM(ss);
    canvas_.bring_to_front(id);
}

void Interpreter::handleRender(std::stringstream& ss) {
    std::string filename;
    long double sx, sy, sw, sh;
    long long w, h;
    ss >> filename >> sx >> sy >> sw >> sh >> w >> h;
    ENSURE_STREAM(ss);

    if (w <= 0 || h <= 0) throw std::invalid_argument("Image dimensions must be > 0");
    if (sw == 0 || sh == 0) throw std::invalid_argument("Scene dimensions cannot be 0");

    Color bgColor{0, 0, 0}; 
    canvas_.render(filename, sx, sy, sw, sh, w, h);
}