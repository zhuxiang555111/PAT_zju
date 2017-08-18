#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 10010;
int Age[maxn] = { 0 };//某年龄段的人数
struct People
{
	char name[10];
	int age;
	int netWorth;//使用long会导致提交错误
}peo[maxn],valid[maxn];

bool cmpNet(People a, People b)
{
	if (a.netWorth != b.netWorth)
		return a.netWorth > b.netWorth;
	else if (a.age != b.age)
		return a.age < b.age;
	return strcmp(a.name, b.name) < 0;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d%d", peo[i].name, &peo[i].age, &peo[i].netWorth);
	}
	sort(peo, peo + n, cmpNet);//按资产值排序
	int validNum = 0;//存到valid数组中的人数
	for (int i = 0; i < n; i++)
	{
		if (Age[peo[i].age] < 100)//该年龄的人数小于100
		{
			Age[peo[i].age]++;
			valid[validNum++] = peo[i];//模拟动态数组 ^-^ 将这个人加入新的数组中
			//将整理后的每个年龄的财富值前100人加入数组，因此数组是根据财富值从高到低排序
			//在n比较大时能大幅缩小查询次数
		}
	}
	int maxPeople, Amin, Amax;
	for (int i = 0; i < k; i++)
	{	
		scanf("%d%d%d", &maxPeople, &Amin, &Amax);
		printf("Case #%d:\n", i + 1);
		int printNum = 0;
		for (int j = 0; j < validNum && printNum < maxPeople; j++)
		{
			if (valid[j].age >= Amin && valid[j].age <= Amax)
			{
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].netWorth);
				printNum++;
			}
		}
		if (printNum == 0)
		{
			printf("None\n");
		}
	}
	system("pause"); 
	return 0;
}