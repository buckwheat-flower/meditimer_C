#include "Standard_FX.h"
#include "alarm1.h"
#include "pill.h"


//�˶��� ���������� ����Ҷ� ����ϴ� ����
#define DO    523
#define RE    587
#define MI    659
#define PA    698    
#define SOL   784
#define RA    880
#define SI    988
#define _DO   1046

extern int total_alarm = 0; // �˶� ����
int total_pills;


void List_alarm()
{
	int i, alarm_key;
	buble_alarm();

	system("cls");

	gotoxy(29, 1); printf("<�˶� ���>");
	gotoxy(2, 16); printf("����������������������������������������������������������������������������������������������������������������������������������");
	gotoxy(2, 17); printf("��");                                    gotoxy(66, 17); printf("��");
	gotoxy(2, 18); printf("��");                                    gotoxy(66, 18); printf("��");
	gotoxy(2, 19); printf("��");                                    gotoxy(66, 19); printf("��");
	gotoxy(2, 20); printf("��");                                    gotoxy(66, 20); printf("��");
	gotoxy(2, 21); printf("��");                                    gotoxy(66, 21); printf("��");
	gotoxy(2, 22); printf("����������������������������������������������������������������������������������������������������������������������������������");


	gotoxy(20, 18); printf("[ ���Ͻô� ��ư�� �����ּ���.]");
	gotoxy(13, 20); printf("1 : �˶� ���  2 : �˶� ����  3 : ���� �޴�");


	if (total_alarm == 0)
	{
		gotoxy(22, 5); printf("[ ��ϵ� �˶��� �����ϴ�.]");
		gotoxy(22, 7); printf(" >> �˶��� ������ּ���.<<");
	}

	else
	{
		gotoxy(3, 3);  printf("��ȣ");
		gotoxy(9, 3);  printf("�˾� �̸�");
		gotoxy(28, 3); printf("��");
		gotoxy(40, 3); printf("��");
		gotoxy(47, 3); printf("��");
		gotoxy(54, 3); printf("��");
		gotoxy(61, 3); printf("��");

		gotoxy(7, 3);  printf("��");
		gotoxy(26, 3); printf("��");
		gotoxy(38, 3); printf("��");
		gotoxy(45, 3); printf("��");
		gotoxy(52, 3); printf("��");
		gotoxy(59, 3); printf("��");

		gotoxy(3, 4); printf("��������������������������������������������������������������������������������������������������������������������������\n");

		for (i = 0; i < total_alarm; i++)
		{
			gotoxy(7, 5 + i);  printf("��");
			gotoxy(26, 5 + i); printf("��");
			gotoxy(38, 5 + i); printf("��");
			gotoxy(45, 5 + i); printf("��");
			gotoxy(52, 5 + i); printf("��");
			gotoxy(59, 5 + i); printf("��");
			gotoxy(3, 5 + i); printf("[%d]", i + 1);
			gotoxy(9, 5 + i); printf("%s", pill[i].pill_name);
			gotoxy(28, 5 + i); printf("%d", arm[i].A_year);
			gotoxy(40, 5 + i); printf("%d", arm[i].A_month);
			gotoxy(47, 5 + i); printf("%d", arm[i].A_day);
			gotoxy(54, 5 + i); printf("%d", arm[i].A_hour);
			gotoxy(61, 5 + i); printf("%d", arm[i].A_min);
		}
	}

	while (_kbhit() == 0)
	{
		alarm_key = _getch();
		switch (alarm_key)
		{
		case '1':
			Make_alarm();
			MainUI();
		case '2':
			Remove_alarm();
			MainUI();
		case '3':
			MainUI();

		default:
			Sleep(1000);
			system("cls");
			printf("��ư�� �ٽ� �����ּ���");
		}
		alarm_key = NULL;
	}
}


void Make_alarm() // �� �˶� �����
{

	int i;
	int Makealarm;
	system("cls");

	if (total_pills == 0)
	{
		gotoxy(20, 6);   printf("������������������������  �˸� ����������������������");
		gotoxy(20, 11);  printf("������������������������������������������������������������");
		gotoxy(20, 7);  printf("��");
		gotoxy(20, 8);  printf("��");
		gotoxy(20, 9);  printf("��");
		gotoxy(20, 10); printf("��");
		gotoxy(49, 7);  printf("��");
		gotoxy(49, 8);  printf("��");
		gotoxy(49, 9);  printf("��");
		gotoxy(49, 10); printf("��");


		gotoxy(25, 8); printf("��ϵ� �˾��� �����ϴ�. ");
		gotoxy(24, 9); printf("  �˾��� ������ּ���. ");

		Sleep(2500);
		system("cls");
	}

	else
	{
		total_alarm++;

		gotoxy(5, 5); printf("��ȣ ��");
		gotoxy(13, 5); printf("�˾� �̸�\t\t   ȿ��               ��ȸ ���뷮");
		gotoxy(32, 5); printf("��");
		gotoxy(51, 5); printf("��");
		gotoxy(5, 6); printf("������");
		gotoxy(8, 6); printf("����������������������������������������������������������������������������������������������������������������");

		for (i = 0; i < total_pills; i++)
		{

			gotoxy(32, 7 + i); printf("��");
			gotoxy(51, 7 + i); printf("��");
			gotoxy(10, 7 + i); printf("��");
			gotoxy(5, 7 + i); printf("[%d]", i + 1);
			gotoxy(13, 7 + i); printf("%s", pill[i].pill_name);
			gotoxy(35, 7 + i); printf("%s", pill[i].pill_efficacy);
			gotoxy(54, 7 + i); printf("%d", pill[i].pill_quantity);

		}
		gotoxy(8, 3); printf("[ �˶��� ����ϱ� ���ϴ� �˾��� ��ȣ�� �����ּ���. ]");

		while (1)
		{
			if (_kbhit())
			{
				Makealarm = _getch();
				Makealarm = Makealarm - 49;
				if (Makealarm < total_pills && Makealarm >= 0)
				{
					break;
				}
			}

		}
		system("cls");

		gotoxy(15, 3); printf("[ �˶��� ����� �ð��� �Է����ּ���.]");
		gotoxy(14, 5); printf("�˾� �̸�: %s, ȿ�� : %s, ��ȸ ���뷮 : %d", pill[Makealarm].pill_name, pill[Makealarm].pill_efficacy, pill[Makealarm].pill_quantity);

		gotoxy(12, 7); printf("������������������������������������������������������������������������������������������");
		gotoxy(12, 17); printf("������������������������������������������������������������������������������������������");
		
		strcpy_s(arm[total_alarm - 1].A_name, 20, pill[Makealarm].pill_name);
		arm[total_alarm - 1].A_quantity = pill[Makealarm].pill_quantity;
		
		gotoxy(24, 8);  printf("�˶� �⵵ : ");
		scanf_s("%d", &arm[total_alarm - 1].A_year);

		gotoxy(24, 10); printf("�˶� ��   : ");
		scanf_s("%d", &arm[total_alarm - 1].A_month);

		gotoxy(24, 12); printf("�˶� ��   : ");
		scanf_s("%d", &arm[total_alarm - 1].A_day);

		gotoxy(24, 14); printf("�˶� �ð� : ");
		scanf_s("%d", &arm[total_alarm - 1].A_hour);

		gotoxy(24, 16); printf("�˶� ��   : ");
		scanf_s("%d", &arm[total_alarm - 1].A_min);

		Sleep(1500);
		system("cls");
		gotoxy(17, 8);   printf("����������������������������  �˸� ������������������������������");
		gotoxy(16, 9);  printf(" ��                                  �� ");
		gotoxy(17, 10);  printf("��    �˶� ����� �Ϸ�Ǿ����ϴ�.   ��");
		gotoxy(16, 11); printf(" ��                                  �� ");
		gotoxy(16, 12); printf(" ������������������������������������������������������������������������");
		Sleep(1500);
		system("cls");
	}
}


void Remove_alarm() // ���ϴ� �˶� ����
{
	system("cls");

	printf("<�˶� ����>\n");

	if (total_alarm <= 0)
	{
		gotoxy(17, 8);  printf(" ���������������������������� �˸� ������������������������������");
		gotoxy(17, 9);  printf(" ��                                 ��");
		gotoxy(17, 10); printf(" ��      ������ �˶��� �����ϴ�.    ��");
		gotoxy(17, 11); printf(" ��                                 ��");
		gotoxy(17, 12); printf(" ����������������������������������������������������������������������");


		Sleep(1700);
		system("cls");
	}

	else {

		int Removealarm = NULL;
		int i = 0;

		gotoxy(12, 3); printf("[ ������ ���Ͻô� �˶��� ��ȣ�� �����ּ���. ]");

		gotoxy(3, 5);  printf("��ȣ");
		gotoxy(9, 5);  printf("�˾� �̸�");
		gotoxy(28, 5); printf("��");
		gotoxy(40, 5); printf("��");
		gotoxy(47, 5); printf("��");
		gotoxy(54, 5); printf("��");
		gotoxy(61, 5); printf("��");

		gotoxy(7, 5);  printf("��");
		gotoxy(26, 5); printf("��");
		gotoxy(38, 5); printf("��");
		gotoxy(45, 5); printf("��");
		gotoxy(52, 5); printf("��");
		gotoxy(59, 5); printf("��");

		gotoxy(3, 6); printf("��������������������������������������������������������������������������������������������������������������������������\n");

		for (i = 0; i < total_alarm; i++)
		{
			gotoxy(7, 7 + i);  printf("��");
			gotoxy(26, 7 + i); printf("��");
			gotoxy(38, 7 + i); printf("��");
			gotoxy(45, 7 + i); printf("��");
			gotoxy(52, 7 + i); printf("��");
			gotoxy(59, 7 + i); printf("��");
			gotoxy(3, 7 + i); printf("[%d]", i + 1);
			gotoxy(9, 7 + i); printf("%s", arm[i].A_name);
			gotoxy(28, 7 + i); printf("%d", arm[i].A_year);
			gotoxy(40, 7 + i); printf("%d", arm[i].A_month);
			gotoxy(47, 7 + i); printf("%d", arm[i].A_day);
			gotoxy(54, 7 + i); printf("%d", arm[i].A_hour);
			gotoxy(61, 7 + i); printf("%d", arm[i].A_min);
		}

		while (1)
		{
			if (_kbhit())
			{
				Removealarm = _getch();
				Removealarm = Removealarm - 49;
				if (Removealarm < total_alarm && Removealarm >= 0)
				{
					for (int i = 0; i < total_alarm; i++)
					{
						if (Removealarm == i)
						{
							for (int j = Removealarm; j < total_alarm; j++)
							{
								arm[j] = arm[j + 1];
							}
						}
					}
					break;
				}

			}
		}
		total_alarm--;

		system("cls");
		gotoxy(17, 8);   printf("�������������������������� �˸� ����������������������������");
		gotoxy(16, 9);  printf(" ��                               �� ");
		gotoxy(17, 10);  printf("��   %d�� �˶��� �����Ǿ����ϴ�.  ��", Removealarm + 1);
		gotoxy(16, 11); printf(" ��                               �� ");
		gotoxy(16, 12); printf(" ������������������������������������������������������������������");

		Sleep(1700);
		system("cls");
	}

}


void buble_alarm()
{
	int i, j;
	for (i = 0; i < total_alarm; i++)
	{
		for (j = 0; j < total_alarm - 1; j++)
		{
			if (arm[j].A_year > arm[j + 1].A_year)
			{
				temp = arm[j];
				arm[j] = arm[j + 1];
				arm[j + 1] = temp;
			}
			else if (arm[j].A_month > arm[j + 1].A_month)
			{
				temp = arm[j];
				arm[j] = arm[j + 1];
				arm[j + 1] = temp;
			}
			else if (arm[j].A_day > arm[j + 1].A_day)
			{
				temp = arm[j];
				arm[j] = arm[j + 1];
				arm[j + 1] = temp;
			}
			else if (arm[j].A_hour > arm[j + 1].A_hour)
			{
				temp = arm[j];
				arm[j] = arm[j + 1];
				arm[j + 1] = temp;
			}
			else if (arm[j].A_min > arm[j + 1].A_min)
			{
				temp = arm[j];
				arm[j] = arm[j + 1];
				arm[j + 1] = temp;
			}
		}
	}
}

int alarm_i = 0;
BOOL Check_alarm(int y, int m, int d, int h, int min) //���� �ð��� �˶��� �´��� Ȯ��
{
	for (int i = 0; i < total_alarm; i++)
	{
		if (y == arm[i].A_year)
			if (m == arm[i].A_month)
				if (d == arm[i].A_day)
					if (h == arm[i].A_hour)
						if (min == arm[i].A_min)
						{
							alarm_i = i;
							return 1;
						}
	}
	return 0;

	// ���ؼ� ������ alarmcheck ++ �� ��, ȭ����ȯ
	// �ٸ� ���α׷��� �������� ���� ����Ǿ����� ��
}


void Active_alarm(int* alarm_Chk) // �˶� �︲
{
	if (*alarm_Chk)	//���ڷ� ���� alarmChk���� 1�̶��(���� �п� ó����µǴ� �˶��̶��)
					//(���� üũ�� ���� �ʴ´ٸ� �˶��� ������ '��'�� ���������� 1�е��� ��� �˶��� �︮�� ��
	{
		system("cls");
		// �˶� ���� �����ϰ� ���� !!

		gotoxy(17, 8);  printf(" %s(��)�� %d�� �����ϼ��� ", arm[alarm_i].A_name, arm[alarm_i].A_quantity);
		
		for (int i = 0; i < 4; i++)	//2�� ���
		{
			Beep(MI, 120);
			Beep(DO, 120);
			Beep(SOL, 120);
			Beep(DO, 120);
			Beep(SOL, 120);
			Beep(RA, 120);
			Beep(SOL, 120);
			Beep(DO, 120);
			Beep(RA, 120);
			Beep(SOL, 120);
			Beep(MI, 120);
			Beep(SOL, 120);		//���� ���ǵ� ���̸��� �̿��� ���������� ���ǿ���

			Sleep(1000);		//1�� ��ǥ
		}
		system("cls");
	}

	*alarm_Chk = 0;	//�˶��� ����Ǿ����Ƿ� �ߺ��˶� ������ ���� alarmChk�� 0���� �ʱ�ȭ

	// ���� alarmcheck == 1 ������
	// alaemcheck -- ,, �ߺ������� ���� �ʱ�ȭ
}

// �˶��� ����Ͽ� ����ð��ϰ� �� �´ٸ� �︮�� 