#include <iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Student
{
	int id; //根据数组序号排列
	int Ge;
	int Gi;
	int finalGrade;
	int rank;
	vector<int> choice;
}stu[40010];


struct School
{
	int quota;//总额度
	int stuNum = 0;//当前已经招收的学生数
	int id[40010];//招收的学生编号，以便输出时使用
	int lastAdmit = -1;//最后一个招收的学生编号,标记未-1表示不存在
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
	int n, m, k;//申请数，院校数，志愿数
	//vector<int> quota;//名额
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
	for (int i = 0; i < n; i++)//处理每一个考生的志愿
	{
		for (int j = 0; j < k; j++)//处理每一个考生所填的每一所院校
		{
			int choiceTemp = stu[i].choice[j];//选择考生的第j个志愿的学校编号
			int stuNumTemp = sch[choiceTemp].stuNum;//选择当前学校编号的已招人数
			int lastTemp = sch[choiceTemp].lastAdmit;//选择当前学校编号的最后一个招生的学生编号

			//处理录取
			if (stuNumTemp < sch[choiceTemp].quota || (lastTemp != -1 && stu[i].rank ==
				stu[lastTemp].rank))//前者表示名额没满，则肯定录取,后者表示虽然名额满了，但是一定要满足与该校最后一位录取的考生排名一致，则破格录取
			{
				sch[choiceTemp].id[stuNumTemp] = stu[i].id;//录取该考生，排在院校录取学生id数组的最后一个
				sch[choiceTemp].stuNum++;//该校已录取人数+1
				sch[choiceTemp].lastAdmit = stu[i].id;//更新该校录取的最后一个考生id
				break;//一旦录取，必须跳出循环，防止后续循环录取
			}
		}
	}
	for (int i = 0; i < m; i++)//对于m所院校
	{
		if (sch[i].stuNum > 0)
		{
			sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpID);
			for (int j = 0; j < sch[i].stuNum; j++)//对于每一个学生
			{
				printf("%d", sch[i].id[j]);
				if (j < sch[i].stuNum - 1)//防止末尾多余的空格
					printf(" ");
			}
		}
		printf("\n");
	}

	
	system("pause");
}
