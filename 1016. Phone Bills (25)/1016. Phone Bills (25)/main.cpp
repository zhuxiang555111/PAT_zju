#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int toll[24];

struct Record
{
	char name[20];
	int month, day, hour, minute;;//can be fixed 00:00:00:00
	bool status; //1:on-line 0:off-line
} rec[1500];

//**********************�������********************************//
//1���û�����ͬ�����û�������
//2����������·ݲ�ͬ�����·ݴ�С��������
//3������������ڲ�ͬ�������ڴ�С��������
//4���������Сʱ��ͬ����Сʱ��С��������
//5������������Ӳ�ͬ���򰴷��Ӵ�С��������
bool cmp(Record a, Record b)
{
	int s = strcmp(a.name, b.name);
	if (s != 0)
		return s < 0;//���û�������
	else if (a.month != b.month)
			return a.month < b.month;
	else if (a.day != b.day)
			return a.day < b.day;
	else if (a.hour != b.hour)
			return a.hour < b.hour;
	else
			return a.minute < b.minute;
}
//***********************�������***************************//

//*********************��ʱģ��***************************//
//��δ���ܺ� �ܸ�Ч//
double get_bill(Record a, Record b,int& totalTime)
{
	totalTime = 0;
	double bill = 0;
	while (a.day < b.day || a.hour < b.hour || a.minute < b.minute)
	{
		totalTime++;
		bill += toll[a.hour];
		a.minute++;
		if (a.minute >= 60)
		{
			a.minute = 0;
			a.hour++;
		}
		if (a.hour >= 24)
		{
			a.hour = 0;
			a.day++;
		}
	}
	return bill/100;
}
//.......................................................//

int main()
{
	
	int N;//N
	for (int i = 0; i < 24; i++)
	{
		scanf("%d", &toll[i]);
	}
	scanf("%d", &N);
	if (N == 0)
		return 0;
	for (int i = 0; i < N; i++)
	{
		char line[10];
		scanf("%s", &rec[i].name);
		scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].day, &rec[i].hour, &rec[i].minute);
		scanf("%s", line);
		if (strcmp(line, "on-line") == 0)
			rec[i].status = true;
		else
			rec[i].status = false;
	}
	sort(rec, rec + N, cmp);
	int users = 1;//�û�����
	vector<int> current_user;
	current_user.push_back(0);
	for (int i = 1; i < N; i++)
	{
		if (strcmp(rec[i].name, rec[i - 1].name) != 0)
		{
			users += 1;
			current_user.push_back(i);
		}
	}
	//........1.........//
	for (int i = 0; i < users - 1; i++)//�������û������һ��
	{
		int time = 0;
		double totalBill = 0;
		int needPrint = 0;
		int start = current_user[i];//��ÿ��ĵ�һ���û���ʼ
		while (i < users - 1 && start != current_user[i + 1] - 1)//����ÿ����
		{
			if (rec[start].status == true && rec[start + 1].status == false)//��Ҫ������
			{
				needPrint++;
				if (needPrint < 2)
				{
					cout << rec[start].name << " ";
					printf("%02d\n", rec[start].month);
				}
				printf("%02d:%02d:%02d ", rec[start].day, rec[start].hour, rec[start].minute);
				printf("%02d:%02d:%02d ", rec[start + 1].day, rec[start + 1].hour, rec[start + 1].minute);
				printf("%d $%.2f\n", time,get_bill(rec[start], rec[start + 1],time));
				totalBill += get_bill(rec[start], rec[start + 1],time);
				start++;
			}
			else
				start++;
		}
		if(needPrint > 0)
		{
			cout << "Total amount: " << "$";
			printf("%.2f\n", totalBill);
		}
	}
	//..........2..........//�������һ���û�
	int start = current_user[users-1];
	int needPrint = 0;
	double totalBill = 0;
	int time = 0;
	while (start != N - 1)
	{
		if (rec[start].status == true && rec[start + 1].status == false)
		{
			needPrint++;
			if (needPrint < 2)
			{
				cout << rec[start].name << " ";
				printf("%02d\n", rec[start].month);
			}
			printf("%02d:%02d:%02d ", rec[start].day, rec[start].hour, rec[start].minute);
			printf("%02d:%02d:%02d ", rec[start + 1].day, rec[start + 1].hour, rec[start + 1].minute);
			printf("%d $%.2f\n", time,get_bill(rec[start], rec[start + 1],time));
			totalBill += get_bill(rec[start], rec[start + 1],time);
			start++;
		}
		else
			start++;
	}
	if(needPrint > 0)
	{
		cout << "Total amount: " << "$";
		printf("%.2f\n", totalBill);
	}
	system("pause");
}