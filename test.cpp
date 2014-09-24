#include "DxLib.h"
#include "Charcter.h"
#include "ImageTable.h"

void CheckKey(CCharcter* player);

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){

		// DXライブラリ初期化
		ChangeWindowMode( TRUE ) ;
        if(DxLib_Init() == -1 ) 
		{
			return -1;
		}

		int id = LoadGraph(_T("画像\\キャラクタ00.png"));
		CCharcter* player  = new CCharcter(id);

		while(1)
		{
			SetDrawScreen( DX_SCREEN_BACK ) ;
			// 画面を初期化(真っ黒にする)
			ClearDrawScreen();
			
			// 自機
			{
				CheckKey(player);
				player->DrawCharcter();
			}
			player->m_pEquipment.DrawShot();
			player->m_pEquipment.MoveShot();
			player->m_pEquipment.CheckShot();
			// 裏画面の内容を表画面にコピーする
			ScreenFlip() ;			
			// Windows 特有の面倒な処理をＤＸライブラリにやらせる
			// -1 が返ってきたらループを抜ける
			if( ProcessMessage() < 0 ) break ;

			// もしESCキーが押されていたらループから抜ける
			if( CheckHitKey( KEY_INPUT_ESCAPE ) ) break ;
		}


		// DXライブラリ終了処理
        DxLib_End();
        return 0;
}

void CheckKey(CCharcter* player)
{
				if(CheckHitKey(KEY_INPUT_UP) == 1)
					player->m_y -= 3;
				if(CheckHitKey(KEY_INPUT_DOWN) == 1)
					player->m_y += 3;
				if(CheckHitKey(KEY_INPUT_LEFT) == 1)
					player->m_x -= 3;
				if(CheckHitKey(KEY_INPUT_RIGHT) == 1)
					player->m_x += 3 ;

				if(player->m_x < 0 )
					player->m_x = 0 ;
				if(player->m_x > 640 - 64)
					player->m_x = 640 - 64;
				if(player->m_y < 0 )
					player->m_y = 0 ;
				if(player->m_y > 480 - 64)
					player->m_y = 480 - 64;

				if(CheckHitKey(KEY_INPUT_SPACE) == 1)
				{
					player->m_pEquipment.Add(player->m_id, player->m_x, player->m_y);
				}
}