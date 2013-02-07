#include "game.h"
#include "player.h"
#include "board.h"
#include <iostream>
using namespace std;

game::game()
{
    //ctor
}

game::~game()
{
    //dtor
}
void game::initialize (){
    m_board.initialize();
    m_p1.setname("Player 1");
    m_p1.seticon('X');
    m_p2.setname("Player 2");
    m_p2.seticon('O');
    m_currentPlayer = &m_p1;

}
void game::update (){
        m_board.update(m_currentPlayer->getmove(), m_currentPlayer->geticon());
        m_isComplete = checkwin();
            if (m_isComplete==1)
                {
                    m_board.render();
                    cout<< m_currentPlayer->getname() <<"   W I N S ! ! !"<< endl;
                }
            if (gameDraw()==1 && m_isComplete==0)
                {
                m_board.render();
                cout <<"\t\t   Game Draw" <<endl;
                }
        switchplayer();
}
void game::render ()
{
    m_board.render();
    cout << m_currentPlayer->getname()<<" will move.";
}
bool game::checkwin()
{
    m_board.checkwin();

}
bool game::gameDraw()
{
    m_board.gameDraw();
}


void game::switchplayer()
{
    if (m_currentPlayer == &m_p1)
        m_currentPlayer = &m_p2;
    else if (m_currentPlayer == &m_p2)
        m_currentPlayer = &m_p1;
}


void game::run()
{
    while(m_isComplete==0&&gameDraw()==0)
        {
            render();
            update();
        }
}

