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
//int timeToSecond(int hh, int mm, int ss)  //由于在同一天之内，将时间统一转换为秒会很方便
//{
//	return hh * 3600 + mm * 60 + ss;
//}
//
//int main()
//{
//	int n, k;//记录数，查询数
//	scanf("%d%d", &n, &k);
//	int totalPlate = 1;
//	int plate[10010];//不同的车牌分解号
//	char statusTemp[3];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s %d:%d:%d %s", rec[i].plateNumber, &rec[i].hh, &rec[i].mm, &rec[i].ss,statusTemp);
//		if (strcmp(statusTemp, "in") == 0)
//			rec[i].status = true;
//		if (strcmp(statusTemp, "out") == 0)
//			rec[i].status = false;
//	}
//	sort(rec, rec + n, cmp);//第一次排序
//	plate[0] = 0;//首个车牌号编号为0
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
//		{//匹配非最后一辆车的每一辆车的出入信息,组间匹配
//			for (int x = plate[j]; x < plate[j + 1]-1; x++)//组内匹配
//			{
//				if ((rec[x].status == true && rec[x + 1].status == false))//可以配对
//				{
//					rec[x].duration = timeToSecond(rec[x + 1].hh, rec[x + 1].mm, rec[x + 1].ss) - timeToSecond(rec[x].hh, rec[x].mm, rec[x].ss);
//					if ((timeToSecond(rec[x].hh, rec[x].mm, rec[x].ss) <= currentTime) && (timeToSecond(rec[x + 1].hh, rec[x + 1].mm, rec[x + 1].ss) > currentTime))
//						que[i].carNum++;
//				}
//			}
//			j++;
//		}
//		//匹配最后一辆车
//		j = totalPlate - 1;
//		for (int x = plate[j]; x < n-1; x++)
//		{
//			/*if ((rec[x].status == true && rec[x + 1].status == false) && (timeToSecond(rec[x].hh, rec[x].mm, rec[x].ss) <= currentTime) && (timeToSecond(rec[x + 1].hh, rec[x + 1].mm, rec[x + 1].ss)>currentTime))
//					que[i].carNum++;*/
//			if ((rec[x].status == true && rec[x + 1].status == false))//可以配对
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