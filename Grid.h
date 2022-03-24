/**
@mainpage Hexagon game
- @ref Grid.h
\author Student Gruzdenkov Gregory
\version 1.0
\date January, 2020
\warning This class is created for educational purposes
*/
#ifndef HEXAGON_GRID_H
#define HEXAGON_GRID_H

#include <iostream>
#include <ncurses.h>
#include <curses.h>
/**
@brief Main class of game grid
*/
class Grid {
private:
public:
    /**
@brief Class Constructor
*/
    Grid();
    /**
@brief Method draws game field
*/
    void ViewNcur();
    /**
@brief Nested class of Hex cells's
*/
    class Hex{
    public:
        int q;
        int r;
        char status;
        Hex() {
            status = '0';
        };
    };
    Grid::Hex field[7][7];
    /*!
Function of testing for occupancy.
\return Return bool.
*/
    bool IsFilled();
/*!
Function of calculating distance between two cell's.
\param[in] a First(root) game cell.
\param[in] b Second game cell.
\return Distance between two cell's.
*/
    int Distance(Hex a, Hex b);
    /*!
Method draws possible move's.
     \param[in] a Game cell.
     \param[in] x x coordinate.
     \param[in] y y coordinate.
*/
    void DistanceMarker(Hex a, int x, int y);
/*!
  Function of capture enemy cells.
  \param[in] a Game cell.
  \param[in] playernumber Number of player.
 */
    void Invader(Hex a, char playernumber);
    /*!
Function of testing for one player in game.
\return Return bool.
 */
    bool IsOnePlayer();
};


#endif //HEXAGON_GRID_H
