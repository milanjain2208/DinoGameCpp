#include <iostream>
#include "renderer.h"
#include "game.h"
#include "controller.h"
int main() {
    constexpr std::size_t kFramesPerSecond{25};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Game game(kGridWidth, kGridHeight);
    Controller controller;
    game.Run(controller,renderer, kMsPerFrame);

    std::cout << "Game has successfully terminated!\n";
}