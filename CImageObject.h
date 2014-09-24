/* キャライメージクラス */
class CImageObject
{
	public:
		int m_id;
		int m_x;
		int m_y;

	public:
		virtual void DrawCharacter(void)=0;//抽象クラス
};