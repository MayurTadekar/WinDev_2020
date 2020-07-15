
// Header
#include <windows.h>

// Callback Function Declaration
LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM);

// Windows GUI Main
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
	wndcls.hbrBackground = (HBRUSH) GetStockObject( BLACK_BRUSH );	// BLACK_BRUSH 	->  #define  BLACK_BRUSH 	0
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls.hInstance = hInstance;
	wndcls.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// Register WNDCLASS
	RegisterClassEx( &wndcls );

	// Creating the window on RAM
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

	// Show The Window on Display
	ShowWindow(hwnd, iCmdShow);

	// Set The Background Of The Window
	UpdateWindow(hwnd);

	// Message Loop
	while( GetMessage(&msg, NULL, 0, 0) )
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// Return wParam of MSG.
	return((int)msg.wParam);
}


// Defining The Callback Function. 
LRESULT CALLBACK WndProc( HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	TCHAR str[256];
	LPCREATESTRUCT lpcreate;

	// Handelling The Window Callback Messages
	switch (iMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_CREATE:
			lpcreate = (LPCREATESTRUCT)lParam;
			wsprintf(str, TEXT("%s window is created."), lpcreate->lpszName);
			MessageBox(hwnd, str, TEXT("Window Created"), MB_OK);
			break;

		case WM_KEYDOWN:
			switch(LOWORD(wParam))
			{
				case 0x1B:
					DestroyWindow(hwnd);
					break;
			}
			break;

		default:
			break;
	}

	// Calling The OS Handling Function
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

