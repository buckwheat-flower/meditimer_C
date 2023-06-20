#include "Standard_FX.h"
#include "pill.h"
#include "alarm1.h"

extern int total_pills = 0; // �˾� ���� 

void List_pill()
{
	system("cls");
	int i;
	int Listpill;

	gotoxy(29, 1); printf("<�˾� ���>");
	gotoxy(2, 16); printf("����������������������������������������������������������������������������������������������������������������������������������");
	gotoxy(2, 17); printf("��");                                    gotoxy(66, 17); printf("��");
	gotoxy(2, 18); printf("��");                                    gotoxy(66, 18); printf("��");
	gotoxy(2, 19); printf("��");                                    gotoxy(66, 19); printf("��");
	gotoxy(2, 20); printf("��");                                    gotoxy(66, 20); printf("��");
	gotoxy(2, 21); printf("��");                                    gotoxy(66, 21); printf("��");
	gotoxy(2, 22); printf("����������������������������������������������������������������������������������������������������������������������������������");


	gotoxy(20, 18); printf("[ ���Ͻô� ��ư�� �����ּ���.]");
	gotoxy(6, 20); printf("1 : �˾� ���  2 : �˾� ����  3 : �˾� ����  4 : ���� �޴�");

	if (total_pills == 0)
	{
		gotoxy(22, 5); printf("[ ��ϵ� �˾��� �����ϴ�.]");
		gotoxy(22, 7); printf(" >> �˾��� ������ּ���.<<");
	}

	else
	{
		gotoxy(5, 4); printf("��ȣ ��");
		gotoxy(13, 4); printf("�˾� �̸�\t\t   ȿ��               ��ȸ ���뷮");
		gotoxy(32, 4); printf("��");
		gotoxy(51, 4); printf("��");
		gotoxy(5, 5); printf("������");
		gotoxy(8, 5); printf("����������������������������������������������������������������������������������������������������������������");

		for (i = 0; i < total_pills; i++)
		{

			gotoxy(32, 6 + i); printf("��");
			gotoxy(51, 6 + i); printf("��");
			gotoxy(10, 6 + i); printf("��");
			gotoxy(5, 6 + i); printf("[%d]", i + 1);
			gotoxy(13, 6 + i); printf("%s", pill[i].pill_name);
			gotoxy(35, 6 + i); printf("%s", pill[i].pill_efficacy);
			gotoxy(54, 6 + i); printf("%d", pill[i].pill_quantity);

		}
	}

	while (1)
	{
		if (_kbhit())
		{
			Listpill = _getch();
			switch (Listpill)
			{
			case '1':
				Make_pill();
				MainUI();
			case '2':
				Remove_pill();
				MainUI();
			case '3':
				mdfpill();
				MainUI();

			case '4':
				MainUI();
			default:
				Sleep(1000);
				system("cls");
				printf("��ư�� �ٽ� �����ּ���");
			}
			Listpill = NULL;
		}

	}

}

void Make_pill()
{
	system("cls");
	gotoxy(28, 6); printf("<�˾� ���>\n");
	total_pills++;
	gotoxy(12, 7); printf("������������������������������������������������������������������������������������������");
	gotoxy(12, 13); printf("������������������������������������������������������������������������������������������");
	gotoxy(24, 8); printf("�˾� �̸� : ");
	scanf_s("%s", pill[total_pills - 1].pill_name, 20);
	gotoxy(24, 10); printf("�˾� ȿ�� : ");
	scanf_s("%s", pill[total_pills - 1].pill_efficacy, 20);
	gotoxy(24, 12); printf("��ȸ ���뷮 : ");
	scanf_s("%d", &pill[total_pills - 1].pill_quantity);

	Sleep(1000);
	system("cls");
	gotoxy(17, 9);   printf("����������������������������  �˸� ������������������������������");
	gotoxy(16, 10); printf(" ��                                  �� ");
	gotoxy(17, 11);  printf("��    �˾� ����� �Ϸ�Ǿ����ϴ�.   ��");
	gotoxy(16, 12); printf(" ��                                  �� ");
	gotoxy(16, 13); printf(" ������������������������������������������������������������������������");
	Sleep(1700);
	system("cls");
}

void Remove_pill()
{
	system("cls");

	if (total_pills == 0)
	{
		gotoxy(17, 8);  printf(" ���������������������������� �˸� ������������������������������");
		gotoxy(17, 9);  printf(" ��                                 ��");
		gotoxy(17, 10); printf(" ��      ������ �˾��� �����ϴ�.    ��");
		gotoxy(17, 11); printf(" ��                                 ��");
		gotoxy(17, 12); printf(" ����������������������������������������������������������������������");
		Sleep(1700);
		system("cls");
	}
	else {

		int Removepill = NULL;
		int i = 0;

		gotoxy(12, 3); printf("[ ������ ���Ͻô� �˾��� ��ȣ�� �����ּ���. ]");
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


		/*printf("\n\n\n������ �˾� ��ȣ :");
		scanf_s("%d", &Removepill);
		while (Removepill <= 0 || Removepill > total_pills)
		{
			printf("�˾� ��ȣ�� �ٽ� �Է����ּ��� : ");
			scanf_s("%d", &Removepill);

			Sleep(1500);
			system("cls");
		}

		Removepill;*/
		while (1)
		{
			if (_kbhit())
			{
				Removepill = _getch();
				Removepill = Removepill - 49;
				if (Removepill < total_pills && Removepill >= 0)
				{
					for (int i = 0; i < total_pills; i++)
					{
						if (Removepill == i)
						{
							for (int j = Removepill; j < total_pills; j++)
							{
								pill[j] = pill[j + 1];
							}
						}
					}
					break;
				}

			}
		}

		total_pills--;

		system("cls");
		gotoxy(17, 9); printf("�������������������������� �˸� ����������������������������");
		gotoxy(16, 10); printf(" ��                               �� ");
		gotoxy(17, 11); printf("��   %d�� �˾��� �����Ǿ����ϴ�.  ��", Removepill + 1);
		gotoxy(16, 12); printf(" ��                               �� ");
		gotoxy(16, 13); printf(" ������������������������������������������������������������������");

		Sleep(1700);
		system("cls");
	}

	system("cls");

}

void mdfpill()
{
	system("cls");
	int i;
	int Modifypill; // ���� ��
	int idx = NULL; // �� ��


	if (total_pills == 0)
	{
		Sleep(100);
		system("cls");
		gotoxy(14, 8); printf(" ������������������������������������ �˸� ������������������������������������");
		gotoxy(14, 9); printf(" ��                                        ��");
		gotoxy(14, 10); printf(" ��      ���� �� �� �ִ� ���� �����ϴ�.    ��");
		gotoxy(14, 11); printf(" ��                                        ��");
		gotoxy(14, 12); printf(" ������������������������������������������������������������������������������������");
		Sleep(1700);
	}


	else
	{

		gotoxy(12, 3); printf("[ ������ ���Ͻô� �˾��� ��ȣ�� �����ּ���. ]");
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

		while (1)
		{
			if (_kbhit())
			{
				Modifypill = _getch();
				Modifypill = Modifypill - 49;
				if (Modifypill < total_pills && Modifypill >= 0)
				{
					for (i = 0; i < total_pills; i++)
					{
						if (Modifypill == i)
						{
							idx = i;
							Modifypill = NULL;
						}
					}
					break;
				}
			}

		}
	}

	//idx��° �� ����
	//������ �� �Ӽ� �� ���� �Է�
	system("cls");
	gotoxy(14, 6);  printf("[1] : �˾� �̸�  [2] : ȿ��  [3] : ��ȸ ���뷮");
	gotoxy(10, 8);  printf(" ��������������������������������������������������������������������������������������������������");
	gotoxy(10, 9);  printf(" ��                                               ��");
	gotoxy(10, 10); printf(" ��    ������ ���Ͻô� ������ ��ȣ�� �����ּ���.  ��");
	gotoxy(10, 11); printf(" ��                                               ��");
	gotoxy(10, 12); printf(" ��������������������������������������������������������������������������������������������������");
	//������ ���� �Է� �޾ƾ���



	while (1)
	{
		char buf[20] = { 0 };
		int tmp = 0;

		if (_kbhit())
		{
			switch (_getch())
			{
			case '1':

				system("cls");
				gotoxy(21, 6);
				printf("�˾��� �̸��� �Է����ּ���.");

				gotoxy(11, 8);
				printf("��������������������������������������������������������������������������������������������");
				gotoxy(11, 12);
				printf("��������������������������������������������������������������������������������������������");

				gotoxy(26, 10); printf(">> "); 	scanf_s("%s", buf, 20);

				strcpy_s(pill[idx].pill_name, 20, buf);
				break;

			case '2':

				system("cls");
				gotoxy(21, 6); printf("�˾��� ȿ���� �Է����ּ���.");
				gotoxy(11, 8); printf("��������������������������������������������������������������������������������������������");
				gotoxy(11, 12); printf("��������������������������������������������������������������������������������������������");

				gotoxy(26, 10); printf(">> "); scanf_s("%s", buf, 20);

				strcpy_s(pill[idx].pill_efficacy, 20, buf);
				break;

			case '3':

				system("cls");
				gotoxy(18, 6); printf("�˾��� ��ȸ ���뷮�� �Է����ּ���.");
				gotoxy(11, 8); printf("��������������������������������������������������������������������������������������������");
				gotoxy(11, 12); printf("��������������������������������������������������������������������������������������������");
				gotoxy(32, 10); printf(">> "); scanf_s("%d", &tmp);

				pill[idx].pill_quantity = tmp;
				break;

			default:
				Sleep(1000);
				system("cls");
				printf("��ư�� �ٽ� �����ּ���");
			}
			break;
		}

	}

	system("cls");
	gotoxy(16, 8); printf(" ������������������������������ �˸� ������������������������������");
	gotoxy(16, 9); printf(" ��                                  ��");
	gotoxy(16, 10); printf(" ��    �˾� ������ �Ϸ�Ǿ����ϴ�.   ��");
	gotoxy(16, 11); printf(" ��                                  ��");
	gotoxy(16, 12); printf(" ������������������������������������������������������������������������");
	Sleep(1700);

	system("cls");
}


