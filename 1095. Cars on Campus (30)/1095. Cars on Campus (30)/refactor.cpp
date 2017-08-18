#include<iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;

const int maxn = 10010;
struct Car
{
	char plateNumber[7];
	int time;//记录的时间，用秒作为单位
	char status[4];//true-in false-out
}rec[maxn],valid[maxn];

int num = 0;//有效记录的条数
map<string, int> parkTime;//总停车时间

int timeToInt(int hh,int mm,int ss)
{
	return hh * 3600 + mm * 60 + ss;;
}


bool cmpById(Car a, Car b)
{
	if (strcmp(a.plateNumber, b.plateNumber) != 0)
		return strcmp(a.plateNumber, b.plateNumber) < 0;
	else
		return a.time < b.time;
}

bool cmpByTime(Car a, Car b)
{
	return a.time < b.time;
}

int main()
{
	int n, k, hh, mm, ss;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d:%d:%d %s", rec[i].plateNumber, &hh, &mm, &ss,rec[i].status);
		rec[i].time = timeToInt(hh, mm, ss);
	}
	sort(rec, rec + n, cmpById);
	int maxTime = -1;//最长停留时间
	
	//先处理所有车辆的最大停车时间
	for (int i = 0; i < n - 1; i++)//不选择最后一条
	{
		if (!strcmp(rec[i].plateNumber, rec[i + 1].plateNumber) &&//同一个车牌号
			!strcmp(rec[i].status, "in") &&
			!strcmp(rec[i + 1].status, "out"))
		{
			valid[num++] = rec[i];
			valid[num++] = rec[i + 1];//将两条配对的记录同时存入valid数组
			int duration = rec[i + 1].time - rec[i].time;//此次停车的时间
			if (parkTime.count(rec[i].plateNumber) == 0)
				parkTime[rec[i].plateNumber] = 0;//map中没有这个车牌号，总时间置0,这步很关键
			parkTime[rec[i].plateNumber] += duration;
			maxTime = max(maxTime, parkTime[rec[i].plateNumber]);//更新最大总停留时间，和自己比较
		}
	}
	sort(valid, valid + num, cmpByTime);
	int now = 0, numCar = 0;
	//now为在查询时间之前的第now条记录，numCar为停在校区内的车辆总数
	int query[maxn];
	for (int i = 0; i < k; i++)
	{
		scanf("%d:%d:%d", &hh, &mm, &ss);
		query[i] = timeToInt(hh, mm, ss);//转换当前查询时间
	}
	for (int i = 0; i < k; i++)
	{
		while (now < num && valid[now].time <= query[i])
		{
			if (!strcmp(valid[now].status, "in"))
				numCar++;
			else
				numCar--;
			now++;
		}
		printf("%d\n", numCar);
	}
	map<string, int>::iterator iter;
	for (iter = parkTime.begin(); iter != parkTime.end(); iter++)
	{
		if (iter->second == maxTime)
			printf("%s ", iter->first.c_str());//别忘记转成指针类型，方便printf输出
	}
	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
	system("pause");
	return 0;

}




