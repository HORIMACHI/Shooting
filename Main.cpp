#include "DxLib.h"
#include "Character.h"
#include "ShootingScene.h"

//#include "ImageTable.h"

void CheckKey(CCharacter* player, int shotid);

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){

		// DX���C�u����������
		ChangeWindowMode( TRUE ) ;
        if(DxLib_Init() == -1 ) 
		{
			return -1;
		}

		CShootingScene CShootingScene;
		SetDrawScreen( DX_SCREEN_BACK ) ;
		while(1)
		{		
			ClearDrawScreen();
			CShootingScene.DrawImage();
			ScreenFlip();			
			if( ProcessMessage() < 0 ) break ;
#ifdef _DEBUG
			if( CheckHitKey( KEY_INPUT_ESCAPE ) ) break ;
#endif
		}

		// DX���C�u�����I������
        DxLib_End();
        return 0;
}
