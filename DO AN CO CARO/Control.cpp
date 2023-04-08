#include "Control.h"


void StartGame(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y)
{
	system("cls");
	ResetData(_A, _TURN, _COMMAND, _X, _Y); // Khởi tạo dữ liệu gốc
	DrawBoard(BOARD_SIZE); // Vẽ màn hình game
}
void MoveRight(_POINT _A[][BOARD_SIZE], int& _X, int& _Y) {
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x)
	{
		_X += 4;
		GotoXY(_X, _Y);
	}
}
void MoveLeft(_POINT _A[][BOARD_SIZE], int& _X, int& _Y) {
	if (_X > _A[0][0].x) {
		_X -= 4;
		GotoXY(_X, _Y);
	}
}
void MoveDown(_POINT _A[][BOARD_SIZE], int& _X, int& _Y) {
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y)
	{
		_Y += 2;
		GotoXY(_X, _Y);
	}
}
void MoveUp(_POINT _A[][BOARD_SIZE], int& _X, int& _Y) {
	if (_Y > _A[0][0].y) {
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}

void GamePlay(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& MO_NHAC)
{
	_PLAYER _PLAYER1, _PLAYER2;
	FixConsoleWindow();
	bool runGame = true;
	int escOption;
	StartGame(_A, _TURN, _COMMAND, _X, _Y);
	StopMusic();
	short int toadothang[24];
	while (1)
	{
		_COMMAND = toupper(_getch());
		if (_COMMAND == ESC)
		{
			escOption = SelectMenu(EscMenu(_A));
			RunEscMenu(_A, _PLAYER1, _PLAYER2, _TURN, escOption, runGame);
		}
		if (_COMMAND == 'O')
			StopMusic();
		else if (_COMMAND == 'P')
			PlayBackGroundMusic(0);
		if (_COMMAND == 27)
		{
			system("cls");
			return;
		}
		else {
			if (_COMMAND == 'A' || _COMMAND == ARROW_LEFT) MoveLeft(_A, _X, _Y);
			else if (_COMMAND == 'W'||_COMMAND == ARROW_UP) MoveUp(_A, _X, _Y);
			else if (_COMMAND == 'S' || _COMMAND == ARROW_DOWN) MoveDown(_A, _X, _Y);
			else if (_COMMAND == 'D' || _COMMAND == ARROW_RIGHT) MoveRight(_A, _X, _Y);
			else if (_COMMAND == 13 || _COMMAND == SPACE) {// Người dùng đánh dấu trên màn hình bàn cờ
				PlaySoundEffect("move", MO_NHAC);
				switch (CheckBoard(_X, _Y, _A, _TURN)) {
				case -1:
				{
					SetColor(1);
					printf("X"); 
					break;
				}
				case 1:
				{
					SetColor(2);
					printf("O"); 
					break;
				}
				case 0: validEnter = false; // Khi đánh vào ô đã đánh rồi
				}
				// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X),toadothang), _A, _TURN, _X, _Y,toadothang, MO_NHAC)) {
					case -1: case 1: case 0:
						if (AskContinue(_A) != 'Y') {
							StopMusic();
							system("cls");
							return;
						}
						else StartGame(_A, _TURN, _COMMAND, _X, _Y);
					}
				}
				validEnter = true; // Mở khóa
			}
		}
	}
}
void RunGame(_POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, bool& MO_NHAC)
{
	bool validEnter = true;
	bool runGame = true;
	int escOption;
	short int toadothang[24];
	//PlaySoundA("NhacGame.wav", NULL, SND_ASYNC | SND_LOOP);
	while (runGame)
	{
		//ShowPlayerInfo(_A, _PLAYER1, _PLAYER2);
		GotoXY(_X, _Y);
		_COMMAND = toupper(_getch());
		if (_COMMAND == ESC)
		{
			escOption = SelectMenu(EscMenu(_A));
			RunEscMenu(_A, _PLAYER1, _PLAYER2, _TURN, escOption, runGame);
		}
		else
		{
			if (_COMMAND == 'W' || _COMMAND == ARROW_UP) MoveUp(_A, _X, _Y);
			else if (_COMMAND == 'S' || _COMMAND == ARROW_DOWN) MoveDown(_A, _X, _Y);
			else if (_COMMAND == 'A' || _COMMAND == ARROW_LEFT) MoveLeft(_A, _X, _Y);
			else if (_COMMAND == 'D' || _COMMAND == ARROW_RIGHT) MoveRight(_A, _X, _Y);
			else if (_COMMAND == ENTER || _COMMAND == SPACE)
			{
				switch (CheckBoard(_X, _Y, _A, _TURN))
				{
				case P_X:
				{
					SetColor(1);
					printf("X");
					break;
				}
				case P_O:
				{
					SetColor(2);
					printf("O");
					break;
				}
				case 0:
					validEnter = false;
					break;
				}
				// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard(_A, _TURN, GetRowIndex(_Y), GetColIndex(_X), toadothang), _A, _TURN, _X, _Y, toadothang, MO_NHAC)) {
					case -1: case 1: case 0:
						if (AskContinue(_A) != 'Y') {
							StopMusic();
							system("cls");
							return;
						}
						else StartGame(_A, _TURN, _COMMAND, _X, _Y);
					}
				}
				validEnter = true; // Mở khóa
			}
			validEnter = true;
		}
	}
	//PlaySoundA("NoSound.wav", NULL, SND_ASYNC);
}
void LoadGame(string filename, _POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y)
{
	system("cls");
	LoadData(filename, _A, _PLAYER1, _PLAYER2, _TURN, _COMMAND, _X, _Y);
	SetPlayerRank(_PLAYER1);
	SetPlayerRank(_PLAYER2);
	DrawBoard(BOARD_SIZE);
	//ShowTurn(_A, _PLAYER1, _PLAYER2, _TURN);
	DrawLoaded(_A);
	GotoXY(_X, _Y);
}
void SaveGame(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN)
{
	bool overwrite = false;
	bool save = true;
	string filename;
	char key;
	int option;

	do
	{
		system("cls");
		PrintText("Nhap ten muon luu game: ", 0, X_CENTER-40, Y_CENTER-10);
		std::getline(cin, filename);
		filename += ".txt";
		if (CheckFileExistence(filename))
		{
			PrintText("Ten da ton tai", 0, X_CENTER - 40, Y_CENTER -8);
			PrintText("Ban co muon luu de?", 0, X_CENTER - 40, Y_CENTER -6);
			option = SelectMenu(YesNoMenu(X_CENTER - 35, Y_CENTER - 4));
			key = RunYesNoMenu(option);
			if (key == 'Y')
			{
				overwrite = true;
				save = false;
			}
		}
		else save = false;
	} while (save);

	SaveData(filename, _A, _PLAYER1, _PLAYER2, _TURN);

	if (!overwrite)
	{
		std::fstream saveFile;
		saveFile.open(SAVED_LIST, std::fstream::app);

		saveFile << filename << "\n";

		saveFile.close();
	}
}
char RunYesNoMenu(int option)
{
	switch (option)
	{
	case 1:
		return 'Y';
	case 2:
		return 'N';
	}
}
int SelectMenu(_MENU menu)
{
	int cursor = 1;
	char key;

	PrintText("", menu.cursorColor, menu.x - 18, menu.y-9);

	do
	{
		key = _getch();
		if ((key == 'w'||key== ARROW_UP)&& cursor > 1)
		{
			PrintText("", menu.cursorColor, menu.x - 18, menu.y + cursor - 10);
			cursor--;
			PrintText("", menu.cursorColor, menu.x - 18, menu.y + cursor - 10);
		}
		else if ((key == 's'||key==ARROW_DOWN) && cursor < menu.options)
		{
			PrintText("", menu.cursorColor, menu.x - 18, menu.y + cursor - 10);
			cursor++;
			PrintText("", menu.cursorColor, menu.x - 18, menu.y + cursor - 10);
		}
		else if (key == ESC)
		{
			return -1;
		}
	} while (key != ENTER);

	return cursor;
}
void RunEscMenu(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int option, bool& runGame)
{
	switch (option)
	{
	case 1: case -1:
		system("cls");
		DrawBoard(BOARD_SIZE);
		DrawLoaded(_A);
		ShowTurn(_A, _PLAYER1, _PLAYER2, _TURN);
		break;
	case 2:
		SaveGame(_A, _PLAYER1, _PLAYER2, _TURN);
		runGame = false;
		break;
	case 3:
		runGame = false;
		break;
	}
}
string RunLoadingMenu(int option)
{
	string filename;
	std::vector<string> files;

	files = LoadFiles();
	filename = files.at(option - 1);

	return filename;
}

