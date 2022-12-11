#include "game.hpp"
#include "textures.hpp"
#include "game.typedef.hpp"

int main()
{

    // imaginons que tu loads ta config depuis un fichier, et �a te donne �a :
    GameConfig config {
        {
            920,
            "Super Pixeled Chess"
        },
        {
            8
        }
    };

    Game chessGame(config);


    chessGame.play();
    
    return 0;
}