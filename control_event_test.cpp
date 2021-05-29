#define LearningChapter "Control Event Test"
//page xxx

#include <Windows.h>
#include <tchar.h>
//#include "resource.h"

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
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;//MAKEINTRESOURCE(IDR_MENU0_0);
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
	HDC hdc;
	static int x;
	static int y;
	static BOOL bnowDraw = FALSE;


	static int isLBUTTONDOWN;
	static int isLBUTTONUP ;
	static int isLBUTTONDCLICK ;

	static int isMOUSEMOVE ;
		static int movePosX;
		static int movePosY;

	static int isRBUTTONDOWN;
	static int isRBUTTONUP;
	static int isRBUTTONDCLICK;

	static int isMBUTTONDOWN;
	static int isMBUTTONUP;
	static int isMBUTTONDCLICK;

	static int isMOUSEWHEEL;
		static int wheel_zDelta;
		static int wheel_xPos;
		static int wheel_yPos;

	static int isKEYDOWN;
		static WPARAM isKEYDOWNwParam = 0;
	static int isKEYUP= -1;
	static int isCHAR;
		static WPARAM isCHARwParam = 0;

	//static int 변수를 하나씩 추가할 때마다 1씩 더한다
	const int controlEvent = 14;

	switch (iMsg) {
	case WM_CREATE:
		SetTimer(hwnd, 1, 10, NULL);
		return 0;


	case WM_LBUTTONDOWN:
		isLBUTTONDOWN++;
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		bnowDraw = TRUE;
		return 0;

	case WM_LBUTTONUP:
		isLBUTTONUP++;
		bnowDraw = FALSE;
		return 0;

	case WM_LBUTTONDBLCLK:
		isLBUTTONDCLICK++;
		InvalidateRect(hwnd, NULL, TRUE);
		return 0;

	case WM_MOUSEMOVE:
		isMOUSEMOVE++;
		movePosX = LOWORD(lParam);
		movePosY = HIWORD(lParam);
		if (bnowDraw == TRUE) {
			hdc = GetDC(hwnd);
			MoveToEx(hdc, x, y, NULL);
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			LineTo(hdc, x, y);
			ReleaseDC(hwnd, hdc);
		}
		return 0;

	case WM_RBUTTONDOWN:
		isRBUTTONDOWN++;
		return 0;

	case WM_RBUTTONUP:
		isRBUTTONUP++;
		return 0;

	case WM_RBUTTONDBLCLK:
		isRBUTTONDCLICK++;
		return 0;

	case WM_MBUTTONDOWN:
		isMBUTTONDOWN++;
		return 0;

	case WM_MBUTTONUP:
		isMBUTTONUP++;
		return 0;

	case WM_MBUTTONDBLCLK:
		isMBUTTONDCLICK++;
		return 0;

	case WM_MOUSEWHEEL:
		isMOUSEWHEEL++;
		wheel_zDelta = (short)HIWORD(wParam);
		wheel_xPos = LOWORD(lParam);
		wheel_yPos = HIWORD(lParam);
		return 0;

	case WM_KEYDOWN:
		isKEYDOWN++;
		isKEYDOWNwParam = wParam;
		if (wParam == VK_SPACE) {
			isLBUTTONDOWN = 0;
			isLBUTTONUP = 0;
			isLBUTTONDCLICK = 0;
			isMOUSEMOVE = 0;

			isRBUTTONDOWN = 0;
			isRBUTTONUP = 0;
			isRBUTTONDCLICK = 0;
			isMBUTTONDOWN = 0;
			isMBUTTONUP = 0;
			isMBUTTONDCLICK = 0;

			isMOUSEWHEEL = 0;
			wheel_zDelta = 0;
			wheel_xPos = 0;
			wheel_yPos = 0;

			movePosX = 0;
			movePosY = 0;

			isKEYDOWN = 0;
			isKEYDOWNwParam = 0;
			isKEYUP = -1;
			isCHAR = -1;
			isCHARwParam = 0;
		}
		return 0;

	case WM_KEYUP:
		isKEYUP++;
		return 0;

	case WM_CHAR:
		isCHAR++;
		isCHARwParam = wParam;
		return 0;


	case WM_TIMER:
		switch (wParam)
		{
		case 1:
		{
			TCHAR buff[controlEvent][256];
			hdc = GetDC(hwnd);
			_stprintf_s(buff[0], 256, _T("isLBUTTONDOWN(%d)         "), isLBUTTONDOWN);
			_stprintf_s(buff[1], 256, _T("isLBUTTONUP(%d)           "), isLBUTTONUP);
			_stprintf_s(buff[2], 256, _T("isLBUTTONDCLICK(%d)       "), isLBUTTONDCLICK);
			_stprintf_s(buff[3], 256, _T("isMOUSEMOVE(%d)           "), isMOUSEMOVE);
			_stprintf_s(buff[4], 256, _T("isRBUTTONDOWN(%d)         "), isRBUTTONDOWN);
			_stprintf_s(buff[5], 256, _T("isRBUTTONUP(%d)           "), isRBUTTONUP);
			_stprintf_s(buff[6], 256, _T("isRBUTTONDCLICK(%d)       "), isRBUTTONDCLICK);
			_stprintf_s(buff[7], 256, _T("isMBUTTONDOWN(%d)         "), isMBUTTONDOWN);
			_stprintf_s(buff[8], 256, _T("isMBUTTONUP(%d)           "), isMBUTTONUP);
			_stprintf_s(buff[9], 256, _T("isMBUTTONDCLICK(%d)       "), isMBUTTONDCLICK);
			_stprintf_s(buff[10], 256, _T("isMOUSEWHEEL(%d)          "), isMOUSEWHEEL);
			_stprintf_s(buff[11], 256, _T("isKEYDOWN(%d) w:%d        "), isKEYDOWN, isKEYDOWNwParam);
			_stprintf_s(buff[12], 256, _T("isKEYUP(%d)               "), isKEYUP);
			_stprintf_s(buff[13], 256, _T("isCHAR(%d) w:%d           "), isCHAR, isCHARwParam);
			for (int i = 0; i < controlEvent; i++)
				TextOut(hdc, 0, i * 20, buff[i], _tcslen(buff[i]));

			_stprintf_s(buff[10], 256, _T("zDelta:%d, xPos:%d, yPos:%d                              "), wheel_zDelta, wheel_xPos, wheel_yPos);
			TextOut(hdc, 200, 0, buff[10], _tcslen(buff[10]));
			_stprintf_s(buff[3], 256, _T("movePosX:%d, movePosY:%d                              "), movePosX, movePosY);
			TextOut(hdc, 200, 20, buff[3], _tcslen(buff[3]));
			ReleaseDC(hwnd, hdc);
		}
			break;
		}
		return 0;
	case WM_DESTROY:
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
