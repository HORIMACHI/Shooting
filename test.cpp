#include "DxLib.h"
#include "Charcter.h"
#include "ImageTable.h"

void CheckKey(CCharcter* player);

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){

		// DX���C�u����������
		ChangeWindowMode( TRUE ) ;
        if(DxLib_Init() == -1 ) 
		{
			return -1;
		}

		int id = LoadGraph(_T("�摜\\�L�����N�^00.png"));
		CCharcter* player  = new CCharcter(id);

		while(1)
		{
			SetDrawScreen( DX_SCREEN_BACK ) ;
			// ��ʂ�������(�^�����ɂ���)
			ClearDrawScreen();
			
			// ���@
			{
				CheckKey(player);
				player->DrawCharcter();
			}
			player->m_pEquipment.DrawShot();
			player->m_pEquipment.MoveShot();
			player->m_pEquipment.CheckShot();
			// ����ʂ̓��e��\��ʂɃR�s�[����
			ScreenFlip() ;			
			// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
			// -1 ���Ԃ��Ă����烋�[�v�𔲂���
			if( ProcessMessage() < 0 ) break ;

			// ����ESC�L�[��������Ă����烋�[�v���甲����
			if( CheckHitKey( KEY_INPUT_ESCAPE ) ) break ;
		}


		// DX���C�u�����I������
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