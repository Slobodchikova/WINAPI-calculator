#include <Windows.h>
#include <tchar.h>
#include <string>
#include <sstream>
#include <CommCtrl.h>
 
#pragma comment(lib,"ComCtl32.Lib")
#define IDB_Button1 1
//Сделать строку состояния через встроенную функцию
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

TCHAR WinName[] = _T("MainFrame");

int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
HINSTANCE Prev, 	// В современных системах всегда 0 
LPTSTR cmd, 		// Командная строка 
int mode) 		// Режим отображения окна
{ 
HWND hWnd;		// Дескриптор главного окна программы 
MSG msg; 		// Структура для хранения сообщения 
WNDCLASS wc; 	// Класс окна
HBRUSH br = CreateSolidBrush (RGB(153,204,255));
// Определение класса окна 
wc.hInstance = This; 
wc.lpszClassName = WinName; 				// Имя класса окна 
wc.lpfnWndProc = WndProc; 					// Функция окна 
wc.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
wc.lpszMenuName = NULL; 					// Нет меню 
wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
wc.hbrBackground = (HBRUSH) (br); 	// Заполнение окна белым цветом 


// Регистрация класса окна
if (!RegisterClass(&wc)) return 0; 	

// Создание окна 
hWnd = CreateWindow(WinName,			// Имя класса окна 
_T("Калькулятор"), 		// Заголовок окна 
WS_SYSMENU, 		// Стиль окна 
CW_USEDEFAULT,				// x 
CW_USEDEFAULT, 				// y	 Размеры окна 
500, 				// width 
600, 				// Height 
HWND_DESKTOP, 				// Дескриптор родительского окна 
NULL, 						// Нет меню 
This, 						// Дескриптор приложения 
NULL); 					// Дополнительной информации нет 

ShowWindow(hWnd, mode); 				// Показать окно

// Цикл обработки сообщений 
while(GetMessage(&msg, NULL, 0, 0)) 
{ 
TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
} 
return 0;
}
std::wstring df=L"\0";
std::wstring primer=L"\0";
std::wstringstream s;
double d, answer=0;
int flag= 0;
static HWND hStat, hSost; 
int method (int flag)
	{
		double d = _wtof(df.c_str());
		
		if (flag == 0) answer = d;
		if (flag == 1) answer = answer + d;
		if (flag == 2) answer = answer - d;
		if (flag == 3) answer = answer * d;
		if (flag == 4) answer = answer / d;
		df = L"\0";
		
		s=std::wstringstream(); // очищаем буфер
		s << answer;
		//SetWindowText(hStat, s.str().c_str());
		return 0;
	}

// Оконная функция вызывается операционной системой
// и получает сообщения из очереди для данного приложения

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{ 
	static HWND Bt1, Bt2, Bt3, Bt4, Bt5, Bt6, Bt7, Bt8, Bt9, Bt0; // дескриптор кнопкок
	static HWND BtPl, BtMin, BtMu, BtDi, BtBack, BtEc; // дескриптор кнопкок
	//поле вывода 
	/*LPCWSTR str= L"0";
	LPCWSTR ch;*/
	UINT wID;
	LPARAM hello = L'hello';


switch(message)		 // Обработчик сообщений
{ 
	
case WM_CREATE:
	
	Bt1= CreateWindow(TEXT("button"), TEXT("1"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  70, 200,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);

	Bt2= CreateWindow(TEXT("button"), TEXT("2"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  150, 200,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	 
	Bt3= CreateWindow(TEXT("button"), TEXT("3"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  230, 200,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);

	Bt4=  CreateWindow(TEXT("button"), TEXT("4"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  70, 280,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);

	  Bt5= CreateWindow(TEXT("button"), TEXT("5"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  150, 280,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	Bt6= CreateWindow(TEXT("button"), TEXT("6"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  230, 280,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	Bt7= CreateWindow(TEXT("button"), TEXT("7"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  70, 360,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	Bt8= CreateWindow(TEXT("button"), TEXT("8"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  150, 360,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
		
	  Bt9 =CreateWindow(TEXT("button"), TEXT("9"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  230, 360,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	 Bt0=  CreateWindow(TEXT("button"), TEXT("0"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  70, 440,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	 BtEc=  CreateWindow(TEXT("button"), TEXT("="),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  150, 440,
  150, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	BtPl = CreateWindow(TEXT("button"), TEXT("+"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  320, 200,
  70, 230,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	BtMin =  CreateWindow(TEXT("button"), TEXT("-"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  400, 200,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	BtMu =CreateWindow(TEXT("button"), TEXT("*"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  400, 280,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	BtDi =CreateWindow(TEXT("button"), TEXT("/"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  400, 360,
  70, 70,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	BtBack =CreateWindow(TEXT("button"), TEXT("<- Backspace"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  230, 140,
  240, 50,
  hWnd,
  (HMENU)IDB_Button1,
  NULL, NULL);
	 hStat = CreateWindow(TEXT("STATIC"),NULL,
    WS_VISIBLE | WS_CHILD | SS_CENTER | SS_CENTERIMAGE,
    70,20,
	400,70,hWnd,(HMENU)1,NULL,NULL);
    ShowWindow(hStat, SW_SHOWNORMAL);
	wID = 4000;
	hSost = CreateWindow(STATUSCLASSNAME, L"",
                                 WS_CHILD | WS_VISIBLE | WS_BORDER | SBARS_SIZEGRIP | CCS_BOTTOM,
                                 0, 0, 0, 0, hWnd, (HMENU)wID, NULL, NULL);
    SendMessage(hSost, SB_SIMPLE, 0, true ) ;

	break;
case WM_PAINT:
	/*hdc = GetDC(hWnd);
	Rectangle (hdc, 70 , 20, 470, 120);*/
		break;
case WM_COMMAND:  // сообщение о команде

	if (lParam == (LPARAM)BtEc)    // если нажали на кнопку
    {
		method (flag);
		
		SetWindowText(hStat, s.str().c_str());
		flag = 0;
		answer = 0;
		d = 0;
		primer = primer + L"=";
		primer = primer + s.str();
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str());
		Sleep(1000);
		primer = L"\0";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str());

		
	};
	if (lParam == (LPARAM)BtMin)    // если нажали на кнопку
    {
		method (flag);
		SetWindowText(hStat, s.str().c_str());
		flag = 2;
		primer = primer + L"-";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};
	if (lParam == (LPARAM)BtPl)    // если нажали на кнопку
    {
		method (flag);
		SetWindowText(hStat, s.str().c_str());
		flag = 1;
		primer = primer + L"+";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};
		if (lParam == (LPARAM)BtDi)    // если нажали на кнопку
    {
		method (flag);
		SetWindowText(hStat, s.str().c_str());
		flag = 4;
		primer = primer + L"/";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};
	if (lParam == (LPARAM)BtMu)    // если нажали на кнопку
    {
		method (flag);
		SetWindowText(hStat, s.str().c_str());
		flag = 3;
		primer = primer + L"*";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};

	if (lParam == (LPARAM)BtBack)    // если нажали на кнопку
    {
		df.pop_back();
		SetWindowText(hStat, df.c_str());
		primer.pop_back();
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};
    if (lParam == (LPARAM)Bt1)    // если нажали на кнопку
    {
		
		df = df + L"1";
		SetWindowText(hStat, df.c_str());
		primer = primer + L"1";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
		
	};
	 if (lParam == (LPARAM)Bt2)    // если нажали на кнопку
    {
		df = df + L"2";
		SetWindowText(hStat, df.c_str());
		primer = primer + L"2";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
		
	};
	 
    if (lParam == (LPARAM)Bt3)    // если нажали на кнопку
    {
		
		df = df + L"3";
		primer = primer + L"3";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
		SetWindowText(hStat, df.c_str());
		
	};
	 if (lParam == (LPARAM)Bt4)    // если нажали на кнопку
    {
		df = df + L"4";
		SetWindowText(hStat, df.c_str());
		primer = primer + L"4";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};
	     if (lParam == (LPARAM)Bt5)    // если нажали на кнопку
    {
		
		df = df + L"5";
		SetWindowText(hStat, df.c_str());
		primer = primer + L"5";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};
	 if (lParam == (LPARAM)Bt6)    // если нажали на кнопку
    {
		df = df + L"6";
		SetWindowText(hStat, df.c_str());
		primer = primer + L"6";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};
	 
    if (lParam == (LPARAM)Bt7)    // если нажали на кнопку
    {
		
		df = df + L"7";
		SetWindowText(hStat, df.c_str());
		primer = primer + L"7";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};
	 if (lParam == (LPARAM)Bt8)    // если нажали на кнопку
    {
		df = df + L"8";
		SetWindowText(hStat, df.c_str());
		primer = primer + L"8";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};
	    if (lParam == (LPARAM)Bt0)    // если нажали на кнопку
    {
		
		df = df + L"0";
		SetWindowText(hStat, df.c_str());
		primer = primer + L"0";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};
	 if (lParam == (LPARAM)Bt9)    // если нажали на кнопку
    {
		df = df + L"9";
		SetWindowText(hStat, df.c_str());
		primer = primer + L"9";
		SendMessage(hSost,SB_SETTEXT,0, (LPARAM)primer.c_str() );
	};
    break;
	 case WM_SIZE:
        SendMessage(hSost, WM_SIZE, 0, 0);
        break;
case WM_DESTROY : 
PostQuitMessage(0); 
break; 			// Завершение программы 
default : 			// Обработка сообщения по умолчанию 
return DefWindowProc(hWnd, message, wParam, lParam); 
} 
return 0;
}
