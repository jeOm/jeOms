#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "board.h"
#include <iostream>


class game
{
    public:
        game();
        virtual ~game();
        void initialize();
        void update();
        void render ();
        bool checkwin();
        void switchplayer();
        bool gameDraw();
        void run();
        void winner();
    protected:
    private:
        player m_p1;
        player m_p2;
        player *m_currentPlayer;
        bool m_isComplete;
        board m_board;
};

#endif // GAME_H
