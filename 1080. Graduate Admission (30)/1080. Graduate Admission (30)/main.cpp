#include <iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Student
{
	int id; //���������������
	int Ge;
	int Gi;
	int finalGrade;
	int rank;
	vector<int> choice;
}stu[40010];


struct School
{
	int quota;//�ܶ��
	int stuNum = 0;//��ǰ�Ѿ����յ�ѧ����
	int id[40010];//���յ�ѧ����ţ��Ա����ʱʹ��
	int lastAdmit = -1;//���һ�����յ�ѧ�����,���δ-1��ʾ������
}sch[110];



bool cmpStu(Student a, Student b)
{
	if (a.finalGrade != b.finalGrade)
		return a.finalGrade > b.finalGrade;
	else
		return a.Ge > b.Ge;
}

bool cmpID(int a, int b)
{
	return a < b;
}

int main()
{
	int n, m, k;//��������ԺУ����־Ը��
	//vector<int> quota;//����
	{
		//int quotaTemp;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
		scanf("%d", &sch[i].quota);
		//quota.push_back(quotaTemp);
	}
	

	for (int i = 0; i < n; i++)
	{
		stu[i].id = i;
		scanf("%d%d%", &stu[i].Ge, &stu[i].Gi);
		stu[i].finalGrade = (stu[i].Gi + stu[i].Ge) / 2;
		for (int j = 0; j < k; j++)
		{
			int choiceTemp;
			scanf("%d", &choiceTemp);
			stu[i].choice.push_back(choiceTemp);
		}
	}
	sort(stu, stu + n, cmpStu);
	stu[0].rank = 1;
	for (int i = 1; i < n; i++)
	{
		if (stu[i].finalGrade == stu[i - 1].finalGrade && stu[i].Ge == stu[i - 1].Ge)
			stu[i].rank = stu[i - 1].rank;
		else
			stu[i].rank = i + 1;
	}
	for (int i = 0; i < n; i++)//����ÿһ��������־Ը
	{
		for (int j = 0; j < k; j++)//����ÿһ�����������ÿһ��ԺУ
		{
			int choiceTemp = stu[i].choice[j];//ѡ�����ĵ�j��־Ը��ѧУ���
			int stuNumTemp = sch[choiceTemp].stuNum;//ѡ��ǰѧУ��ŵ���������
			int lastTemp = sch[choiceTemp].lastAdmit;//ѡ��ǰѧУ��ŵ����һ��������ѧ�����

			//����¼ȡ
			if (stuNumTemp < sch[choiceTemp].quota || (lastTemp != -1 && stu[i].rank ==
				stu[lastTemp].rank))//ǰ�߱�ʾ����û������϶�¼ȡ,���߱�ʾ��Ȼ�������ˣ�����һ��Ҫ�������У���һλ¼ȡ�Ŀ�������һ�£����Ƹ�¼ȡ
			{
				sch[choiceTemp].id[stuNumTemp] = stu[i].id;//¼ȡ�ÿ���������ԺУ¼ȡѧ��id��������һ��
				sch[choiceTemp].stuNum++;//��У��¼ȡ����+1
				sch[choiceTemp].lastAdmit = stu[i].id;//���¸�У¼ȡ�����һ������id
				break;//һ��¼ȡ����������ѭ������ֹ����ѭ��¼ȡ
			}
		}
	}
	for (int i = 0; i < m; i++)//����m��ԺУ
	{
		if (sch[i].stuNum > 0)
		{
			sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpID);
			for (int j = 0; j < sch[i].stuNum; j++)//����ÿһ��ѧ��
			{
				printf("%d", sch[i].id[j]);
				if (j < sch[i].stuNum - 1)//��ֹĩβ����Ŀո�
					printf(" ");
			}
		}
		printf("\n");
	}

	
	system("pause");
}
