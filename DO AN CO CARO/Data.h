#pragma once

//Libraries
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
#include<stack>
using std::cout;
using std::cin;
using std::string;
using namespace std;

//Hằng số
#define BOARD_SIZE 12 // Kích thức ma trận bàn cờ
#define LEFT 0 // Tọa độ trái màn hình bàn cờ
#define TOP 0 // Tọa độ trên màn hình bàn cờ
#define MIDDLESCREEN //Tọa độ giữa màn hình hiển thị game theo trục x
struct _POINT { 
	int x, 
		y, 
		c; 
}; // x: tọa độ dòng, y: tọa độ cột, c: đánh dấu
#define FIRST true
#define SECOND false
#define P_X -1
#define P_O 1
#define SPACE 32
#define ENTER 13
#define ESC 27
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define HORIZONTAL_LINE (char)196
#define VERTICAL_LINE (char)179
#define HORIZONTAL_DISTANCE 4
#define VERTICAL_DISTANCE 2
#define TOP_LEFT (char)218
#define TOP_RIGHT (char)191
#define BOTTOM_LEFT (char)192
#define BOTTOM_RIGHT (char)217
#define TOP_CROSS (char)194
#define BOTTOM_CROSS (char)193
#define	LEFT_CROSS (char)195
#define RIGHT_CROSS (char)180
#define CROSS (char)197
struct toado {
	short int x, y;
	char data;
};
typedef struct toado Toado;
struct _MENU
{
	int options;	 //So chuc nang cua Menu
	int x;			 // Toa do cua diem bat 
	int y;			 //dau cua chuc nang dau tien
	int cursorColor; //Mau con tro chon menu
};
struct _PLAYER
{
	string name; //Ten nguoi choi
	int wins = 0;	 //Dem so tran thang
	int rank; //Xep hang cua nguoi choi

	bool operator>(_PLAYER other);
	bool operator<(_PLAYER other);
	bool operator==(_PLAYER other);
};
//File stuffs
#define SAVED_LIST "savedlist.txt" //Ten cac file game duoc save
#define PLAYER_LIST "PlayerList.txt" //Thong tin cac player da choi game
#define WIDTH 1320
#define HEIGHT 700
#define X_CENTER WIDTH / 16 + 2
#define Y_CENTER HEIGHT / 32
#pragma comment (lib,"winmm.lib") //dung cho PlaySoundA()