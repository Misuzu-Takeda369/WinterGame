#pragma once
typedef struct Vector2 {
	float x;
	float y;
};

typedef struct Base {
	Vector2 Pos_;
	Vector2 Speed_;
	Vector2 Acceleration_;
	Vector2 Radish_;
	int Color_;
	int Hp_;
};

enum Mode
{
	Title, TOption, Select, Save, Road, Play, POption, over, retry, clear
};

enum PlayerShape
{
	nomal,box
};

//•ÏŒ`‚ÌÅ‘åL‚Ñ”
const int PBoxmaxNum = 10;