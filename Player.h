#pragma once
#include "Base.h"

class Player
{
public:
	Player();
	~Player();

	/// <summary>
	/// 変数
	/// </summary>
	///プレイヤー本体関連の変数
	float GetPlayerPosx() { return base_.Pos_.x; };
	float GetPlayerPosy() { return base_.Pos_.y; };
	float GetPlayerSpeedx() { return base_.Speed_.x; };
	float GetPlayerSpeedy() { return base_.Speed_.y; };

	float GetPlayerAccelerationx() { return base_.Acceleration_.x; };
	float GetPlayerAccelerationy() { return base_.Acceleration_.y; };

	float GetPlayerRadishx() { return base_.Radish_.x; };
	float GetPlayerRadishy() { return base_.Radish_.y; };

	int GetPlayerColor() { return base_.Color_; };
	int GetPlayerHp() { return base_.Hp_; };
	///動いているか
	bool GetPlayerMoving() { return playerMoving_; };
	///姿関連
	int GetPlayerShape() {	return  playerShape_;};
	
	float GetPBoxModPosx() {return PBoxModPos_[PBoxNum_].x;};
	float GetPBoxModPosy() { return PBoxModPos_[PBoxNum_].y; };
	bool GetPBoxModflag() { return PBoxModflag_[PBoxNum_]; };
	///スクロール
	float GetScrollx() { return scroll_.x; };
	float GetScrolly() { return scroll_.y; };
/// <summary>
/// 関数
/// </summary>
	void Move(char* keys, char* preKeys);
	void Draw();
	void Scroll();
	void Change(char* keys, char* preKeys);

private:

	/// <summary>
	/// 変数
	/// </summary>
	///プレイヤー本体関連の変数
	Base base_;
	///動いているか
	bool playerMoving_;
	///姿関連
	int playerShape_;
	int PBoxNum_;
	Vector2 PBoxModPos_[PBoxmaxNum]{

	};
	bool PBoxModflag_[PBoxmaxNum]{

	};

	///スクロール
	Vector2 scroll_;
};

