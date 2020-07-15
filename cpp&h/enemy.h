// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// 敵処理 [enemy.h]
// Author : KOKI NISHIYAMA
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef _ENEMY_H_
#define _ENEMY_H_

#define _CRT_SECURE_NO_WARNINGS

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// インクルードファイル
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "character.h"

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 前方宣言
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// クラス
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CEnemy : public CCharacter
{
public:
	/* 関数 */
	// 自分自身用
	CEnemy(CHARACTER const &character);
	virtual ~CEnemy();
	virtual void Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);
#ifdef _DEBUG
	void Debug(void);
#endif // _DEBUG
	// 当たった後の処理
	//	nObjType	: オブジェクトタイプ
	//	pScene		: 相手のシーン情報
	virtual void Scene_MyCollision(
		int const &nObjType = 0,	// オブジェクトタイプ
		CScene * pScene = NULL		// 相手のシーン情報
	);
	// 相手に当てられた後の処理
	//	nObjType	: オブジェクトタイプ
	//	pScene		: 相手のシーン情報
	virtual void Scene_OpponentCollision(
		int const &nObjType = 0,	// オブジェクトタイプ
		CScene * pScene = NULL		// 相手のシーン情報
	);
	// 敵が死んだときの関数
	virtual void Die(void);
	static HRESULT Load(void);								// 読み込み
	static void UnLoad(void);								// UnLoadする
protected:
	/* 列挙型 */
	/* 変数 */
	// 行動
private:
	/* 関数 */
	// AIアクション処理
	void Ai_Action(void);
	// AI移動処理
	void Ai_Move(void);
	/* 変数 */
};
#endif
