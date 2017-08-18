#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 10010;
int Age[maxn] = { 0 };//ĳ����ε�����
struct People
{
	char name[10];
	int age;
	int netWorth;//ʹ��long�ᵼ���ύ����
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
	sort(peo, peo + n, cmpNet);//���ʲ�ֵ����
	int validNum = 0;//�浽valid�����е�����
	for (int i = 0; i < n; i++)
	{
		if (Age[peo[i].age] < 100)//�����������С��100
		{
			Age[peo[i].age]++;
			valid[validNum++] = peo[i];//ģ�⶯̬���� ^-^ ������˼����µ�������
			//��������ÿ������ĲƸ�ֵǰ100�˼������飬��������Ǹ��ݲƸ�ֵ�Ӹߵ�������
			//��n�Ƚϴ�ʱ�ܴ����С��ѯ����
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