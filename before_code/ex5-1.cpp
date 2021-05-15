#define LearningChapter "ex5-1"
//page 185

#include <Windows.h>
#include <tchar.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
static LPCTSTR WindowClassName = _T(LearningChapter) _T(" Class");
static LPCTSTR WindowTitleName = _T(LearningChapter);
static const int WindowPosition[2] = { 400, 200 };
static const int WindowSize[2] = { 720, 480 };

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
	WndClass.hbrBackground = CreateSolidBrush(RGB(156, 156, 166));
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU5_1);
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

	HACCEL hAccel = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR5_1));

	while (GetMessage(&msg, NULL, 0, 0)) {
		if (!TranslateAccelerator(hwnd, hAccel, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
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
			MessageBox(hwnd, _T("ID_FILENEW"), _T(""), MB_OK);
			break;
		case ID_FILEOPEN:
			MessageBox(hwnd, _T("ID_FILEOPEN"), _T(""), MB_OK);
			break;
		case ID_FILESAVE:
			MessageBox(hwnd, _T("ID_FILESAVE"), _T(""), MB_OK);
			break;
		case ID_EXIT:
			MessageBox(hwnd, _T("ID_EXIT"), _T(""), MB_OK);
			break;
		case ID_EDITUNDO:
			MessageBox(hwnd, _T("ID_EDITUNDO"), _T(""), MB_OK);
			break;
		case ID_EDITCOPY:
			MessageBox(hwnd, _T("ID_EDITCOPY"), _T(""), MB_OK);
			break;
		case ID_EDITPASTE:
			MessageBox(hwnd, _T("ID_EDITPASTE"), _T(""), MB_OK);
			break;
		case ID_HELP:
			MessageBox(hwnd, _T("ID_HELP"), _T(""), MB_OK);
			break;
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
