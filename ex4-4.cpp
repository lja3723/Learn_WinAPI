#define LearningChapter "ex4-4"

#include <Windows.h>
#include <tchar.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
static LPCTSTR WindowClassName = _T(LearningChapter) _T(" Class");
static LPCTSTR WindowTitleName = _T(LearningChapter);
static const int WindowPosition[2] = { 400, 200 };
static const int WindowSize[2] = { 720, 480 };

void wincmd_fileopen(HWND hwnd);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU4_4);
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
	switch (iMsg) {
	case WM_CREATE:
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_FILENEW:
			MessageBox(hwnd,
				_T("�� ������ ���ðڽ��ϱ�?"),
				_T("�� ���� ����"),
				MB_OKCANCEL);
			break;
		case ID_FILEOPEN:
			wincmd_fileopen(hwnd);
			break;
		case ID_EXIT:
			int answer = MessageBox(hwnd,
				_T("������ �����ϰ� �����ڽ��ϱ�?"),
				_T("������ ����"),
				MB_YESNOCANCEL);
			if (answer == IDYES)
				PostQuitMessage(0);
			break;
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

void wincmd_fileopen(HWND hwnd)
{
	OPENFILENAME OFN;
	TCHAR str[100], lpstrFile[100] = _T("");
	TCHAR filter[] = _T(
		"Every File(*.*)\0"
		"*.*\0"
		"Text File(*.txt, *.doc)\0"
		"*.txt;*.doc\0");

	memset(&OFN, 0, sizeof(OPENFILENAME));
	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = hwnd;
	OFN.lpstrFilter = filter;
	OFN.lpstrFile = lpstrFile;
	OFN.nMaxFile = 100;
	OFN.lpstrInitialDir = _T(".");
	if (GetOpenFileName(&OFN) != 0) {
		_stprintf_s(str, _T("%s ������ ���ڽ��ϱ�?"), OFN.lpstrFile);
		MessageBox(hwnd, str, _T("���� ����"), MB_OK);
	}
}