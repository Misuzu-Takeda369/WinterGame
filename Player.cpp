#include <Novice.h>
#include "Player.h"
#include "Base.h"

Player::Player()
{
	base_.Pos_.x = 100.0f;
	base_.Pos_.y = 200.0f;
	base_.Speed_ = {
		2.0f,0.0f
	};
	base_.Acceleration_ = {
		0.0f,0.0f
	};

	base_.Radish_ = {
		32.0f,32.0f
	};
	base_.Color_ = WHITE;
	base_.Hp_ = 2;
	playerMoving_ = false;
	playerShape_ = nomal;
	scroll_ = {
		0.0f,0.0f
	};
}

Player::~Player()
{

}

void Player::Draw() {
	Novice::DrawEllipse(base_.Pos_.x- scroll_.x, base_.Pos_.y, base_.Radish_.x, base_.Radish_.y, 0.0f, base_.Color_, kFillModeSolid);
};

void Player::Move(char *keys,char *preKeys) {

	//上下移動
	if (playerMoving_) {

		//自動で動いていいよサインが出ている時はX方向は自動で動く
		base_.Pos_.x += base_.Speed_.x;
		//ライン移動
		if (preKeys[DIK_W] == 0 && keys[DIK_W] != 0) {
			base_.Pos_.y = 250;
		}
		else if (preKeys[DIK_S] == 0 && keys[DIK_S] != 0) {
			base_.Pos_.y = 550;
		}

	}
	else {
		if (keys[DIK_A]) {
			playerMoving_ = true;
		}
		
	}

	
}

void Player::Scroll() {
	if (playerMoving_) {
		base_.Pos_.x + base_.Speed_.x;

		if (base_.Pos_.x >=640.0f) {
			scroll_.x += base_.Speed_.x;
			
		}
		else {
			scroll_.x = 0.0f;
		}
	}
};

void Player::Change(char* keys, char* preKeys) {

	//プレイヤーのモードチェンジ
	if ((preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) && (playerShape_==nomal)) {
		playerShape_ = box;
	}
	else if ((preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) && (playerShape_ == box)) {
		playerShape_ = nomal;
	}

	//状態変化
	if (playerShape_ == nomal) {
		base_.Color_ = WHITE;
		base_.Speed_.x = 2.0f;
	}
	else {
		base_.Color_ = BLACK;
		base_.Speed_.x = 4.0f;
	}
}