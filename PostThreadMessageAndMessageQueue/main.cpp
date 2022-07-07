#include <Windows.h>

HINSTANCE__* g_pInstance = nullptr;

long long __stdcall WndProc(HWND__* const _pWindow, const unsigned int _unMessage, const unsigned long long _ullWParam, const long long _llLParam)
{
	return DefWindowProcW(_pWindow, _unMessage, _ullWParam, _llLParam);
}

unsigned long __stdcall Thread(void* const _pParameter)
{
	Sleep(2000ul);
	
	//DWORD dwThreadID = GetCurrentThreadId();
	//BOOL bResult = PostThreadMessageW(dwThreadID, WM_QUIT, 123, 456);

	//tagMSG stMSG{};
	//if (PeekMessageW(&stMSG, nullptr, 0, 0, static_cast<unsigned int>(PM_REMOVE)) == 0)
	//{
	//	int bb = 10;
	//	Sleep(2000ul);
	//}

	tagWNDCLASSEXW stWNDCLASSEXW
	{
		sizeof(tagWNDCLASSEXW),
		static_cast<unsigned int>(CS_VREDRAW | CS_HREDRAW),
		&WndProc,
		0,
		0,
		g_pInstance,
		nullptr,
		static_cast<HICON__*>(LoadImageW(nullptr, static_cast<const wchar_t*>(IDC_ARROW), static_cast<unsigned int>(IMAGE_CURSOR), 0, 0, static_cast<unsigned int>(LR_SHARED))),
		static_cast<HBRUSH__*>(GetStockObject(WHITE_BRUSH)),
		L"MenuName",
		L"ClassName",
		nullptr
	};

	//Sleep(5000ul);

	unsigned short usWindowClass = RegisterClassExW(&stWNDCLASSEXW);

	Sleep(5000ul);

	tagMSG stMSG{};
	if (PeekMessageW(&stMSG, nullptr, 0, 0, static_cast<unsigned int>(PM_REMOVE)) == 0)
	{
		int bb = 10;
		Sleep(2000ul);
	}

	HWND__* const pWindow = CreateWindowExW(0ul,
											reinterpret_cast<const wchar_t*>(usWindowClass),
											L"WindowName",
											static_cast<unsigned long>(WS_OVERLAPPEDWINDOW),
											0,
											0,
											1200,
											800,
											nullptr,
											nullptr,
											g_pInstance,
											nullptr);

	Sleep(5000ul);

	if (PeekMessageW(&stMSG, nullptr, 0, 0, static_cast<unsigned int>(PM_REMOVE)) == 0)
	{
		int bb = 10;
	}

	return 0ul;
}

int __stdcall wWinMain(HINSTANCE__* const _pInstance,
					   HINSTANCE__* const _pPrevInstance,
					   wchar_t* const _pCmdLine,
					   const int _nCmdShow)
{
	g_pInstance = _pInstance;
	
	unsigned long ulThreadID = 0ul;
	void* pThread = CreateThread(nullptr, 0ull, &Thread, nullptr, 0ul, &ulThreadID);

	Sleep(1000ul);

	BOOL bResult = PostThreadMessageW(ulThreadID, WM_QUIT, 123, 456);

	Sleep(2000ul);

	bResult = PostThreadMessageW(ulThreadID, WM_QUIT, 123, 456);

	Sleep(30000ul);

	return 0;
}