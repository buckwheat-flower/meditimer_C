#include "Standard_FX.h"
#include "alarm1.h"
#include "pill.h"

void consolesize()
{
	system("mode con cols=70 lines=25 | title 알약 알리미");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


char* digits[10][5][4] =//0~9까지 출력할 정보
{
   {
	  { "■","■","■","■" },
	  { "■","  ","  ","■" },
	  { "■","  ","  ","■" },
	  { "■","  ","  ","■" },
	  { "■","■","■","■" }
   },
   {
	  { "  ","  ","  ","■" },
	  { "  ","  ","  ","■" },
	  { "  ","  ","  ","■" },
	  { "  ","  ","  ","■" },
	  { "  ","  ","  ","■" }
   },
   {
	  { "■","■","■","■" },
	  { "  ","  ","  ","■" },
	  { "■","■","■","■" },
	  { "■","  ","  ","  " },
	  { "■","■","■","■" }
   },
   {
	  { "■","■","■","■" },
	  { "  ","  ","  ","■" },
	  { "■","■","■","■" },
	  { "  ","  ","  ","■" },
	  { "■","■","■","■" }
   },
   {
	  { "■","  ","■","  " },
	  { "■","  ","■","  " },
	  { "■","■","■","■" },
	  { "  ","  ","■","  " },
	  { "  ","  ","■","  " }
   },
   {
	  { "■","■","■","■" },
	  { "■","  ","  ","  " },
	  { "■","■","■","■" },
	  { "  ","  ","  ","■" },
	  { "■","■","■","■" },
   },
   {
	  { "■","  ","  ","  " },
	  { "■","  ","  ","  " },
	  { "■","■","■","■" },
	  { "■","  ","  ","■" },
	  { "■","■","■","■" }
   },
   {
	  { "■","■","■","■" },
	  { "■","  ","  ","■" },
	  { "■","  ","  ","■" },
	  { "  ","  ","  ","■" },
	  { "  ","  ","  ","■" }
   },
   {
	  { "■","■","■","■" },
	  { "■","  ","  ","■" },
	  { "■","■","■","■" },
	  { "■","  ","  ","■" },
	  { "■","■","■","■" }
   },
   {
	  { "■","■","■","■" },
	  { "■","  ","  ","■" },
	  { "■","■","■","■" },
	  { "  ","  ","  ","■" },
	  { "  ","  ","  ","■" }
   }
};

int sx[6] = { 2,12,26,36,50,60 };//시분초를 출력할 x좌표 

char* colons[5] = { " ","■","  ","■","  " };
int sx2[6] = { 22,46 };//콜론을 출력할 좌표


//dn자리에 정수 n을 출력하는 함수
void DrawNum(int dn, int n)
{
	int y, x;

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 4; x++)
		{
			gotoxy(sx[dn] + x * 2, y + 4);
			printf("%s", digits[n][y][x]);
		}
		printf("\n");
	}
}

//콜론을 출력하는함수 n이 0이면 시와 분사이, 1이면 분과 초사이
void DrawColon(int n)
{
	int y = 0;


	for (y = 0; y < 5; y++)
	{
		gotoxy(sx2[n], y + 4);
		printf("%s\n", colons[y]);
	}

}

//시간을 출력하는함수
void DrawTime(int h, int m, int s)
{
	DrawNum(0, h / 10);//시의 앞자리
	DrawNum(1, h % 10);//시의 뒷자리
	DrawColon(0);//콜론
	DrawNum(2, m / 10);//분의 앞자리
	DrawNum(3, m % 10);//분의 뒷자리
	DrawColon(1);//콜론
	DrawNum(4, s / 10);//초의 앞자리
	DrawNum(5, s % 10);//초의 뒷자리
}

void Control_Menu(int* k) // 메뉴 선택
{
	char Ckey = *k;

	switch (Ckey)
	{
	case '1':
		List_pill();
	case '2':
		List_alarm();
	case 27:
		exit(0);
	default: break;
	}
}


extern int olds = 0; // 알람중복 울림을 막기위해 분단위로 체크하는 변수

void MainUI() // 첫화면 인터페이스
{
	int pill_Num = 0; // 알약 번호
	int alarm_Chk = 0; // 알람 중복울림을 막는 변수

	system("cls");

	while (_kbhit() == 0)  // 키가 눌리지 않으면 진행 => 키가 눌리면 종료!
	{
		int Mkey = NULL; // 키 값 초기화

		system("color F1");

		time_t now, before;
		struct tm nt;

		now = before = time(0); //초 단위 시간을 구함
		localtime_s(&nt, &now); //지역 시각을 구함
		int year = nt.tm_year + 1900;    //연도에는 1900 더해줌
		int month = nt.tm_mon + 1;    // 월에는 1 더해줌
		int day = nt.tm_mday;
		int hour = nt.tm_hour;
		int min = nt.tm_min;
		int sec = nt.tm_sec;

		
		if (olds != min)  // 1분마다 체크하여 알람 중복울림을 막음
		{
			olds = min; 
			alarm_Chk = 1; 
		}
		else 
			alarm_Chk = 0;

		if (Check_alarm(year, month, day, hour, min))//알람체크 함수를 호출해서 알람시각이 일치하면
		{
			Active_alarm(&alarm_Chk);   //알람을 출력함
		}

		DrawTime(hour, min, sec);//현재 시각을 출력

		gotoxy(14, 11); printf(" ┌────────────────MENU───────────────┐");
		gotoxy(14, 12); printf(" │                                   │ ");
		gotoxy(14, 13); printf(" │          1 : 알약 목록            │");
		gotoxy(14, 14); printf(" │          2 : 알람 목록            │");
		gotoxy(14, 15); printf(" │        ESC : 프로그램 종료        │");
		gotoxy(14, 16); printf(" │                                   │");
		gotoxy(14, 17); printf(" └───────────────────────────────────┘");
		gotoxy(19, 19); printf(" 원하시는 버튼을 클릭해주세요. ");


		now = time(0);//초단위 시간을 구함

		if (now != before)//다르면
		{

			before = now;//현재 초단위 시간을 기억
			localtime_s(&nt, &now);//지역 시각을 구함
			DrawTime(hour, min, sec);//현재 시각을 출력
			year = nt.tm_year + 1900;    //연도에는 1900 더해줌
			month = nt.tm_mon + 1;    // 월에는 1 더해줌
			day = nt.tm_mday;
			hour = nt.tm_hour;
			min = nt.tm_min;
			sec = nt.tm_sec;
		}

		if (_kbhit() != NULL)
		{
			Mkey = _getch();
			system("cls");
			Control_Menu(&Mkey);
			Mkey = NULL;
		}

	}

}




int main()
{
	consolesize();
	MainUI();
}
