
// MFC_0325.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMFC0325App:
// このクラスの実装については、MFC_0325.cpp を参照してください
//

class CMFC0325App : public CWinApp
{
public:
	CMFC0325App();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMFC0325App theApp;
