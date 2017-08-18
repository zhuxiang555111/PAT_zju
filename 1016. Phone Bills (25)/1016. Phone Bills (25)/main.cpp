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

//**********************排序规则********************************//
//1、用户名不同，则按用户名排序
//2、否则，如果月份不同，则按月份从小到大排序
//3、否则，如果日期不同，则按日期从小到大排序
//4、否则，如果小时不同，则按小时从小到大排序
//5、否则，如果分钟不同，则按分钟从小到大排序
bool cmp(Record a, Record b)
{
	int s = strcmp(a.name, b.name);
	if (s != 0)
		return s < 0;//按用户名排序
	else if (a.month != b.month)
			return a.month < b.month;
	else if (a.day != b.day)
			return a.day < b.day;
	else if (a.hour != b.hour)
			return a.hour < b.hour;
	else
			return a.minute < b.minute;
}
//***********************排序完成***************************//

//*********************计时模块***************************//
//这段代码很好 很高效//
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
	int users = 1;//用户数量
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
	for (int i = 0; i < users - 1; i++)//处理单个用户非最后一个
	{
		int time = 0;
		double totalBill = 0;
		int needPrint = 0;
		int start = current_user[i];//从每组的第一个用户开始
		while (i < users - 1 && start != current_user[i + 1] - 1)//处理每个组
		{
			if (rec[start].status == true && rec[start + 1].status == false)//需要被处理
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
	//..........2..........//处理最后一份用户
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