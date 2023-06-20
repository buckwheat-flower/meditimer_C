void Make_alarm();
void Remove_alarm();
//void Now_time();
BOOL Check_alarm(int y, int m, int d, int h, int min);
void Active_alarm(int* alarm_Chk);
void List_alarm();
void buble_alarm();



struct alarm
{
	char A_name[20];
	int A_year;
	int A_month;
	int A_day;
	int A_hour;
	int A_min;
	int A_quantity;
	// 알람 시간, 분 입력
} arm[10], temp;

