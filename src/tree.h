#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <random>

class Tree {
    public:
    Tree(int grid_width,int grid_height):
    pos_y(static_cast<int>(0.6*grid_height)),
    engine(dev()),
    random_x(grid_width, static_cast<int>(2*grid_width)) {}
    int pos_x = -10;
    int pos_y;
    std::string image_path = "../media/tree.bmp";   
    void update();
    private:
    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_x;
};
#endif