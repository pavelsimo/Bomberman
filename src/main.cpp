#include <string>

#include "BombermanGame.h"

const uint32_t SCREEN_WIDTH = 640;
const uint32_t SCREEN_HEIGHT = 640;
const std::string SCREEN_TITLE = "Bomberman";

int main(int argc, char *argv[])
{
    std::shared_ptr<BombermanGame> game(new BombermanGame(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT));
    game->Run();
    return 0;
}