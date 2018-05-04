
// MFC_0325Dlg.h : ヘッダー ファイル
//

#pragma once


// CMFC0325Dlg ダイアログ
class CMFC0325Dlg : public CDialogEx
{
// コンストラクション
public:
	CMFC0325Dlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_0325_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
public:
//	afx_msg void OnCbnSelchangeccombobox();
	CComboBox m_cComboBox;

	// ★画像を選ぶためのコンボボックス
	//int m_Combo;
	afx_msg void OnCbnSelchangeCombo();
	//CComboBox mc; // ★test
	void GUIInit();
	void Picture();
};
