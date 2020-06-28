
// Header
#include <windows.h>

// Callback Function Declaration
LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM);

// Windows GUI Main
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{

	MSG msg;
	HWND hwnd;
	TCHAR szAppName[] = TEXT("MyWindow");
	WNDCLASSEX wndcls;

	wndcls.cbSize = sizeof(WNDCLASSEX);
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.lpfnWndProc = WndProc;
	wndcls.lpszClassName = szAppName;
	wndcls.lpszMenuName = NULL;
	wndcls.hbrBackground = (HBRUSH) GetStockObject( BLACK_BRUSH );
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls.hInstance = hInstance;
	wndcls.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx( &wndcls );

	hwnd = CreateWindow( szAppName,
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

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while( GetMessage(&msg, NULL, 0, 0) )
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	switch (iMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			break;
	}

	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

