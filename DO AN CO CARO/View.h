#pragma once
#include "Data.h"
#include "Model.h"
#include "Control.h"

void CreateConsoleWindow(int pWidth, int pHeight); //Tao console voi kich thuoc cho truoc
void FixConsoleWindow(); //Co dinh console khong cho ng dung thay doi
void GotoXY(int x, int y);
void DrawBoard(int pSize);
//Hàm xử lý khi người chơi thua
int ProcessFinish(int pWhoWin, _POINT _A[][BOARD_SIZE], bool& _TURN, int& _X, int& _Y,short int toadothang[24], bool& MO_NHAC);
int AskContinue(_POINT _A[][BOARD_SIZE]);
void SetColor(WORD color);
void DrawBoard_1(int m, int n);
void TextColor(int color);
void ScreenStartGame(int n, _POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& MO_NHAC);
void ShowCur(bool CursorVisibility);
void ShowTurn(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN);
void PrintText(string text, int color, int x, int y);
void DrawLoaded(_POINT _A[][BOARD_SIZE]);
_MENU YesNoMenu(int x, int y);
_MENU LoadingMenu();
_MENU EscMenu(_POINT _A[][BOARD_SIZE]);
void ShowPlayerInfo(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2);
void Help();
void About();
void Sound(bool& MO_NHAC);