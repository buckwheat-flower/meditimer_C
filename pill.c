#include "Standard_FX.h"
#include "pill.h"
#include "alarm1.h"

extern int total_pills = 0; // 憲擒 偃熱 

void List_pill()
{
	system("cls");
	int i;
	int Listpill;

	gotoxy(29, 1); printf("<憲擒 跡煙>");
	gotoxy(2, 16); printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	gotoxy(2, 17); printf("弛");                                    gotoxy(66, 17); printf("弛");
	gotoxy(2, 18); printf("弛");                                    gotoxy(66, 18); printf("弛");
	gotoxy(2, 19); printf("弛");                                    gotoxy(66, 19); printf("弛");
	gotoxy(2, 20); printf("弛");                                    gotoxy(66, 20); printf("弛");
	gotoxy(2, 21); printf("弛");                                    gotoxy(66, 21); printf("弛");
	gotoxy(2, 22); printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");


	gotoxy(20, 18); printf("[ 錳ж衛朝 幗が擊 揚楝輿撮蹂.]");
	gotoxy(6, 20); printf("1 : 憲擒 蛔煙  2 : 憲擒 餉薯  3 : 憲擒 熱薑  4 : 詭檣 詭景");

	if (total_pills == 0)
	{
		gotoxy(22, 5); printf("[ 蛔煙脹 憲擒檜 橈蝗棲棻.]");
		gotoxy(22, 7); printf(" >> 憲擒擊 蛔煙п輿撮蹂.<<");
	}

	else
	{
		gotoxy(5, 4); printf("廓�� 弛");
		gotoxy(13, 4); printf("憲擒 檜葷\t\t   �艘�               橾�� 犒辨榆");
		gotoxy(32, 4); printf("弛");
		gotoxy(51, 4); printf("弛");
		gotoxy(5, 5); printf("式式式");
		gotoxy(8, 5); printf("式式托式式式式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式");

		for (i = 0; i < total_pills; i++)
		{

			gotoxy(32, 6 + i); printf("弛");
			gotoxy(51, 6 + i); printf("弛");
			gotoxy(10, 6 + i); printf("弛");
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
				printf("幗が擊 棻衛 揚楝輿撮蹂");
			}
			Listpill = NULL;
		}

	}

}

void Make_pill()
{
	system("cls");
	gotoxy(28, 6); printf("<憲擒 蛔煙>\n");
	total_pills++;
	gotoxy(12, 7); printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	gotoxy(12, 13); printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
	gotoxy(24, 8); printf("憲擒 檜葷 : ");
	scanf_s("%s", pill[total_pills - 1].pill_name, 20);
	gotoxy(24, 10); printf("憲擒 �艘� : ");
	scanf_s("%s", pill[total_pills - 1].pill_efficacy, 20);
	gotoxy(24, 12); printf("橾�� 犒辨榆 : ");
	scanf_s("%d", &pill[total_pills - 1].pill_quantity);

	Sleep(1000);
	system("cls");
	gotoxy(17, 9);   printf("忙式式式式式式式式式式式式式  憲葡 式式式式式式式式式式式式式式忖");
	gotoxy(16, 10); printf(" 弛                                  弛 ");
	gotoxy(17, 11);  printf("弛    憲擒 蛔煙檜 諫猿腎歷蝗棲棻.   弛");
	gotoxy(16, 12); printf(" 弛                                  弛 ");
	gotoxy(16, 13); printf(" 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	Sleep(1700);
	system("cls");
}

void Remove_pill()
{
	system("cls");

	if (total_pills == 0)
	{
		gotoxy(17, 8);  printf(" 忙式式式式式式式式式式式式式 憲葡 式式式式式式式式式式式式式式忖");
		gotoxy(17, 9);  printf(" 弛                                 弛");
		gotoxy(17, 10); printf(" 弛      餉薯й 憲擒檜 橈蝗棲棻.    弛");
		gotoxy(17, 11); printf(" 弛                                 弛");
		gotoxy(17, 12); printf(" 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
		Sleep(1700);
		system("cls");
	}
	else {

		int Removepill = NULL;
		int i = 0;

		gotoxy(12, 3); printf("[ 餉薯蒂 錳ж衛朝 憲擒曖 廓�ㄧ� 揚楝輿撮蹂. ]");
		gotoxy(5, 5); printf("廓�� 弛");
		gotoxy(13, 5); printf("憲擒 檜葷\t\t   �艘�               橾�� 犒辨榆");
		gotoxy(32, 5); printf("弛");
		gotoxy(51, 5); printf("弛");
		gotoxy(5, 6); printf("式式式");
		gotoxy(8, 6); printf("式式托式式式式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式");

		for (i = 0; i < total_pills; i++)
		{

			gotoxy(32, 7 + i); printf("弛");
			gotoxy(51, 7 + i); printf("弛");
			gotoxy(10, 7 + i); printf("弛");
			gotoxy(5, 7 + i); printf("[%d]", i + 1);
			gotoxy(13, 7 + i); printf("%s", pill[i].pill_name);
			gotoxy(35, 7 + i); printf("%s", pill[i].pill_efficacy);
			gotoxy(54, 7 + i); printf("%d", pill[i].pill_quantity);

		}


		/*printf("\n\n\n餉薯й 憲擒 廓�� :");
		scanf_s("%d", &Removepill);
		while (Removepill <= 0 || Removepill > total_pills)
		{
			printf("憲擒 廓�ㄧ� 棻衛 殮溘п輿撮蹂 : ");
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
		gotoxy(17, 9); printf("忙式式式式式式式式式式式式 憲葡 式式式式式式式式式式式式式忖");
		gotoxy(16, 10); printf(" 弛                               弛 ");
		gotoxy(17, 11); printf("弛   %d廓 憲擒檜 餉薯腎歷蝗棲棻.  弛", Removepill + 1);
		gotoxy(16, 12); printf(" 弛                               弛 ");
		gotoxy(16, 13); printf(" 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");

		Sleep(1700);
		system("cls");
	}

	system("cls");

}

void mdfpill()
{
	system("cls");
	int i;
	int Modifypill; // 熱薑 高
	int idx = NULL; // 綠掖 高


	if (total_pills == 0)
	{
		Sleep(100);
		system("cls");
		gotoxy(14, 8); printf(" 忙式式式式式式式式式式式式式式式式式 憲葡 式式式式式式式式式式式式式式式式式忖");
		gotoxy(14, 9); printf(" 弛                                        弛");
		gotoxy(14, 10); printf(" 弛      熱薑 й 熱 氈朝 擒檜 橈蝗棲棻.    弛");
		gotoxy(14, 11); printf(" 弛                                        弛");
		gotoxy(14, 12); printf(" 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
		Sleep(1700);
	}


	else
	{

		gotoxy(12, 3); printf("[ 熱薑擊 錳ж衛朝 憲擒曖 廓�ㄧ� 揚楝輿撮蹂. ]");
		gotoxy(5, 5); printf("廓�� 弛");
		gotoxy(13, 5); printf("憲擒 檜葷\t\t   �艘�               橾�� 犒辨榆");
		gotoxy(32, 5); printf("弛");
		gotoxy(51, 5); printf("弛");
		gotoxy(5, 6); printf("式式式");
		gotoxy(8, 6); printf("式式托式式式式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式式");

		for (i = 0; i < total_pills; i++)
		{

			gotoxy(32, 7 + i); printf("弛");
			gotoxy(51, 7 + i); printf("弛");
			gotoxy(10, 7 + i); printf("弛");
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

	//idx廓簞 高 滲唳
	//滲唳擊 й 樓撩 塽 薑爾 殮溘
	system("cls");
	gotoxy(14, 6);  printf("[1] : 憲擒 檜葷  [2] : �艘�  [3] : 橾�� 犒辨榆");
	gotoxy(10, 8);  printf(" 忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	gotoxy(10, 9);  printf(" 弛                                               弛");
	gotoxy(10, 10); printf(" 弛    熱薑擊 錳ж衛朝 頂辨曖 廓�ㄧ� 揚楝輿撮蹂.  弛");
	gotoxy(10, 11); printf(" 弛                                               弛");
	gotoxy(10, 12); printf(" 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	//滲唳й 高擊 殮溘 嫡嬴撿л



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
				printf("憲擒曖 檜葷擊 殮溘п輿撮蹂.");

				gotoxy(11, 8);
				printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
				gotoxy(11, 12);
				printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");

				gotoxy(26, 10); printf(">> "); 	scanf_s("%s", buf, 20);

				strcpy_s(pill[idx].pill_name, 20, buf);
				break;

			case '2':

				system("cls");
				gotoxy(21, 6); printf("憲擒曖 �艘劦� 殮溘п輿撮蹂.");
				gotoxy(11, 8); printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
				gotoxy(11, 12); printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");

				gotoxy(26, 10); printf(">> "); scanf_s("%s", buf, 20);

				strcpy_s(pill[idx].pill_efficacy, 20, buf);
				break;

			case '3':

				system("cls");
				gotoxy(18, 6); printf("憲擒曖 橾�� 犒辨榆擊 殮溘п輿撮蹂.");
				gotoxy(11, 8); printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
				gotoxy(11, 12); printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
				gotoxy(32, 10); printf(">> "); scanf_s("%d", &tmp);

				pill[idx].pill_quantity = tmp;
				break;

			default:
				Sleep(1000);
				system("cls");
				printf("幗が擊 棻衛 揚楝輿撮蹂");
			}
			break;
		}

	}

	system("cls");
	gotoxy(16, 8); printf(" 忙式式式式式式式式式式式式式式 憲葡 式式式式式式式式式式式式式式忖");
	gotoxy(16, 9); printf(" 弛                                  弛");
	gotoxy(16, 10); printf(" 弛    憲擒 熱薑檜 諫猿腎歷蝗棲棻.   弛");
	gotoxy(16, 11); printf(" 弛                                  弛");
	gotoxy(16, 12); printf(" 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
	Sleep(1700);

	system("cls");
}


