#include "game.typedef.hpp"
#include "game.hpp"

int main()
{

    // imaginons que tu loads ta config depuis un fichier, et ça te donne ça :
    GameConfig config {
        {
            900,
            "Super Pixeled Chess"
        },
        {
            8
        }
    };

    Game chessGame(config);
    chessGame.newGame();
    
    chessGame.play();
    
    return 0;
}