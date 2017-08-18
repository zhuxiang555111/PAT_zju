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
	int time;//��¼��ʱ�䣬������Ϊ��λ
	char status[4];//true-in false-out
}rec[maxn],valid[maxn];

int num = 0;//��Ч��¼������
map<string, int> parkTime;//��ͣ��ʱ��

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
	int maxTime = -1;//�ͣ��ʱ��
	
	//�ȴ������г��������ͣ��ʱ��
	for (int i = 0; i < n - 1; i++)//��ѡ�����һ��
	{
		if (!strcmp(rec[i].plateNumber, rec[i + 1].plateNumber) &&//ͬһ�����ƺ�
			!strcmp(rec[i].status, "in") &&
			!strcmp(rec[i + 1].status, "out"))
		{
			valid[num++] = rec[i];
			valid[num++] = rec[i + 1];//��������Եļ�¼ͬʱ����valid����
			int duration = rec[i + 1].time - rec[i].time;//�˴�ͣ����ʱ��
			if (parkTime.count(rec[i].plateNumber) == 0)
				parkTime[rec[i].plateNumber] = 0;//map��û��������ƺţ���ʱ����0,�ⲽ�ܹؼ�
			parkTime[rec[i].plateNumber] += duration;
			maxTime = max(maxTime, parkTime[rec[i].plateNumber]);//���������ͣ��ʱ�䣬���Լ��Ƚ�
		}
	}
	sort(valid, valid + num, cmpByTime);
	int now = 0, numCar = 0;
	//nowΪ�ڲ�ѯʱ��֮ǰ�ĵ�now����¼��numCarΪͣ��У���ڵĳ�������
	int query[maxn];
	for (int i = 0; i < k; i++)
	{
		scanf("%d:%d:%d", &hh, &mm, &ss);
		query[i] = timeToInt(hh, mm, ss);//ת����ǰ��ѯʱ��
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
			printf("%s ", iter->first.c_str());//������ת��ָ�����ͣ�����printf���
	}
	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
	system("pause");
	return 0;

}




