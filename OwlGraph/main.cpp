// #include <iostream>
// #include <windows.h>
//
// #include "Window.h"
//
//
//
// Owl::Graph::Window* window;
//
// int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
// 	_In_opt_ HINSTANCE hPrevInstance,
// 	_In_ LPWSTR lpCmdLine,
// 	_In_ int nCmdShow
// )
// {
//     nCmdShow = true;
//
// 	window = new Owl::Graph::Window();
//     //
//     // if (AllocConsole()) {
//     //     freopen("CONOUT$", "w", stdout);
//     //     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
//     //     SetWindowPos(GetConsoleWindow(), 0, 1200, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
//     // }
//     return MessageBox(NULL, L"hello, world", L"caption", 0);
//
//
//     HWND hwnd = CreateWindowEx(
//         0,                              // Optional window styles.
//         L"Sample Window Class",                     // Window class
//         L"Learn to Program Windows",    // Window text
//         WS_OVERLAPPEDWINDOW,            // Window style
//
//         // Size and position
//         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//
//         NULL,       // Parent window    
//         NULL,       // Menu
//         hInstance,  // Instance handle
//         NULL        // Additional application data
//     );
//
//     if (hwnd == NULL)
//     {
//         return 0;
//     }
//
//     ShowWindow(hwnd, nCmdShow);
//
//     while(IsWindowVisible(hwnd))
//     {
// 	    
//     }
//     std::cout << "test" << std::endl;
// 	delete window;
// }


// #define UNICODE
// #define _UNICODE
#include <iostream>
#include <windows.h>
#include <tchar.h>

const TCHAR CLSNAME[] = L"helloworldWClass";
LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PTSTR cmdline,
    int cmdshow)
{
    HWND hwnd;

    if (AllocConsole()) {
        freopen("CONOUT$", "w", stdout);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        SetWindowPos(GetConsoleWindow(), 0, 1200, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    }

    MSG         Msg;
    WNDCLASSEX  WndClsEx = { 0 };

    WndClsEx.cbSize = sizeof(WNDCLASSEX);
    WndClsEx.style = CS_HREDRAW | CS_VREDRAW;
    WndClsEx.lpfnWndProc = WndProc;
    WndClsEx.hInstance = hInst;
    WndClsEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClsEx.lpszClassName = L"ClassName";
    WndClsEx.hIconSm = LoadIcon(hInst, IDI_APPLICATION);

    RegisterClassEx(&WndClsEx);

    hwnd = CreateWindowEx(
        WS_EX_LEFT,
        L"ClassName",
        L"Window Title",
        // (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX),
        (WS_THICKFRAME | WS_MAXIMIZEBOX),
        0,
        0,
        0,
        0,
        NULL,
        NULL,
        hInst,
        NULL);

    SetWindowLong(hwnd, GWL_STYLE, 0);

    // SetWindowLong(hwnd, GWL_STYLE, ~(WS_CAPTION | WS_THICKFRAME));
    // SetWindowLong(hwnd, GWL_EXSTYLE, ~(WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE));
    ShowWindow(hwnd, cmdshow);
    UpdateWindow(hwnd);

    while (GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch (Msg)
    {
    case WM_DESTROY:
        PostQuitMessage(WM_QUIT);
        break;
    case WM_PAINT:
    {
        /* */
        PAINTSTRUCT ps;
        HDC         hdc;
        RECT        rc;
        hdc = BeginPaint(hwnd, &ps);

        GetClientRect(hwnd, &rc);
        SetTextColor(hdc, 0);
        SetBkMode(hdc, TRANSPARENT);
        DrawText(hdc, L"HELLO WORLD", -1, &rc, DT_CENTER | DT_SINGLELINE | DT_VCENTER);

        EndPaint(hwnd, &ps);
        /* */
        break;
    }
    break;
    default:
        return DefWindowProc(hwnd, Msg, wParam, lParam);
    }
    return 0;
}