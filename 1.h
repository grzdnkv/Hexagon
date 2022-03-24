/** 
@mainpage Kalax Game
- @ref 1.h Grid.h
\author Student Muratov Mihail 
\version 1.0 
\date January, 2020 
\warning This class is created for educational purposes 
*/ 
#pragma once 
#include <iostream> 
#include <vector> 
/** 
@brief Main Class 
*/ 
class Game { 

private: 

public: 
/** 
@brief Map vector 
*/ 
std::vector<int> Map; 
/** 
@brief Player parameter 
*/ 
int plr; 
/** 
@brief Game values 
*/ 
int kal1, kal2; 
/** 
@brief Class constructor 
*/ 
Game(); 
/*! 
Method begins game 
\param[in] Kalax Game parameter
\param[in] mode Game mode
*/ 
void Start(Game Kalax,int mode);
/*!
Method сheck for victory
\return bool
*/ 
int win();
/*!
Method of move on game field
\param[in] hole Game cell
\param[in] plr Number of player
\return int result field
*/  
int move(int hole,int plr);
/*!
Method of move on game field
\param[in] out std::ostream parameter
\param[in] Kalax Game field
*/ 
friend std::ostream& operator«(std::ostream &out, const Game& Kalax); 

};