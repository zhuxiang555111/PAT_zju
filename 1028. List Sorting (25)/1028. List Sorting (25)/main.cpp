#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>

using namespace std;

struct Student 
{
	int id;
	char name[10];
	int grade;
}stu[100000];

bool cmpID(Student a, Student b)
{
	return a.id <= b.id;
}

bool cmpName(Student a, Student b)
{
	int s = strcmp(a.name, b.name);
	if (s != 0)
	{
		return s < 0;
	}
	else
		return a.id < b.id;
}

bool cmpGrade(Student a, Student b)
{
	if (a.grade != b.grade)
	{
		return a.grade <= b.grade;
	}
	else
		return a.id < b.id;
	
}

int main()
{
	int N, C;
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %s %d", &stu[i].id, &stu[i].name, &stu[i].grade);
	}
	if (C == 1)
	{
		sort(stu, stu + N, cmpID);
	}
	else if (C == 2)
	{
		sort(stu, stu + N, cmpName);
	}
	else if (C == 3)
	{
		sort(stu, stu + N, cmpGrade);
	}
	for (int i = 0; i < N; i++)
	{
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	system("pause");
	return 0;
}