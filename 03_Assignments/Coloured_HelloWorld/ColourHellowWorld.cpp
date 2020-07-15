
// Header
#include <windows.h>

// Callback Function Declaration
LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM);

// ENUM
enum 
{
	RED = 1,
	GREEN,
	BLUE,
	CYAN,
	MAGENTA,
	YELLOW
};

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
		TEXT("Hello World Window"),
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

	// Variable Declaration
	static HDC hdc;
	static RECT rc;
	static PAINTSTRUCT ps;
	static TCHAR str[] = TEXT("Hello World!!!");
	static	int iPaintFlag = RED;

	// Handelling The Window Callback Messages
	switch (iMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_PAINT:
		
			hdc = BeginPaint(hwnd, &ps);

			GetClientRect(hwnd, &rc);

			SetBkColor(hdc, RGB(0, 0, 0));

			switch(iPaintFlag)
			{
				case RED:
					SetTextColor(hdc, RGB(255, 0, 0));
					break;

				case GREEN:
					SetTextColor(hdc, RGB(0, 255, 0));
					break;

				case BLUE:
					SetTextColor(hdc, RGB(0, 0, 255));
					break;

				case CYAN:
					SetTextColor(hdc, RGB(0, 255, 255));
					break;

				case MAGENTA:
					SetTextColor(hdc, RGB(255, 0, 255));
					break;

				case YELLOW:
					SetTextColor(hdc, RGB(255, 255, 0));
					break;
			}
			DrawText(hdc, str, -1, &rc, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

			ReleaseDC(hwnd, hdc);
			hdc = NULL;

			EndPaint(hwnd, &ps);
			break;

		case WM_CHAR :

			switch( wParam )
			{
				case 'r':
				case 'R':
					iPaintFlag = RED;
					InvalidateRect(hwnd, NULL, TRUE);
					break;
					
				case 'g':
				case 'G':
					iPaintFlag = GREEN;
					InvalidateRect(hwnd, NULL, TRUE);
					break;

				case 'b':
				case 'B':
					iPaintFlag = BLUE;
					InvalidateRect(hwnd, NULL, TRUE);
					break;

				case 'c':
				case 'C':
					iPaintFlag = CYAN;
					InvalidateRect(hwnd, NULL, TRUE);
					break;

				case 'y':
				case 'Y':
					iPaintFlag = YELLOW;
					InvalidateRect(hwnd, NULL, TRUE);
					break;

				case 'm':
				case 'M':
					iPaintFlag = MAGENTA;
					InvalidateRect(hwnd, NULL, TRUE);
					break;
			}

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

