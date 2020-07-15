
// Header
#include <windows.h>

// Callback Function Declaration
// __int64 __stdcall WndProc(unsigned __int64, unsigned __int64, __int64)
LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM);

// Windows GUI Main
// int __stdcall WinMain (HINSTANCE , HINSTANCE, char *, int)
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{

	// Variable Declaration
	MSG msg;
	HWND hwnd;
	TCHAR szAppName[] = TEXT("MyWindow");
	WNDCLASSEX wndcls;

	// Code

	// Initialize WNDCLASSEX struct members
	wndcls.cbSize = sizeof(WNDCLASSEX);
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.lpfnWndProc = WndProc;
	wndcls.lpszClassName = szAppName;
	wndcls.lpszMenuName = NULL;
	wndcls.hbrBackground = (HBRUSH) GetStockObject( BLACK_BRUSH );	// BLACK_BRUSH 	->  #define  BLACK_BRUSH 	0	// HGDIOBJ WINAPI GetStockObject( int);
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);			// HICON WINAPI LoadIcon(HINSTANCE, LPCWSTR)
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);			// HCURSOR WINAPI LoadCursor(HINSTANCE, LPCWSTR)
	wndcls.hInstance = hInstance;
	wndcls.hIconSm = LoadIcon(NULL, IDI_APPLICATION);		// HICON WINAPI LoadIcon(HINSTANCE, LPCWSTR)

	// Register WNDCLASS
	RegisterClassEx( &wndcls );		// ATOM WINAPI RegisterClassEx( LPWNDCLASS );

	// Creating the window on RAM
	hwnd = CreateWindow( szAppName,	// HWND WINAPI CreateWindow(LPCWSTR, LPCWSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID);
		TEXT("Mayur's Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	// Show The Window on Display
	ShowWindow(hwnd, SW_SHOWMINIMIZED);		//BOOL WINAPI ShowWindow(HWND, int);	// #define		SW_SHOWMINIMIZED	2

	// Set The Background Of The Window
	UpdateWindow(hwnd);				// BOOL WINAPI UpdateWindow(HWND);

	// Message Loop
	while( GetMessage(&msg, NULL, 0, 0) )	// BOOL GetMessage(MSG, HWND, UINT wMsgFilterMin, UINT wMsgFilterMax );
	{
		TranslateMessage(&msg);				// BOOL TranslateMessage(LPMSG);
		DispatchMessage(&msg);				// BOOL TranslateMessage(LPMSG);
	}

	// Return wParam of MSG.
	return((int)msg.wParam);
}


// Defining The Callback Function. 
LRESULT CALLBACK WndProc( HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	// Handelling The Window Callback Messages
	switch (iMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			break;
	}

	// Calling The OS Handling Function
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

