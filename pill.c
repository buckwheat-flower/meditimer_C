#include "Standard_FX.h"
#include "pill.h"
#include "alarm1.h"

extern int total_pills = 0; // ¾Ë¾à °³¼ö 

void List_pill()
{
	system("cls");
	int i;
	int Listpill;

	gotoxy(29, 1); printf("<¾Ë¾à ¸ñ·Ï>");
	gotoxy(2, 16); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	gotoxy(2, 17); printf("¦¢");                                    gotoxy(66, 17); printf("¦¢");
	gotoxy(2, 18); printf("¦¢");                                    gotoxy(66, 18); printf("¦¢");
	gotoxy(2, 19); printf("¦¢");                                    gotoxy(66, 19); printf("¦¢");
	gotoxy(2, 20); printf("¦¢");                                    gotoxy(66, 20); printf("¦¢");
	gotoxy(2, 21); printf("¦¢");                                    gotoxy(66, 21); printf("¦¢");
	gotoxy(2, 22); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");


	gotoxy(20, 18); printf("[ ¿øÇÏ½Ã´Â ¹öÆ°À» ´­·¯ÁÖ¼¼¿ä.]");
	gotoxy(6, 20); printf("1 : ¾Ë¾à µî·Ï  2 : ¾Ë¾à »èÁ¦  3 : ¾Ë¾à ¼öÁ¤  4 : ¸ÞÀÎ ¸Þ´º");

	if (total_pills == 0)
	{
		gotoxy(22, 5); printf("[ µî·ÏµÈ ¾Ë¾àÀÌ ¾ø½À´Ï´Ù.]");
		gotoxy(22, 7); printf(" >> ¾Ë¾àÀ» µî·ÏÇØÁÖ¼¼¿ä.<<");
	}

	else
	{
		gotoxy(5, 4); printf("¹øÈ£ ¦¢");
		gotoxy(13, 4); printf("¾Ë¾à ÀÌ¸§\t\t   È¿´É               ÀÏÈ¸ º¹¿ë·®");
		gotoxy(32, 4); printf("¦¢");
		gotoxy(51, 4); printf("¦¢");
		gotoxy(5, 5); printf("¦¡¦¡¦¡");
		gotoxy(8, 5); printf("¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");

		for (i = 0; i < total_pills; i++)
		{

			gotoxy(32, 6 + i); printf("¦¢");
			gotoxy(51, 6 + i); printf("¦¢");
			gotoxy(10, 6 + i); printf("¦¢");
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
				printf("¹öÆ°À» ´Ù½Ã ´­·¯ÁÖ¼¼¿ä");
			}
			Listpill = NULL;
		}

	}

}

void Make_pill()
{
	system("cls");
	gotoxy(28, 6); printf("<¾Ë¾à µî·Ï>\n");
	total_pills++;
	gotoxy(12, 7); printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");
	gotoxy(12, 13); printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");
	gotoxy(24, 8); printf("¾Ë¾à ÀÌ¸§ : ");
	scanf_s("%s", pill[total_pills - 1].pill_name, 20);
	gotoxy(24, 10); printf("¾Ë¾à È¿´É : ");
	scanf_s("%s", pill[total_pills - 1].pill_efficacy, 20);
	gotoxy(24, 12); printf("ÀÏÈ¸ º¹¿ë·® : ");
	scanf_s("%d", &pill[total_pills - 1].pill_quantity);

	Sleep(1000);
	system("cls");
	gotoxy(17, 9);   printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡  ¾Ë¸² ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	gotoxy(16, 10); printf(" ¦¢                                  ¦¢ ");
	gotoxy(17, 11);  printf("¦¢    ¾Ë¾à µî·ÏÀÌ ¿Ï·áµÇ¾ú½À´Ï´Ù.   ¦¢");
	gotoxy(16, 12); printf(" ¦¢                                  ¦¢ ");
	gotoxy(16, 13); printf(" ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	Sleep(1700);
	system("cls");
}

void Remove_pill()
{
	system("cls");

	if (total_pills == 0)
	{
		gotoxy(17, 8);  printf(" ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡ ¾Ë¸² ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
		gotoxy(17, 9);  printf(" ¦¢                                 ¦¢");
		gotoxy(17, 10); printf(" ¦¢      »èÁ¦ÇÒ ¾Ë¾àÀÌ ¾ø½À´Ï´Ù.    ¦¢");
		gotoxy(17, 11); printf(" ¦¢                                 ¦¢");
		gotoxy(17, 12); printf(" ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
		Sleep(1700);
		system("cls");
	}
	else {

		int Removepill = NULL;
		int i = 0;

		gotoxy(12, 3); printf("[ »èÁ¦¸¦ ¿øÇÏ½Ã´Â ¾Ë¾àÀÇ ¹øÈ£¸¦ ´­·¯ÁÖ¼¼¿ä. ]");
		gotoxy(5, 5); printf("¹øÈ£ ¦¢");
		gotoxy(13, 5); printf("¾Ë¾à ÀÌ¸§\t\t   È¿´É               ÀÏÈ¸ º¹¿ë·®");
		gotoxy(32, 5); printf("¦¢");
		gotoxy(51, 5); printf("¦¢");
		gotoxy(5, 6); printf("¦¡¦¡¦¡");
		gotoxy(8, 6); printf("¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");

		for (i = 0; i < total_pills; i++)
		{

			gotoxy(32, 7 + i); printf("¦¢");
			gotoxy(51, 7 + i); printf("¦¢");
			gotoxy(10, 7 + i); printf("¦¢");
			gotoxy(5, 7 + i); printf("[%d]", i + 1);
			gotoxy(13, 7 + i); printf("%s", pill[i].pill_name);
			gotoxy(35, 7 + i); printf("%s", pill[i].pill_efficacy);
			gotoxy(54, 7 + i); printf("%d", pill[i].pill_quantity);

		}


		/*printf("\n\n\n»èÁ¦ÇÒ ¾Ë¾à ¹øÈ£ :");
		scanf_s("%d", &Removepill);
		while (Removepill <= 0 || Removepill > total_pills)
		{
			printf("¾Ë¾à ¹øÈ£¸¦ ´Ù½Ã ÀÔ·ÂÇØÁÖ¼¼¿ä : ");
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
		gotoxy(17, 9); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡ ¾Ë¸² ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
		gotoxy(16, 10); printf(" ¦¢                               ¦¢ ");
		gotoxy(17, 11); printf("¦¢   %d¹ø ¾Ë¾àÀÌ »èÁ¦µÇ¾ú½À´Ï´Ù.  ¦¢", Removepill + 1);
		gotoxy(16, 12); printf(" ¦¢                               ¦¢ ");
		gotoxy(16, 13); printf(" ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");

		Sleep(1700);
		system("cls");
	}

	system("cls");

}

void mdfpill()
{
	system("cls");
	int i;
	int Modifypill; // ¼öÁ¤ °ª
	int idx = NULL; // ºñ±³ °ª


	if (total_pills == 0)
	{
		Sleep(100);
		system("cls");
		gotoxy(14, 8); printf(" ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡ ¾Ë¸² ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
		gotoxy(14, 9); printf(" ¦¢                                        ¦¢");
		gotoxy(14, 10); printf(" ¦¢      ¼öÁ¤ ÇÒ ¼ö ÀÖ´Â ¾àÀÌ ¾ø½À´Ï´Ù.    ¦¢");
		gotoxy(14, 11); printf(" ¦¢                                        ¦¢");
		gotoxy(14, 12); printf(" ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
		Sleep(1700);
	}


	else
	{

		gotoxy(12, 3); printf("[ ¼öÁ¤À» ¿øÇÏ½Ã´Â ¾Ë¾àÀÇ ¹øÈ£¸¦ ´­·¯ÁÖ¼¼¿ä. ]");
		gotoxy(5, 5); printf("¹øÈ£ ¦¢");
		gotoxy(13, 5); printf("¾Ë¾à ÀÌ¸§\t\t   È¿´É               ÀÏÈ¸ º¹¿ë·®");
		gotoxy(32, 5); printf("¦¢");
		gotoxy(51, 5); printf("¦¢");
		gotoxy(5, 6); printf("¦¡¦¡¦¡");
		gotoxy(8, 6); printf("¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");

		for (i = 0; i < total_pills; i++)
		{

			gotoxy(32, 7 + i); printf("¦¢");
			gotoxy(51, 7 + i); printf("¦¢");
			gotoxy(10, 7 + i); printf("¦¢");
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

	//idx¹øÂ° °ª º¯°æ
	//º¯°æÀ» ÇÒ ¼Ó¼º ¹× Á¤º¸ ÀÔ·Â
	system("cls");
	gotoxy(14, 6);  printf("[1] : ¾Ë¾à ÀÌ¸§  [2] : È¿´É  [3] : ÀÏÈ¸ º¹¿ë·®");
	gotoxy(10, 8);  printf(" ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	gotoxy(10, 9);  printf(" ¦¢                                               ¦¢");
	gotoxy(10, 10); printf(" ¦¢    ¼öÁ¤À» ¿øÇÏ½Ã´Â ³»¿ëÀÇ ¹øÈ£¸¦ ´­·¯ÁÖ¼¼¿ä.  ¦¢");
	gotoxy(10, 11); printf(" ¦¢                                               ¦¢");
	gotoxy(10, 12); printf(" ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	//º¯°æÇÒ °ªÀ» ÀÔ·Â ¹Þ¾Æ¾ßÇÔ



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
				printf("¾Ë¾àÀÇ ÀÌ¸§À» ÀÔ·ÂÇØÁÖ¼¼¿ä.");

				gotoxy(11, 8);
				printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");
				gotoxy(11, 12);
				printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");

				gotoxy(26, 10); printf(">> "); 	scanf_s("%s", buf, 20);

				strcpy_s(pill[idx].pill_name, 20, buf);
				break;

			case '2':

				system("cls");
				gotoxy(21, 6); printf("¾Ë¾àÀÇ È¿´ÉÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä.");
				gotoxy(11, 8); printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");
				gotoxy(11, 12); printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");

				gotoxy(26, 10); printf(">> "); scanf_s("%s", buf, 20);

				strcpy_s(pill[idx].pill_efficacy, 20, buf);
				break;

			case '3':

				system("cls");
				gotoxy(18, 6); printf("¾Ë¾àÀÇ ÀÏÈ¸ º¹¿ë·®À» ÀÔ·ÂÇØÁÖ¼¼¿ä.");
				gotoxy(11, 8); printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");
				gotoxy(11, 12); printf("¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡");
				gotoxy(32, 10); printf(">> "); scanf_s("%d", &tmp);

				pill[idx].pill_quantity = tmp;
				break;

			default:
				Sleep(1000);
				system("cls");
				printf("¹öÆ°À» ´Ù½Ã ´­·¯ÁÖ¼¼¿ä");
			}
			break;
		}

	}

	system("cls");
	gotoxy(16, 8); printf(" ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡ ¾Ë¸² ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	gotoxy(16, 9); printf(" ¦¢                                  ¦¢");
	gotoxy(16, 10); printf(" ¦¢    ¾Ë¾à ¼öÁ¤ÀÌ ¿Ï·áµÇ¾ú½À´Ï´Ù.   ¦¢");
	gotoxy(16, 11); printf(" ¦¢                                  ¦¢");
	gotoxy(16, 12); printf(" ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	Sleep(1700);

	system("cls");
}


