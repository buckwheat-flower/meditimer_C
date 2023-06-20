#include "Standard_FX.h"
#include "alarm1.h"
#include "pill.h"

void consolesize()
{
	system("mode con cols=70 lines=25 | title �˾� �˸���");
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


char* digits[10][5][4] =//0~9���� ����� ����
{
   {
	  { "��","��","��","��" },
	  { "��","  ","  ","��" },
	  { "��","  ","  ","��" },
	  { "��","  ","  ","��" },
	  { "��","��","��","��" }
   },
   {
	  { "  ","  ","  ","��" },
	  { "  ","  ","  ","��" },
	  { "  ","  ","  ","��" },
	  { "  ","  ","  ","��" },
	  { "  ","  ","  ","��" }
   },
   {
	  { "��","��","��","��" },
	  { "  ","  ","  ","��" },
	  { "��","��","��","��" },
	  { "��","  ","  ","  " },
	  { "��","��","��","��" }
   },
   {
	  { "��","��","��","��" },
	  { "  ","  ","  ","��" },
	  { "��","��","��","��" },
	  { "  ","  ","  ","��" },
	  { "��","��","��","��" }
   },
   {
	  { "��","  ","��","  " },
	  { "��","  ","��","  " },
	  { "��","��","��","��" },
	  { "  ","  ","��","  " },
	  { "  ","  ","��","  " }
   },
   {
	  { "��","��","��","��" },
	  { "��","  ","  ","  " },
	  { "��","��","��","��" },
	  { "  ","  ","  ","��" },
	  { "��","��","��","��" },
   },
   {
	  { "��","  ","  ","  " },
	  { "��","  ","  ","  " },
	  { "��","��","��","��" },
	  { "��","  ","  ","��" },
	  { "��","��","��","��" }
   },
   {
	  { "��","��","��","��" },
	  { "��","  ","  ","��" },
	  { "��","  ","  ","��" },
	  { "  ","  ","  ","��" },
	  { "  ","  ","  ","��" }
   },
   {
	  { "��","��","��","��" },
	  { "��","  ","  ","��" },
	  { "��","��","��","��" },
	  { "��","  ","  ","��" },
	  { "��","��","��","��" }
   },
   {
	  { "��","��","��","��" },
	  { "��","  ","  ","��" },
	  { "��","��","��","��" },
	  { "  ","  ","  ","��" },
	  { "  ","  ","  ","��" }
   }
};

int sx[6] = { 2,12,26,36,50,60 };//�ú��ʸ� ����� x��ǥ 

char* colons[5] = { " ","��","  ","��","  " };
int sx2[6] = { 22,46 };//�ݷ��� ����� ��ǥ


//dn�ڸ��� ���� n�� ����ϴ� �Լ�
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

//�ݷ��� ����ϴ��Լ� n�� 0�̸� �ÿ� �л���, 1�̸� �а� �ʻ���
void DrawColon(int n)
{
	int y = 0;


	for (y = 0; y < 5; y++)
	{
		gotoxy(sx2[n], y + 4);
		printf("%s\n", colons[y]);
	}

}

//�ð��� ����ϴ��Լ�
void DrawTime(int h, int m, int s)
{
	DrawNum(0, h / 10);//���� ���ڸ�
	DrawNum(1, h % 10);//���� ���ڸ�
	DrawColon(0);//�ݷ�
	DrawNum(2, m / 10);//���� ���ڸ�
	DrawNum(3, m % 10);//���� ���ڸ�
	DrawColon(1);//�ݷ�
	DrawNum(4, s / 10);//���� ���ڸ�
	DrawNum(5, s % 10);//���� ���ڸ�
}

void Control_Menu(int* k) // �޴� ����
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


extern int olds = 0; // �˶��ߺ� �︲�� �������� �д����� üũ�ϴ� ����

void MainUI() // ùȭ�� �������̽�
{
	int pill_Num = 0; // �˾� ��ȣ
	int alarm_Chk = 0; // �˶� �ߺ��︲�� ���� ����

	system("cls");

	while (_kbhit() == 0)  // Ű�� ������ ������ ���� => Ű�� ������ ����!
	{
		int Mkey = NULL; // Ű �� �ʱ�ȭ

		system("color F1");

		time_t now, before;
		struct tm nt;

		now = before = time(0); //�� ���� �ð��� ����
		localtime_s(&nt, &now); //���� �ð��� ����
		int year = nt.tm_year + 1900;    //�������� 1900 ������
		int month = nt.tm_mon + 1;    // ������ 1 ������
		int day = nt.tm_mday;
		int hour = nt.tm_hour;
		int min = nt.tm_min;
		int sec = nt.tm_sec;

		
		if (olds != min)  // 1�и��� üũ�Ͽ� �˶� �ߺ��︲�� ����
		{
			olds = min; 
			alarm_Chk = 1; 
		}
		else 
			alarm_Chk = 0;

		if (Check_alarm(year, month, day, hour, min))//�˶�üũ �Լ��� ȣ���ؼ� �˶��ð��� ��ġ�ϸ�
		{
			Active_alarm(&alarm_Chk);   //�˶��� �����
		}

		DrawTime(hour, min, sec);//���� �ð��� ���

		gotoxy(14, 11); printf(" ����������������������������������MENU��������������������������������");
		gotoxy(14, 12); printf(" ��                                   �� ");
		gotoxy(14, 13); printf(" ��          1 : �˾� ���            ��");
		gotoxy(14, 14); printf(" ��          2 : �˶� ���            ��");
		gotoxy(14, 15); printf(" ��        ESC : ���α׷� ����        ��");
		gotoxy(14, 16); printf(" ��                                   ��");
		gotoxy(14, 17); printf(" ��������������������������������������������������������������������������");
		gotoxy(19, 19); printf(" ���Ͻô� ��ư�� Ŭ�����ּ���. ");


		now = time(0);//�ʴ��� �ð��� ����

		if (now != before)//�ٸ���
		{

			before = now;//���� �ʴ��� �ð��� ���
			localtime_s(&nt, &now);//���� �ð��� ����
			DrawTime(hour, min, sec);//���� �ð��� ���
			year = nt.tm_year + 1900;    //�������� 1900 ������
			month = nt.tm_mon + 1;    // ������ 1 ������
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
