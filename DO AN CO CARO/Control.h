#pragma once
#include "Data.h"
#include "View.h"
#include "Model.h"

void StartGame(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y);
void MoveLeft(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
void MoveRight(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
void MoveDown(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
void MoveUp(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);

void GamePlay(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& MO_NHAC);
//void GamePlay(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter);
void SaveGame(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN);
void LoadGame(string filename, _POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y);
char RunYesNoMenu(int option);
int SelectMenu(_MENU menu);
string RunLoadingMenu(int option);
void RunEscMenu(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int option, bool& runGame);
void RunGame(_POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, bool& MO_NHAC);