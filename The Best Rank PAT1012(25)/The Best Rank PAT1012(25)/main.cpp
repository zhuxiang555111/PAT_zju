#include<iostream>
#include <cstdio>
#include <algorithm>
#include<vector>
using namespace std;
struct Student
{
	int id;
	short c, m, e, a;
	int c_rank, m_rank, e_rank, a_rank;
}stu[100000];


bool cmp1(Student a, Student b)//sort c
{
	return a.c > b.c;
}
bool cmp2(Student a, Student b)//sort m
{
	return a.m > b.m;
}
bool cmp3(Student a, Student b)//sort e
{
	return a.e > b.e;
}
bool cmp4(Student a, Student b)
{
	return a.a > b.a;
}

void sortBestRank(Student a)
{


		if (a.a_rank <= a.c_rank && a.a_rank <= a.m_rank && a.a_rank <= a.e_rank)
			cout << a.a_rank << " " << "A";
		else if (a.c_rank <= a.a_rank && a.c_rank <= a.m_rank && a.c_rank <= a.e_rank)
			cout << a.c_rank << " " << "C";
		else if (a.m_rank <= a.a_rank && a.m_rank <= a.c_rank && a.m_rank <= a.e_rank)
			cout << a.m_rank << " " << "M";
		else if (a.e_rank <= a.a_rank&& a.e_rank <= a.c_rank&& a.c_rank <= a.m_rank)
			cout << a.e_rank << " " << "E";

}

int main()
{
	int query[100000];
	int numStu, numCheck;//N,M
	int avg;//average score
	scanf("%d %d", &numStu, &numCheck);
	for (int i = 0; i < numStu; i++)
	{
		scanf("%d %d %d %d", &stu[i].id, &stu[i].c, &stu[i].m, &stu[i].e);
		stu[i].a = (stu[i].c + stu[i].m + stu[i].e) / 3;
	}
	for (int i = 0; i < numCheck; i++)
	{
		scanf("%d",&query[i]);
	}
	sort(stu, stu + numStu, cmp1);//sort c
	stu[0].c_rank = 1;
	for (int i = 1; i < numStu; i++) //防止数组越界
	{
		if (stu[i].c == stu[i - 1].c)
		{
			stu[i].c_rank = stu[i - 1].c_rank;
		}
		else
		{
			stu[i].c_rank = i + 1;
		}
	}
	sort(stu, stu + numStu, cmp2);//sort math
	stu[0].m_rank = 1;
	for (int i = 1; i < numStu; i++) //防止数组越界
	{
		if (stu[i].m == stu[i - 1].m)
		{
			stu[i].m_rank = stu[i - 1].m_rank;
		}
		else
		{
			stu[i].m_rank = i + 1;
		}
	}
	sort(stu, stu + numStu, cmp3);//sort english
	stu[0].e_rank = 1;
	for (int i = 1; i < numStu; i++) //防止数组越界
	{
		if (stu[i].e == stu[i - 1].e)
		{
			stu[i].e_rank = stu[i - 1].e_rank;
		}
		else
		{
			stu[i].e_rank = i + 1;
		}
	}
	sort(stu, stu + numStu, cmp4);//sort average
	stu[0].a_rank = 1;
	for (int i = 1; i < numStu; i++) //防止数组越界
	{
		if (stu[i].a == stu[i - 1].a)
		{
			stu[i].a_rank = stu[i - 1].a_rank;
		}
		else
		{
			stu[i].a_rank = i + 1;
		}
	}
	//==============//
	for (int i = 0; i < numCheck; i++)
	{
		int j;
		for (j = 0; j < numStu; j++)
		{
			if (query[i] == stu[j].id) //checkStudent is in the total
			{
				sortBestRank(stu[j]);
				cout << endl;
				break;
			}
		}
		if(j >= numStu)
			cout << "N/A" << endl;
	}
	system("pause");
}
