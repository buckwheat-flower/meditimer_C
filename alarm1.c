#include "Standard_FX.h"
#include "alarm1.h"
#include "pill.h"


//憲塋擊 綠Щ擠戲煎 轎溘й陽 餌辨ж朝 擠菟
#define DO    523
#define RE    587
#define MI    659
#define PA    698    
#define SOL   784
#define RA    880
#define SI    988
#define _DO   1046

extern int total_alarm = 0; // 憲塋 偃熱
int total_pills;


void List_alarm()
{
	int i, alarm_key;
	buble_alarm();

	system("cls");

	gotoxy(29, 1); printf("<憲塋 跡煙>");
	gotoxy(2, 16); printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	gotoxy(2, 17); printf("弛");                                    gotoxy(66, 17); printf("弛");
	gotoxy(2, 18); printf("弛");                                    gotoxy(66, 18); printf("弛");
	gotoxy(2, 19); printf("弛");                                    gotoxy(66, 19); printf("弛");
	gotoxy(2, 20); printf("弛");                                    gotoxy(66, 20); printf("弛");
	gotoxy(2, 21); printf("弛");                                    gotoxy(66, 21); printf("弛");
	gotoxy(2, 22); printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");


	gotoxy(20, 18); printf("[ 錳ж衛朝 幗が擊 揚楝輿撮蹂.]");
	gotoxy(13, 20); printf("1 : 憲塋 蛔煙  2 : 憲塋 餉薯  3 : 詭檣 詭景");


	if (total_alarm == 0)
	{
		gotoxy(22, 5); printf("[ 蛔煙脹 憲塋檜 橈蝗棲棻.]");
		gotoxy(22, 7); printf(" >> 憲塋擊 蛔煙п輿撮蹂.<<");
	}

	else
	{
		gotoxy(3, 3);  printf("廓��");
		gotoxy(9, 3);  printf("憲擒 檜葷");
		gotoxy(28, 3); printf("喇");
		gotoxy(40, 3); printf("錯");
		gotoxy(47, 3); printf("橾");
		gotoxy(54, 3); printf("衛");
		gotoxy(61, 3); printf("碟");

		gotoxy(7, 3);  printf("弛");
		gotoxy(26, 3); printf("弛");
		gotoxy(38, 3); printf("弛");
		gotoxy(45, 3); printf("弛");
		gotoxy(52, 3); printf("弛");
		gotoxy(59, 3); printf("弛");

		gotoxy(3, 4); printf("式式式式托式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式托式式式式式式托式式式式式式托式式式式式式托式式式式\n");

		for (i = 0; i < total_alarm; i++)
		{
			gotoxy(7, 5 + i);  printf("弛");
			gotoxy(26, 5 + i); printf("弛");
			gotoxy(38, 5 + i); printf("弛");
			gotoxy(45, 5 + i); printf("弛");
			gotoxy(52, 5 + i); printf("弛");
			gotoxy(59, 5 + i); printf("弛");
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
			printf("幗が擊 棻衛 揚楝輿撮蹂");
		}
		alarm_key = NULL;
	}
}


void Make_alarm() // 億 憲塋 虜菟晦
{

	int i;
	int Makealarm;
	system("cls");

	if (total_pills == 0)
	{
		gotoxy(20, 6);   printf("忙式式式式式式式式式式式  憲葡 式式式式式式式式式式忖");
		gotoxy(20, 11);  printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
		gotoxy(20, 7);  printf("弛");
		gotoxy(20, 8);  printf("弛");
		gotoxy(20, 9);  printf("弛");
		gotoxy(20, 10); printf("弛");
		gotoxy(49, 7);  printf("弛");
		gotoxy(49, 8);  printf("弛");
		gotoxy(49, 9);  printf("弛");
		gotoxy(49, 10); printf("弛");


		gotoxy(25, 8); printf("蛔煙脹 憲擒檜 橈蝗棲棻. ");
		gotoxy(24, 9); printf("  憲擒擊 蛔煙п輿撮蹂. ");

		Sleep(2500);
		system("cls");
	}

	else
	{
		total_alarm++;

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
		gotoxy(8, 3); printf("[ 憲塋擊 蛔煙ж望 錳ж朝 憲擒曖 廓�ㄧ� 揚楝輿撮蹂. ]");

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

		gotoxy(15, 3); printf("[ 憲塋擊 蛔煙й 衛除擊 殮溘п輿撮蹂.]");
		gotoxy(14, 5); printf("憲擒 檜葷: %s, �艘� : %s, 橾�� 犒辨榆 : %d", pill[Makealarm].pill_name, pill[Makealarm].pill_efficacy, pill[Makealarm].pill_quantity);

		gotoxy(12, 7); printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
		gotoxy(12, 17); printf("式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式");
		
		strcpy_s(arm[total_alarm - 1].A_name, 20, pill[Makealarm].pill_name);
		arm[total_alarm - 1].A_quantity = pill[Makealarm].pill_quantity;
		
		gotoxy(24, 8);  printf("憲塋 喇紫 : ");
		scanf_s("%d", &arm[total_alarm - 1].A_year);

		gotoxy(24, 10); printf("憲塋 錯   : ");
		scanf_s("%d", &arm[total_alarm - 1].A_month);

		gotoxy(24, 12); printf("憲塋 橾   : ");
		scanf_s("%d", &arm[total_alarm - 1].A_day);

		gotoxy(24, 14); printf("憲塋 衛除 : ");
		scanf_s("%d", &arm[total_alarm - 1].A_hour);

		gotoxy(24, 16); printf("憲塋 碟   : ");
		scanf_s("%d", &arm[total_alarm - 1].A_min);

		Sleep(1500);
		system("cls");
		gotoxy(17, 8);   printf("忙式式式式式式式式式式式式式  憲葡 式式式式式式式式式式式式式式忖");
		gotoxy(16, 9);  printf(" 弛                                  弛 ");
		gotoxy(17, 10);  printf("弛    憲塋 蛔煙檜 諫猿腎歷蝗棲棻.   弛");
		gotoxy(16, 11); printf(" 弛                                  弛 ");
		gotoxy(16, 12); printf(" 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
		Sleep(1500);
		system("cls");
	}
}


void Remove_alarm() // 錳ж朝 憲塋 餉薯
{
	system("cls");

	printf("<憲塋 餉薯>\n");

	if (total_alarm <= 0)
	{
		gotoxy(17, 8);  printf(" 忙式式式式式式式式式式式式式 憲葡 式式式式式式式式式式式式式式忖");
		gotoxy(17, 9);  printf(" 弛                                 弛");
		gotoxy(17, 10); printf(" 弛      餉薯й 憲塋檜 橈蝗棲棻.    弛");
		gotoxy(17, 11); printf(" 弛                                 弛");
		gotoxy(17, 12); printf(" 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");


		Sleep(1700);
		system("cls");
	}

	else {

		int Removealarm = NULL;
		int i = 0;

		gotoxy(12, 3); printf("[ 餉薯蒂 錳ж衛朝 憲塋曖 廓�ㄧ� 揚楝輿撮蹂. ]");

		gotoxy(3, 5);  printf("廓��");
		gotoxy(9, 5);  printf("憲擒 檜葷");
		gotoxy(28, 5); printf("喇");
		gotoxy(40, 5); printf("錯");
		gotoxy(47, 5); printf("橾");
		gotoxy(54, 5); printf("衛");
		gotoxy(61, 5); printf("碟");

		gotoxy(7, 5);  printf("弛");
		gotoxy(26, 5); printf("弛");
		gotoxy(38, 5); printf("弛");
		gotoxy(45, 5); printf("弛");
		gotoxy(52, 5); printf("弛");
		gotoxy(59, 5); printf("弛");

		gotoxy(3, 6); printf("式式式式托式式式式式式式式式式式式式式式式式式托式式式式式式式式式式式托式式式式式式托式式式式式式托式式式式式式托式式式式\n");

		for (i = 0; i < total_alarm; i++)
		{
			gotoxy(7, 7 + i);  printf("弛");
			gotoxy(26, 7 + i); printf("弛");
			gotoxy(38, 7 + i); printf("弛");
			gotoxy(45, 7 + i); printf("弛");
			gotoxy(52, 7 + i); printf("弛");
			gotoxy(59, 7 + i); printf("弛");
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
		gotoxy(17, 8);   printf("忙式式式式式式式式式式式式 憲葡 式式式式式式式式式式式式式忖");
		gotoxy(16, 9);  printf(" 弛                               弛 ");
		gotoxy(17, 10);  printf("弛   %d廓 憲塋檜 餉薯腎歷蝗棲棻.  弛", Removealarm + 1);
		gotoxy(16, 11); printf(" 弛                               弛 ");
		gotoxy(16, 12); printf(" 戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");

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
BOOL Check_alarm(int y, int m, int d, int h, int min) //⑷營 衛陝婁 憲塋檜 蜃朝雖 �挫�
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

	// 綠掖п憮 蜃戲賊 alarmcheck ++ и ��, �飛橉���
	// 棻艇 Щ煎斜極擊 褒ч醞橾 陽紫 褒ч腎橫螳撿 л
}


void Active_alarm(int* alarm_Chk) // 憲塋 選葡
{
	if (*alarm_Chk)	//檣濠煎 嫡擎 alarmChk高檜 1檜塭賊(⑷營 碟縑 籀擠轎溘腎朝 憲塋檜塭賊)
					//(虜擒 羹觼蒂 ж雖 彊朝棻賊 憲塋檜 撲薑脹 '碟'檜 部陳陽梱雖 1碟翕寰 啗樓 憲塋檜 選葬啪 脾
	{
		system("cls");
		// 憲塋 牖憮 唸薑ж堅 嗥辦晦 !!

		gotoxy(17, 8);  printf(" %s(擊)蒂 %d薑 犒辨ж撮蹂 ", arm[alarm_i].A_name, arm[alarm_i].A_quantity);
		
		for (int i = 0; i < 4; i++)	//2廓 轎溘
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
			Beep(SOL, 120);		//瞪縑 薑曖脹 啗檜葷擊 檜辨п 綠Щ擠戲煎 擠學翱輿

			Sleep(1000);		//1蟾 蔑ル
		}
		system("cls");
	}

	*alarm_Chk = 0;	//憲塋檜 褒ч腎歷戲嘎煎 醞犒憲塋 寞雖蒂 嬪п alarmChk蒂 0戲煎 蟾晦��

	// 虜擒 alarmcheck == 1 綠Щ擠
	// alaemcheck -- ,, 醞犒寞雖蒂 嬪п 蟾晦��
}

// 憲塋擊 蛔煙ж罹 ⑷營衛除ж堅 綠掖 蜃棻賊 選葬堅 