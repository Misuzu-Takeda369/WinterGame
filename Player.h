#pragma once
#include "Base.h"

class Player
{
public:
	Player();
	~Player();

	/// <summary>
	/// �ϐ�
	/// </summary>
	///�v���C���[�{�̊֘A�̕ϐ�
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
	///�����Ă��邩
	bool GetPlayerMoving() { return playerMoving_; };
	///�p�֘A
	int GetPlayerShape() {	return  playerShape_;};
	
	float GetPBoxModPosx() {return PBoxModPos_[PBoxNum_].x;};
	float GetPBoxModPosy() { return PBoxModPos_[PBoxNum_].y; };
	bool GetPBoxModflag() { return PBoxModflag_[PBoxNum_]; };
	///�X�N���[��
	float GetScrollx() { return scroll_.x; };
	float GetScrolly() { return scroll_.y; };
/// <summary>
/// �֐�
/// </summary>
	void Move(char* keys, char* preKeys);
	void Draw();
	void Scroll();
	void Change(char* keys, char* preKeys);

private:

	/// <summary>
	/// �ϐ�
	/// </summary>
	///�v���C���[�{�̊֘A�̕ϐ�
	Base base_;
	///�����Ă��邩
	bool playerMoving_;
	///�p�֘A
	int playerShape_;
	int PBoxNum_;
	Vector2 PBoxModPos_[PBoxmaxNum]{

	};
	bool PBoxModflag_[PBoxmaxNum]{

	};

	///�X�N���[��
	Vector2 scroll_;
};

