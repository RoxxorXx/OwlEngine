#include <iostream>
#include <windows.h>
#include <tchar.h>

#include "Window.h"


const TCHAR CLSNAME[] = L"helloworldWClass";
LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PTSTR cmdline, int cmdshow)
{
	if (AllocConsole())
	{
		freopen("CONOUT$", "w", stdout);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		SetWindowPos(GetConsoleWindow(), 0, 1200, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}

	MSG Msg;
	HWND hwnd;


	// WNDCLASSEX WndClsEx = {0};
	// WndClsEx.cbSize = sizeof(WNDCLASSEX);
	// WndClsEx.style = CS_HREDRAW | CS_VREDRAW;
	// WndClsEx.lpfnWndProc = WndProc;
	// WndClsEx.hInstance = hInst;
	// WndClsEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	// WndClsEx.lpszClassName = L"ClassName";
	// WndClsEx.hIconSm = LoadIcon(hInst, IDI_APPLICATION);


	// WNDCLASSEX WndClsEx = {};
	// WndClsEx.cbSize = sizeof(WNDCLASSEX);
	// WndClsEx.lpfnWndProc = WndProc;
	// WndClsEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	// WndClsEx.lpszClassName = L"ClassName";
	//
	//
	// RegisterClassEx(&WndClsEx);
	
	// hwnd = CreateWindowEx(
	// 	WS_EX_LEFT,
	// 	L"ClassName",
	// 	L"Window Title",
	// 	// (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX),
	// 	(WS_THICKFRAME | WS_MAXIMIZEBOX),
	// 	0,
	// 	0,
	// 	0,
	// 	0,
	// 	NULL,
	// 	NULL,
	// 	NULL,
	// 	NULL);
	//
	// ShowWindow(hwnd, cmdshow);


	// UpdateWindow(hwnd);

	// while (GetMessage(&Msg, NULL, 0, 0))
	// {
	// 	// TranslateMessage(&Msg);
	// 	// DispatchMessage(&Msg);
	// }
	auto w = Owl::Graph::Window();
	auto w1 = Owl::Graph::Window();
	while(true)
	{
		w.tupdate();
		w1.tupdate();
		if((GetAsyncKeyState('K') & 0x8000) != 0)
		{
			std::cout << "allah u akbar " << w.IsVisible() << std::endl;
			w.SetVisible(false);
			SoundSentry();
			// break;
		}
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	// switch (Msg)
	// {
	// // case WM_DESTROY:
	// // 	PostQuitMessage(WM_QUIT);
	// // 	break;
	// case WM_PAINT:
	// 	{
	// 		// /* */
	// 		// PAINTSTRUCT ps;
	// 		// HDC hdc;
	// 		// RECT rc;
	// 		// hdc = BeginPaint(hwnd, &ps);
	// 		//
	// 		// GetClientRect(hwnd, &rc);
	// 		// SetTextColor(hdc, 0);
	// 		// SetBkMode(hdc, TRANSPARENT);
	// 		// DrawText(hdc, L"HELLO WORLD", -1, &rc, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	// 		//
	// 		// EndPaint(hwnd, &ps);
	// 		// /* */
	// 		// break;
	// 	}
	// 	break;
	// default:
	// 	return DefWindowProc(hwnd, Msg, wParam, lParam);
	// }
	// return 0;
	return DefWindowProc(hwnd, Msg, wParam, lParam);
}
