//#include<iostream>
//#include <map>
//#include <cstdio>
//#include <cstring>
//#include<algorithm>
//
//using namespace std;
//
//struct Record
//{
//	char plateNumber[7];
//	int hh, mm, ss;
//	bool status = false; //true-in false-out
//}rec[10010];
//
//struct Query
//{
//	int hh, mm, ss;
//	int carNum = 0;
//}que[80010];
//
//map<string, int> duration;
//bool cmp(Record a, Record b)
//{
//	int s = strcmp(a.plateNumber, b.plateNumber);
//	if (s != 0)
//		return s < 0;
//	if (a.hh != b.hh)
//		return a.hh < b.hh;
//	else if (a.mm != b.mm)
//		return a.mm < b.mm;
//	else
//		return a.ss < b.ss;
//}
//
//
//
//int timeToSecond(int hh, int mm, int ss)  //������ͬһ��֮�ڣ���ʱ��ͳһת��Ϊ���ܷ���
//{
//	return hh * 3600 + mm * 60 + ss;
//}
//
//int main()
//{
//	int n, k;//��¼������ѯ��
//	scanf("%d%d", &n, &k);
//	int totalPlate = 1;
//	int plate[10010];//��ͬ�ĳ��Ʒֽ��
//	char statusTemp[3];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s %d:%d:%d %s", rec[i].plateNumber, &rec[i].hh, &rec[i].mm, &rec[i].ss,statusTemp);
//		if (strcmp(statusTemp, "in") == 0)
//			rec[i].status = true;
//		if (strcmp(statusTemp, "out") == 0)
//			rec[i].status = false;
//	}
//	sort(rec, rec + n, cmp);//��һ������
//	plate[0] = 0;//�׸����ƺű��Ϊ0
//	for (int i = 1; i < n; i++)
//	{
//		if (strcmp(rec[i].plateNumber, rec[i - 1].plateNumber) != 0)
//		{
//			plate[totalPlate++] = i;
//		}
//	}
//	for (int i = 0; i < k; i++)
//	{
//		scanf("%d:%d:%d", &que[i].hh, &que[i].mm, &que[i].ss);
//		int currentTime = timeToSecond(que[i].hh, que[i].mm, que[i].ss);
//		int j = 0;
//		while(j != totalPlate-1)
//		{//ƥ������һ������ÿһ�����ĳ�����Ϣ,���ƥ��
//			for (int x = plate[j]; x < plate[j + 1]-1; x++)//����ƥ��
//			{
//				if ((rec[x].status == true && rec[x + 1].status == false))//�������
//				{
//					rec[x].duration = timeToSecond(rec[x + 1].hh, rec[x + 1].mm, rec[x + 1].ss) - timeToSecond(rec[x].hh, rec[x].mm, rec[x].ss);
//					if ((timeToSecond(rec[x].hh, rec[x].mm, rec[x].ss) <= currentTime) && (timeToSecond(rec[x + 1].hh, rec[x + 1].mm, rec[x + 1].ss) > currentTime))
//						que[i].carNum++;
//				}
//			}
//			j++;
//		}
//		//ƥ�����һ����
//		j = totalPlate - 1;
//		for (int x = plate[j]; x < n-1; x++)
//		{
//			/*if ((rec[x].status == true && rec[x + 1].status == false) && (timeToSecond(rec[x].hh, rec[x].mm, rec[x].ss) <= currentTime) && (timeToSecond(rec[x + 1].hh, rec[x + 1].mm, rec[x + 1].ss)>currentTime))
//					que[i].carNum++;*/
//			if ((rec[x].status == true && rec[x + 1].status == false))//�������
//			{
//				rec[x].duration = timeToSecond(rec[x + 1].hh, rec[x + 1].mm, rec[x + 1].ss) - timeToSecond(rec[x].hh, rec[x].mm, rec[x].ss);
//				if ((timeToSecond(rec[x].hh, rec[x].mm, rec[x].ss) <= currentTime) && (timeToSecond(rec[x + 1].hh, rec[x + 1].mm, rec[x + 1].ss) > currentTime))
//					que[i].carNum++;
//			}
//		}
//	}
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d\n", que[i].carNum);
//	}
//	sort(rec, rec + n, cmpTime);
//	int maxTime = rec[0].duration;
//	for (int i = 0; i < n; i++)
//	{
//		if (rec[i].duration == maxTime)
//			pri
//
//	}
//	printf("%d:%d:%d ", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
//	system("pause");
//}