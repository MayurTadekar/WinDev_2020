
// Header
#include <windows.h>

// Callback Function Declaration
//__int64 __stdcall WndProc( unsigned int, unsigned int, unsigned __int64,  __int64 )
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
	wndcls.hbrBackground = (HBRUSH) GetStockObject( BLACK_BRUSH );	// BLACK_BRUSH 	->  #define  BLACK_BRUSH 	0	// HGDIOBJ WINAPI GetStockObject(int);
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// HICON WINAPI LoadIcon(HINSTANCE, LPCWSTR);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);	// HCURSOR WINAPI LoadCursor(HINSTANCE, LPCWSTR);
	wndcls.hInstance = hInstance;
	wndcls.hIconSm = LoadIcon(NULL, IDI_APPLICATION);	// HICON WINAPI LoadIcon(HINSTANCE, LPCWSTR);

	// Register WNDCLASS
	RegisterClassEx( &wndcls );		// ATOM WINAPI RegisterClassEx(CONST WNDCLASSEX *);

	// Creating the window on RAM
	hwnd = CreateWindow( szAppName,	// HWND WINAPI CreateWindows(LPCTSTR, LPCTSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID);  
		TEXT("Mayur's Window"),		
		WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_THICKFRAME | WS_OVERLAPPED,		
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	// Show The Window on Display
	ShowWindow(hwnd, SW_NORMAL);	// BOOL WINAPI ShowWindow(HWND, int); 

	// Set The Background Of The Window
	UpdateWindow(hwnd);			// BOOL WINAPI UpdateWindow(HWND);

	// Message Loop
	while( GetMessage(&msg, NULL, 0, 0) )		// BOOL WINAPI GetMessage( LPMSG, HWND, UINT wMsgFilterMin, UINT wMsgFilterMax );
	{
		TranslateMessage(&msg);					// BOOL WINAPI TranslateMessage(LPMSG);
		DispatchMessage(&msg);					// BOOL WINAPI TranslateMessage(LPMSG);
	}

	// Return wParam of MSG.
	return((int)msg.wParam);
}


// Defining The Callback Function. 
//__int64 __stdcall WndProc( unsigned __int64, unsigned __int64, unsigned __int64, __int64);
LRESULT CALLBACK WndProc( HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	// Handelling The Window Callback Messages
	switch (iMsg)
	{
		case WM_DESTROY:
			MessageBox(hwnd, TEXT("WM_DESTROY received"), TEXT("Message"), MB_OK);	// int WINAPI MessgeBox( unsigned __int64, LPCWSTR, LPCWSTR, int );
			PostQuitMessage(0);		// VOID WINAPI PostQuitMessage(int);
			break;

		case WM_CREATE:
			MessageBox(hwnd, TEXT("WM_CREATE received"), TEXT("Message"), MB_OK);	// int WINAPI MessageBox( unsinged __int64, LPCWSTR, LPCWSTR, int);
			break;
		
		case WM_LBUTTONDOWN:
			MessageBox(hwnd, TEXT("WM_LBUTTONDOWN received"), TEXT("Message"), MB_OK);	// int WINAPI MessageBox(unsigned __int64, LPCWSTR, LPCWSTR, int);
			break;

		case WM_RBUTTONDOWN:
			MessageBox(hwnd, TEXT("WM_RBUTTONDOWN received"), TEXT("Message"), MB_OK);	// int WINAPI MessageBox(unsigned __int64, LPCWSTR, LPCWSTR, int);
			break;
			
		case WM_KEYDOWN:
			MessageBox(hwnd, TEXT("WM_KEYDOWN received"), TEXT("Message"), MB_OK);	// int MessageBox(unsigned __int64, LPCWSTR, LPCWSTR, int);
			break;
					
		default:
			break;
	}

	// Calling The OS Handling Function
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));		// __int64 __stdcall DefWindowProc( unsigned __int64, unsigned __int64, unsigned __int64, __int64);
}

