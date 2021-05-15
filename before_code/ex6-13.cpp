#define LearningChapter "ex6-13"
//page 295

#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <CommCtrl.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
static LPCTSTR WindowClassName = _T(LearningChapter) _T(" Class");
static LPCTSTR WindowTitleName = _T(LearningChapter);
static const int WindowPosition[2] = { 400, 200 };
static const int WindowSize[2] = { 720, 480 };

//BOOL CALLBACK Dlg6_xProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_2Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_3Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_4Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_5Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_6Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_7Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_8Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_9Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_10Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_11Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_12Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_13Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE g_hInstance;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS WndClass;
	g_hInstance = hInstance;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = CreateSolidBrush(RGB(156, 156, 165));
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU6_3);
	WndClass.lpszClassName = WindowClassName;

	RegisterClass(&WndClass);
	hwnd = CreateWindow(WindowClassName, WindowTitleName,
		WS_OVERLAPPEDWINDOW,
		WindowPosition[0], WindowPosition[1],
		WindowSize[0], WindowSize[1],
		NULL, NULL, hInstance, NULL
	);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hDlg6_8 = NULL;
	static HINSTANCE hInstance;
	switch (iMsg) {
	case WM_CREATE:
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_6_3_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_3), hwnd, (DLGPROC)Dlg6_3Proc);
			break;
		case ID_6_4_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_4), hwnd, (DLGPROC)Dlg6_4Proc);
			break;
		case ID_6_5_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_5), hwnd, (DLGPROC)Dlg6_5Proc);
			break;
		case ID_6_6_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_6), hwnd, (DLGPROC)Dlg6_6Proc);
			break;
		case ID_6_7_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_7), hwnd, (DLGPROC)Dlg6_7Proc);
			break;
		case ID_6_8_MENU:
			if (!IsWindow(hDlg6_8))
			{
				hDlg6_8 = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG6_7), hwnd, (DLGPROC)(Dlg6_8Proc));
				ShowWindow(hDlg6_8, SW_SHOW);
			}
			break;
		case ID_6_9_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_9), hwnd, (DLGPROC)Dlg6_9Proc);
			break;
		case ID_6_10_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_10), hwnd, (DLGPROC)Dlg6_10Proc);
			break;
		case ID_6_11_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_11), hwnd, (DLGPROC)Dlg6_11Proc);
			break;
		case ID_6_12_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_12), hwnd, (DLGPROC)Dlg6_12Proc);
			break;
		case ID_6_13_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_13), hwnd, (DLGPROC)Dlg6_13Proc);
			break;
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

/*
BOOL CALLBACK Dlg6_xProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}
*/

void MakeColumn(HWND hDlg)
{
	LPCTSTR name[2] = { _T("이름"), _T("전화번호") };
	LVCOLUMN lvCol = { 0, };
	HWND hList = GetDlgItem(hDlg, IDC_LIST_MEMBER);

	lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvCol.fmt = LVCFMT_LEFT;

	RECT rt;
	GetClientRect(hList, &rt);
	int cxRatio[2] = { 30, 70 };

	for (int i = 0; i < 2; i++)
	{
		lvCol.cx = rt.right * cxRatio[i] / 100;
		lvCol.iSubItem = i;
		lvCol.pszText = (LPWSTR)name[i];
		SendMessage(hList, LVM_INSERTCOLUMN, (WPARAM)i, (LPARAM)&lvCol);
	}
}

void InsertData(HWND hDlg)
{
	LVITEM item;
	HWND hList = GetDlgItem(hDlg, IDC_LIST_MEMBER);
	TCHAR name[][20] = { _T("김철수"), _T("김영희") };
	TCHAR phone[][20] = { _T("010-1267-4773"), _T("010-8483-9910") };

	for (int i = 0; i < 2; i++)
	{
		item.mask = LVIF_TEXT;
		item.iItem = i;
		item.iSubItem = 0;
		item.pszText = name[i];
		ListView_InsertItem(hList, &item);
		ListView_SetItemText(hList, i, 1, phone[i]);
	}
}

void InsertDataNew(HWND hDlg)
{
	HWND hList = GetDlgItem(hDlg, IDC_LIST_MEMBER);
	TCHAR name[20];
	TCHAR phone[20];

	GetDlgItemText(hDlg, IDC_EDIT_NAME, name, sizeof(name) / sizeof(TCHAR));
	GetDlgItemText(hDlg, IDC_EDIT_PHONE, phone, sizeof(phone) / sizeof(TCHAR));

	SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
	SetDlgItemText(hDlg, IDC_EDIT_PHONE, _T(""));
	if (_tcscmp(name, _T("")) == 0) return;
	if (_tcscmp(phone, _T("")) == 0) return;

	int count = ListView_GetItemCount(hList);
	LVITEM item;
	item.mask = LVIF_TEXT;
	item.iItem = count;
	item.iSubItem = 0;
	item.pszText = name;
	ListView_InsertItem(hList, &item);
	ListView_SetItemText(hList, count, 1, phone);
}

int SelectItem(HWND hDlg, LPARAM lParam)
{
	LPNMLISTVIEW nlv = (LPNMLISTVIEW)lParam;
	HWND hList = GetDlgItem(hDlg, IDC_LIST_MEMBER);
	TCHAR name[20], phone[20];
	ListView_GetItemText(hList, nlv->iItem, 0, name, 20);
	ListView_GetItemText(hList, nlv->iItem, 1, phone, 20);
	SetDlgItemText(hDlg, IDC_EDIT_NAME, name);
	SetDlgItemText(hDlg, IDC_EDIT_PHONE, phone);
	
	return nlv->iItem;
}

void ModifyItem(HWND hDlg, int selection)
{
	static HWND hList = GetDlgItem(hDlg, IDC_LIST_MEMBER);
	TCHAR name[20], phone[20];

	GetDlgItemText(hDlg, IDC_EDIT_NAME, name, sizeof(name) / sizeof(TCHAR));
	GetDlgItemText(hDlg, IDC_EDIT_PHONE, phone, sizeof(phone) / sizeof(TCHAR));
	if (_tcscmp(name, _T("")) == 0) return;
	if (_tcscmp(phone, _T("")) == 0) return;
	ListView_SetItemText(hList, selection, 0, name);
	ListView_SetItemText(hList, selection, 1, phone);
	SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
	SetDlgItemText(hDlg, IDC_EDIT_PHONE, _T(""));
}

void DeleteItem(HWND hDlg, int selection)
{
	static HWND hList = GetDlgItem(hDlg, IDC_LIST_MEMBER);
	ListView_DeleteItem(hList, selection);
	SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
	SetDlgItemText(hDlg, IDC_EDIT_PHONE, _T(""));
}

BOOL CALLBACK Dlg6_2Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	LPCTSTR str;
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return 1;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_BUTTON_PRINT:
			hdc = GetDC(hDlg);
			str = _T("The Quick Brown Fox Jumps Over the Lazy Dog.");
			TextOut(hdc, 10, 10, str, _tcslen(str));
			ReleaseDC(hDlg, hdc);
			break;
		case ID_BUTTON_END:
			EndDialog(hDlg, 0);
			break;
		}
	}
	return 0;
}

BOOL CALLBACK Dlg6_3Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hButton;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		hButton = GetDlgItem(hDlg, ID_PAUSE);
		EnableWindow(hButton, FALSE);
		return 1;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_START:
			hButton = GetDlgItem(hDlg, ID_START);
			EnableWindow(hButton, FALSE);
			hButton = GetDlgItem(hDlg, ID_PAUSE);
			EnableWindow(hButton, TRUE);
			break;
		case ID_PAUSE:
			hButton = GetDlgItem(hDlg, ID_START);
			EnableWindow(hButton, TRUE);
			hButton = GetDlgItem(hDlg, ID_PAUSE);
			EnableWindow(hButton, FALSE);
			break;
		case ID_CLOSE:
			EndDialog(hDlg, 0);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}

	return FALSE;
}

BOOL CALLBACK Dlg6_4Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	TCHAR word[100];

	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_BUTTON_COPY:
			GetDlgItemText(hDlg, IDC_EDIT_SOURCE, word, 100);
			SetDlgItemText(hDlg, IDC_EDIT_COPY, word);
			break;
		case ID_BUTTON_CLEAR:
			SetDlgItemText(hDlg, IDC_EDIT_SOURCE, _T(""));
			SetDlgItemText(hDlg, IDC_EDIT_COPY, _T(""));
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK Dlg6_5Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static int Check[3], Radio;
	TCHAR hobby[][30] = { _T("독서"), _T("음악감상"), _T("인터넷") };
	TCHAR sex[][30] = { _T("여자"), _T("남자") };
	TCHAR output[200];

	switch (iMsg)
	{
	case WM_INITDIALOG:
		CheckRadioButton(hDlg, IDC_RADIO_FEMALE, IDC_RADIO_MALE, IDC_RADIO_FEMALE);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_CHECK_READING:
			Check[0] = 1 - Check[0];
			break;
		case IDC_CHECK_MUSIC:
			Check[1] = 1 - Check[1];
			break;
		case IDC_CHECK_INTERNET:
			Check[2] = 1 - Check[2];
			break;
		case IDC_RADIO_FEMALE:
			Radio = 0;
			break;
		case IDC_RADIO_MALE:
			Radio = 1;
			break;
		case IDC_BUTTON_OUTPUT:
			_stprintf_s(output, _T("선택한 취미는 %s %s %s입니다.\r\n")
				_T("선택한 성별은 %s입니다."),
				Check[0] ? hobby[0] : _T(""), Check[1] ? hobby[1] : _T(""), Check[2] ? hobby[2] : _T(""),
				sex[Radio]);
			SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, output);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK Dlg6_6Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hCombo;
	static int selection;
	TCHAR name[50];

	switch (iMsg)
	{
	case WM_INITDIALOG:
		hCombo = GetDlgItem(hDlg, IDC_COMBO_LIST);
		return TRUE;
	case WM_COMMAND:

		if (HIWORD(wParam) == EN_CHANGE)
		{
			TCHAR edit_text[50];
			GetDlgItemText(hDlg, IDC_EDIT_NAME, edit_text, sizeof(edit_text) / sizeof(TCHAR));
			//if (edit_text[_tcslen(edit_text) - 1] == _T('\n'))
			if (edit_text[_tcslen(edit_text) - 2] == VK_RETURN)	//위 주석과 같은 뜻!
			{
				edit_text[_tcslen(edit_text) - 2] = _T('\0');
				SendMessage(hDlg, WM_COMMAND, (WPARAM)IDC_BUTTON_INSERT, 0);
			}
			//Edit 컨트롤에서 Enter키 처리법->
			//반환 설정 | 여러 줄 | 자동 VScroll ->이 세 옵션을 True로 설정한다!!
		}
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_INSERT:
			GetDlgItemText(hDlg, IDC_EDIT_NAME, name, sizeof(name) / sizeof(TCHAR));
			SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
			if (_tcscmp(name, _T("")) != 0)
				SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)name);
			return FALSE;
		case IDC_BUTTON_DELETE:
			SendMessage(hCombo, CB_DELETESTRING, selection, 0);
			return FALSE;
		case IDC_COMBO_LIST:
			if (HIWORD(wParam) == CBN_SELCHANGE)
				selection = (int)SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			//MessageBox(hDlg, _T("LDC_COMBO_LIST 메시지 발생"), _T(""), MB_OK);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK Dlg6_7Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	TCHAR namebuff[64];
	int sznamebuff = sizeof(namebuff) / sizeof(TCHAR);
	static HWND hListBox;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		hListBox = GetDlgItem(hDlg, IDC_LIST_NAME);
		return TRUE;
	case WM_COMMAND:
		if (HIWORD(wParam) == EN_CHANGE)
		{
			GetDlgItemText(hDlg, IDC_EDIT_NAME, namebuff, sznamebuff);
			if (_tcscmp(namebuff, _T("\r\n")) == 0)
				SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
			else if (namebuff[_tcslen(namebuff) - 2] == VK_RETURN)
				SendMessage(hDlg, WM_COMMAND, (WPARAM)IDC_BUTTON_INSERT, 0);
		}
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_INSERT:
			GetDlgItemText(hDlg, IDC_EDIT_NAME, namebuff, sznamebuff);
			SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
			if (_tcscmp(namebuff, _T("")) != 0)
				SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)namebuff);
			break;
		case IDC_BUTTON_DELETE:
			SendMessage(hListBox, LB_DELETESTRING, (WPARAM)SendMessage(hListBox, LB_GETCURSEL, 0, 0), 0);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK Dlg6_8Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	TCHAR namebuff[64];
	int sznamebuff = sizeof(namebuff) / sizeof(TCHAR);
	static HWND hListBox;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		hListBox = GetDlgItem(hDlg, IDC_LIST_NAME);
		return TRUE;
	case WM_COMMAND:
		if (HIWORD(wParam) == EN_CHANGE)
		{
			GetDlgItemText(hDlg, IDC_EDIT_NAME, namebuff, sznamebuff);
			if (_tcscmp(namebuff, _T("\r\n")) == 0)
				SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
			else if (namebuff[_tcslen(namebuff) - 2] == VK_RETURN)
				SendMessage(hDlg, WM_COMMAND, (WPARAM)IDC_BUTTON_INSERT, 0);
		}
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_INSERT:
			GetDlgItemText(hDlg, IDC_EDIT_NAME, namebuff, sznamebuff);
			SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
			if (_tcscmp(namebuff, _T("")) != 0)
				SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)namebuff);
			break;
		case IDC_BUTTON_DELETE:
			SendMessage(hListBox, LB_DELETESTRING, (WPARAM)SendMessage(hListBox, LB_GETCURSEL, 0, 0), 0);
			break;
		case IDCANCEL:
			DestroyWindow(hDlg);
			break;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK Dlg6_9Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		MakeColumn(hDlg);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK Dlg6_10Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		MakeColumn(hDlg);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_INSERT:
			InsertData(hDlg);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK Dlg6_11Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		MakeColumn(hDlg);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_INSERT:
			InsertDataNew(hDlg);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK Dlg6_12Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	LPNMHDR hdr;
	HWND hList;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		MakeColumn(hDlg);
		return TRUE;
	case WM_NOTIFY:
		hdr = (LPNMHDR)lParam;
		hList = GetDlgItem(hDlg, IDC_LIST_MEMBER);
		if (hdr->hwndFrom == hList && hdr->code == LVN_ITEMCHANGING)
			SelectItem(hDlg, lParam);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_INSERT:
			InsertDataNew(hDlg);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK Dlg6_13Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	LPNMHDR hdr;
	HWND hList;
	static int selection;
	static const int UNSELECTED = -1;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		selection = UNSELECTED;
		MakeColumn(hDlg);
		return TRUE;
	case WM_NOTIFY:
		hdr = (LPNMHDR)lParam;
		hList = GetDlgItem(hDlg, IDC_LIST_MEMBER);
		if (hdr->hwndFrom == hList && hdr->code == LVN_ITEMCHANGING)
			selection = SelectItem(hDlg, lParam);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_INSERT:
			InsertDataNew(hDlg);
			break;
		case IDC_BUTTON_MODIFY:
			if (selection == UNSELECTED) break;
			ModifyItem(hDlg, selection);
			selection = UNSELECTED;
			return FALSE;
		case IDC_BUTTON_DELETE:
			if (selection == UNSELECTED) break;
			DeleteItem(hDlg, selection);
			selection = UNSELECTED;
			return FALSE;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}
