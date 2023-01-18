#include <Novice.h>
#include "Player.h"
#include "Function.h"

const char kWindowTitle[] = "CG1A_17_タケダミスズ_";

int WindowX = 1280;
int WindowY = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, WindowX, WindowY);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Mode mode = Mode::Title;
	Player *player = new Player;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		switch (Mode::Play)
		{
		case Title:

			break;

		case TOption:

	
			break;

		case Select:

			break;

		case Save:

			break;
		case Road:

			break;

		case Play:

			//プレイヤー関連
			
			player->Move(keys, preKeys);
			
			player->Scroll();
			player->Change(keys, preKeys);
			player->Draw();

			break;

		case POption:

			break;
		case over:

			break;
		case retry:

			break;
		case clear:

			break;
		}
		///
		/// ↑更新処理ここまで
		///
		Novice::ScreenPrintf(10, 10, "Posx:%2f", player->GetPlayerPosx());
		Novice::ScreenPrintf(10, 30, "Posy:%2f", player->GetPlayerPosy());
		Novice::ScreenPrintf(10, 50, "scrollx:%.2f", player->GetScrollx());
		//Novice::ScreenPrintf(10, 50, "scrollx:%2f", player->GetScrollx());
		Novice::ScreenPrintf(10, 90, "speedX:%.2f", player->GetPlayerSpeedx());

		Novice::ScreenPrintf(10, 130, "Shape:%d", player->GetPlayerShape());
		
		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
