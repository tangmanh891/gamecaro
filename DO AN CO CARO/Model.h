#pragma once
#include "Data.h"
#include "View.h"

void ResetData(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y);
//void GabageCollect(); // Chi viet ham nay khi nao co dung con tro
int TestBoard(_POINT _A[][BOARD_SIZE], bool _TURN, int cRow, int cCol,short int toadothang[24]);
int CheckBoard(int pX, int pY, _POINT _A[][BOARD_SIZE], bool& _TURN);
bool CheckTie(_POINT _A[][BOARD_SIZE]);
bool HorizontalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
bool VerticalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
bool ForwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
bool BackwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
bool CheckWin(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
int GetColIndex(int pX);
int GetRowIndex(int pY);
void PlayBackGroundMusic(int song);
void StopMusic();
void PlaySoundEffect(string s);
void NhapNhayQuanCo(_POINT _A[BOARD_SIZE][BOARD_SIZE], const short int toadothang[24], int pWhoWin);
void LoadData(string filename, _POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y);
std::vector<string> LoadFiles();
bool CheckFileExistence(string filename);
void SaveData(string filename, _POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN);
void SavePlayer(_PLAYER player);
_PLAYER LoadPlayer(_PLAYER player);
void SetPlayerRank(_PLAYER& player);
int CheckPlayerExistence(_PLAYER player);
std::vector<_PLAYER> GetPlayerList();
void SortPlayerList(std::vector<_PLAYER>& playerList);
void PlaySoundEffect(string s, bool MO_NHAC);
void NhapNhayQuanCo(_POINT _A[BOARD_SIZE][BOARD_SIZE], const short int toadothang[24], int pWhoWin);