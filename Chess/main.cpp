#include "game.typedef.hpp"
#include "game.hpp"
#include "textures.hpp"

int main()
{

    // imaginons que tu loads ta config depuis un fichier, et ça te donne ça :
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