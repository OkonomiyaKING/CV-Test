
// MFC_0325Dlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MFC_0325.h"
#include "MFC_0325Dlg.h"
#include "afxdialogex.h"
HWND hCombo;

#include <opencv2\opencv.hpp>
#pragma comment(lib, "opencv_core2413d.lib")
#pragma comment(lib, "opencv_highgui2413d.lib")
//#pragma comment(lib, "opencv_world2413d.lib")

//#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define Nam_Debug 1

//const char filename_src[] = "C:\\Users\\Hallo\\source\\repos\\0325_CvTEST\\Debug"; // 512x512 px 3 channels

// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC0325Dlg ダイアログ



CMFC0325Dlg::CMFC0325Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_0325_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC0325Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO, m_cComboBox);	// ★必須
}

BEGIN_MESSAGE_MAP(CMFC0325Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC0325Dlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO, &CMFC0325Dlg::OnCbnSelchangeCombo)
END_MESSAGE_MAP()


// CMFC0325Dlg メッセージ ハンドラー

BOOL CMFC0325Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GUIInit();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CMFC0325Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMFC0325Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMFC0325Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC0325Dlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CString csLanguage;
	Mat src_img;

	src_img = imread("C:\\Users\\Hallo\\source\\repos\\MFC_0325\\Dona.jpg", 1);

	if (src_img.data == NULL) {
		std::cout << "NULL" << std::endl;
	}

	//imshow("image", src_img);
	waitKey(0);

	cv::namedWindow("dona img", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);	// 動的サイズ取得
	cv::imshow("dona img", src_img);

	// 初期化時に塗りつぶす
//	cv::Mat red_img(cv::Size(640, 480), CV_8UC3, cv::Scalar(0, 0, 255));
//	cv::Mat white_img(cv::Size(640, 480), CV_8UC3, cv::Scalar::all(255));
//	cv::Mat black_img = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);

	// 初期化後に塗りつぶす
//	cv::Mat green_img = red_img.clone();
//	green_img = cv::Scalar(0, 255, 0);

//	cv::namedWindow("red image", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
//	cv::namedWindow("white image", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
//	cv::namedWindow("black image", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
//	cv::namedWindow("green image", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
//	cv::imshow("red image", red_img);
//	cv::imshow("white image", white_img);
//	cv::imshow("black image", black_img);
//	cv::imshow("green image", green_img);

	cv::waitKey(0);

}

#if 0
void CMFC0325Dlg::OnCbnSelchangeccombobox()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);         // 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);        // 小さいアイコンの設定

	int        err = 0, cbErr = 0;

	//m_Combo  = cComboBox.SelectedIndex;

	//if (!err)
	//{
	//	cbErr = m_xcCombo.InsertString(-1, _T("文字列1"));
	//	if (cbErr == CB_ERR || cbErr == CB_ERRSPACE) err = 1;
	//}
	//if (!err)
	//{
	//	cbErr = m_xcCombo.InsertString(-1, _T("文字列2"));
	//	if (cbErr == CB_ERR || cbErr == CB_ERRSPACE) err = 1;
	//}
	//if (!err)
	//{
	//	cbErr = m_xcCombo.InsertString(-1, _T("文字列3"));
	//	if (cbErr == CB_ERR || cbErr == CB_ERRSPACE) err = 1;
	//}
	//if (!err)
	//{
	//	m_xvCombo = 2;
	//	UpdateData(FALSE);
	//}

}
# endif


void CMFC0325Dlg::OnCbnSelchangeCombo()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	Picture();

	//CDialog::OnInitDialog();

	//SetIcon(m_hIcon, TRUE);         // 大きいアイコンの設定
	//SetIcon(m_hIcon, FALSE);        // 小さいアイコンの設定

	//int        err = 0, cbErr = 0;

}

void CMFC0325Dlg::GUIInit()
{
	m_cComboBox.AddString(_T("Dona"));
	m_cComboBox.AddString(_T("2nd"));
	m_cComboBox.AddString(_T("3rd"));

	m_cComboBox.SetCurSel(0);
}

void CMFC0325Dlg::Picture()
{
	Mat src_img;

	CString str;
	int iSelect = m_cComboBox.GetCurSel();
	//m_cComboBox.GetLBText(iSelect, str);

	switch (iSelect)
	{
	case 0:
		src_img = imread("C:\\Users\\Hallo\\source\\repos\\MFC_0325\\Dona.jpg", 1);

		if (src_img.data == NULL) {
			std::cout << "NULL" << std::endl;
		}

		waitKey(0);

		cv::namedWindow("dona img", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);	// 動的サイズ取得
		cv::imshow("dona img", src_img);
		break;
	case 1:
		src_img = imread("C:\\Users\\Hallo\\source\\repos\\MFC_0325\\neko.jpg", 1);

		if (src_img.data == NULL) {
			std::cout << "NULL" << std::endl;
		}

		waitKey(0);

		cv::namedWindow("neko img", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);	// 動的サイズ取得
		cv::imshow("neko img", src_img);
		break;
	case 2:
		src_img = imread("C:\\Users\\Hallo\\source\\repos\\MFC_0325\\Syn.jpg", 1);

		if (src_img.data == NULL) {
			std::cout << "NULL" << std::endl;
		}

		waitKey(0);

		cv::namedWindow("Syn img", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);	// 動的サイズ取得
		cv::imshow("Syn img", src_img);
		break;

	}

}
