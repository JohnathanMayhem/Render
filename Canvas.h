#pragma once

#include <set>

#include "Fabrics/FigureFabric.h"
#include "figures/figure.h"


class Canvas {
private:
    std::vector<Color> holst_;
    std::set<FigureFabric *, FigureFabric::Comparator> figures_;
    std::unordered_map<uint64_t, FigureFabric *> figures_db_;
    long long width_;
    long long height_;
    long long max_layer_;
    long long min_layer_;

public:
    Canvas(): width_(0), height_(0), max_layer_(0), min_layer_(0) {
    }

    void addFigure(const uint64_t id, FigureFabric *figure) {
        if (figures_db_.contains(id)) {
            throw std::invalid_argument("Figure already exists");
        }
        figures_db_[id] = figure;
        figures_.insert(figure);
    }

    void deleteFigure(const uint64_t id) {
        if (!figures_db_.count(id)) {
            throw std::invalid_argument("Figure not exists");
        }
        figures_.extract(figures_db_.at(id));
        delete figures_db_.at(id);
        figures_db_.erase(id);
    }

    void move(const uint64_t id, const long double x, const long double y) {
        if (!figures_db_.count(id)) {
            throw std::invalid_argument("Figure not exists");
        }
        figures_db_.at(id)->move(x, y);
    }

    void scale(const uint64_t id, const long double scale) {
        if (!figures_db_.count(id)) {
            throw std::invalid_argument("Figure not exists");
        }
        figures_db_.at(id)->scale(scale);
    }

    void bring_to_back(const uint64_t id) {
        if (!figures_db_.count(id)) {
            throw std::invalid_argument("Figure not exists");
        }
        figures_.extract(figures_db_.at(id));
        figures_db_.at(id)->changeLayer(min_layer_);
        min_layer_++;
        figures_.insert(figures_db_.at(id));
    }

    void bring_to_front(const uint64_t id) {
        if (!figures_db_.count(id)) {
            throw std::invalid_argument("Figure not exists");
        }
        figures_.extract(figures_db_.at(id));
        figures_db_.at(id)->changeLayer(max_layer_);
        max_layer_++;
        figures_.insert(figures_db_.at(id));
    }

    void create_holst(long long width, long double height) {
        width_ = width;
        height_ = height;
        holst_.resize(width * height);
        for (int i = 0; i < holst_.size(); i++) {
            holst_[i] = {0, 0, 0};
        }
    }

    void set_color(uint64_t id, const Color color) {
        if (!figures_db_.count(id)) {
            throw std::invalid_argument("Figure not exists");
        }
        figures_db_.at(id)->setColor(color);
    }


    void render(const std::string &filename,
                const long double x,
                const long double y,
                const long double scene_width,
                const long double scene_height,
                long long         width,
                long long         height)
    {
        create_holst(width, height);
        for (auto figureFabric: figures_) {
            Figure *figure = figureFabric->createFigure(x, y);
            for (auto &point: figure->locate()) {
                if (point.first.first > x && point.first.first < x + scene_width && point.first.second > y && point.
                    first.second < y + scene_height) {
                    long long pos_x = std::llround(point.first.first);
                    long long pos_y = std::llround(point.first.second);
                    if (pos_x < width && pos_y < height && pos_x > 0 && pos_y > 0) {
                        holst_[pos_x + pos_y * width] = point.second;
                    }
                }
            }

            delete figure;
        }
        std::ofstream file(filename);

        file << "P3\n";
        file << width << " " << height << "\n";
        file << "255\n";

        long long cols = std::llround(width);

        for (long long i = std::llround(height_) - 1; i >= 0; --i) {
            for (long long j = 0; j < std::llround(width_); ++j) {
                file << holst_[i * cols + j].r << " " << holst_[i * cols + j].g << " " << holst_[i * cols + j].b;
            }
            file << "\n";
        }
        file.close();
    }
};
