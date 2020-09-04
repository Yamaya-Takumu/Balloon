// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// 3Dマップ処理の説明[3Dmap.h]
// Author : Koki Nishiyama
//
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef _3DMAP_H_
#define _3DMAP_H_	 // ファイル名を基準を決める

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// インクルードファイル
//
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "scene_X.h"

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// マクロ定義
//
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// クラス
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class C3DMap
{
public:
	/* 列挙型 */
	typedef enum
	{
		MAP_STAGE_1 = 0,
		MAP_STAGE_2,
		MAP_MAX
	} MAP;
	/* 列挙型 */
	// 3Dオブジェクト
	typedef struct OBJECT
	{
		OBJECT()
		{
			nModelType = 0;
			pos = D3DVECTOR3_ZERO;
			rot = D3DVECTOR3_ZERO;
		}
		int nModelType;
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
	} OBJECT;
	// キャラクター
	typedef struct CHARACTER
	{
		CHARACTER()
		{
			nCharacter = 0;
			pos = D3DVECTOR3_ZERO;
			rot = D3DVECTOR3_ZERO;
		}
		int nCharacter;
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
	} CHARACTER;
	// ポリゴン
	typedef struct POLYGON
	{
		POLYGON()
		{
			nTexType = 0;
			pos = D3DVECTOR3_ZERO;
			rot = D3DVECTOR3_ZERO;
			size = D3DVECTOR2_ZERO;
			bBillboard = false;
			bZEneble = false;
			bLighting = false;
			bAlpha = false;
		}
		int nTexType;
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
		D3DXVECTOR2 size;
		bool bBillboard;
		bool bZEneble;
		bool bLighting;
		bool bAlpha;
	} POLYGON;
	// 床
	typedef struct FLOOR
	{
		FLOOR()
		{
			nTexType = 0;
			pos = D3DVECTOR3_ZERO;
			rot = D3DVECTOR3_ZERO;
			nBlockDepth = 0;
			nBlockWidth = 0;
			size = D3DVECTOR2_ZERO;
		}
		int nTexType;
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
		int nBlockDepth;
		int nBlockWidth;
		D3DXVECTOR2 size;
	} FLOOR;
	// 壁
	typedef struct WALL
	{
		WALL()
		{
			nTexType = 0;
			pos = D3DVECTOR3_ZERO;
			rot = D3DVECTOR3_ZERO;
			nBlockDepth = 0;
			nBlockWidth = 0;
			size = D3DVECTOR2_ZERO;
		}
		int nTexType;
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
		int nBlockDepth;
		int nBlockWidth;
		D3DXVECTOR2 size;
	} WALL;
	// 矩形の当たり判定
	typedef struct RECTCOLLISION
	{
		RECTCOLLISION()
		{
			pos = D3DVECTOR3_ZERO;	// 位置
			rot = D3DVECTOR3_ZERO;	// 回転
			size = D3DVECTOR3_ZERO;	// サイズ
			bPush = false;			// 押し出し処理
		}
		D3DXVECTOR3 pos;	// 位置
		D3DXVECTOR3 rot;	// 回転
		D3DXVECTOR3 size;	// サイズ
		bool bPush;			// 押し出し処理
	} RECTCOLLISION;
	// 球の当たり判定
	typedef struct SPHERECOLLISION
	{
		SPHERECOLLISION()
		{
			pos = D3DVECTOR3_ZERO;	// 位置
			fRadius = 0.0f;			// 半径
			bPush = false;			// 押し出し処理
		}
		D3DXVECTOR3 pos;	// 位置
		float fRadius;		// 半径
		bool bPush;			// 押し出し処理
	} SPHERECOLLISION;
	// 円柱の当たり判定
	typedef struct COLUMNCOLLISION
	{
		COLUMNCOLLISION()
		{
			pos = D3DVECTOR3_ZERO;	// 位置
			rot = D3DVECTOR3_ZERO;	// 回転
			bPush = false;			// 押し出し処理
			fRadius = 0.0f;			// 半径
			fVertical = 0.0f;		// 縦
		}
		D3DXVECTOR3 pos;	// 位置
		D3DXVECTOR3 rot;	// 回転
		bool bPush;			// 押し出し処理
		float fRadius;		// 半径
		float fVertical;	// 縦
	} COLUMNCOLLISION;

	/* 関数 */
	C3DMap();
	~C3DMap();
#ifdef _DEBUG
	static void Debug(void);
#endif // _DEBUG
	static HRESULT LoadCreate(MAP const &map);					// 読み込んだ情報を生成
	static void LoadScript(char* Add);
	static HRESULT Load(void);						// リソース情報読み込む設定
	// マネージャーの読み込み
	static HRESULT ManagerLoad(void);
	// スクリプトの読み込み
	static HRESULT ScriptLoad(void);
	static void UnLoad(void);						// 読み込んだリソース情報を開放する
protected:
private:
	/* 関数 */
	// キャラクター生成
	void CharaCreate(void);
	/* 変数 */
	static std::vector<std::vector<OBJECT>> m_vec_obj;
	static std::vector<std::vector<CHARACTER>> m_vec_char;
	static std::vector<std::vector<POLYGON>> m_vec_polygon;
	static std::vector<std::vector<FLOOR>> m_vec_floor;
	static std::vector<std::vector<WALL>> m_vec_wall;
	static std::vector<std::string> m_vec_String;					// ファイル情報読み書き用
	static D3DXVECTOR3 m_CollisionPos[3];
	int m_nType;									// タイプ
};

#endif