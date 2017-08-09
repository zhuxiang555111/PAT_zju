//Programming Ability Test(PAT) is organized by the College of Computer Science and Technology of Zhejiang University.Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test.Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.
//
//Input Specification :
//
//Each input file contains one test case.For each case, the first line contains a positive number N(<= 100), the number of test locations.Then N ranklists follow, each starts with a line containing a positive integer K(<= 300), the number of testees, and then K lines containing the registration number(a 13 - digit number) and the total score of each testee.All the numbers in a line are separated by a space.
//
//Output Specification :
//
//For each test case, first print in one line the total number of testees.Then print the final ranklist in the following format :
//
//registration_number final_rank location_number local_rank
//
//The locations are numbered from 1 to N.The output must be sorted in nondecreasing order of the final ranks.The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.
//
//Sample Input :
//2
//5
//1234567890001 95
//1234567890005 100
//1234567890003 95
//1234567890002 77
//1234567890004 85
//4
//1234567890013 65
//1234567890011 25
//1234567890014 100
//1234567890012 85
//Sample Output :
//9
//1234567890005 1 1 1
//1234567890014 1 2 1
//1234567890001 3 1 2
//1234567890003 3 1 2
//1234567890004 5 1 4
//1234567890012 5 2 2
//1234567890002 7 1 5
//1234567890013 8 2 3
//1234567890011 9 2 4

#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;

struct Student 
{
	char id[15];//׼��֤��
	int score;//����
	int location_number;//������
	int local_rank;//����������
}stu[30010];


bool cmp(Student a, Student b)
{
	if (a.score != b.score)//��ͬ�֣���������������
		return a.score > b.score;
	else//ͬ�ְ�׼��֤����
		return strcmp(a.id, b.id) < 0; //a<b =>true;a>b =>false
}
int main()
{
	int n, k, num = 0;//nΪ�ܿ�����,kΪ������,numΪ�ܿ�����
	scanf("%d",&n);//nΪ�ܿ�����
	for (int i = 0; i < n; i++)//ÿ����һ�־ͽ�������
	{
		scanf("%d", &k);
		for (int j = 0; j < k; j++)//����ÿ��������п�����Ϣ
		{
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].location_number = i;
			num++;
		}
		sort(stu + num - k, stu + num, cmp);
		stu[num - k].local_rank = 1;//�ÿ����ĵ�һ���Ϊ1
		for (int x = num - k + 1; x < num; x++)//�Ըÿ���ʣ�µ��˽��б��
		{
			if (stu[x].score == stu[x - 1].score)//�����ǰһλ����ͬ��
				stu[x].local_rank = stu[x - 1].local_rank;//local_rankҲ��ͬ
			else//��ͬ��
			{
				stu[x].local_rank = x + 1 - (num - k);
			}
		}
	}
	cout << num << endl;
	sort(stu, stu + num, cmp);//��ȫ������Ӧ������
	int totalRank = 1;
	for (int i = 0; i < num; i++)//�������ǲ��к���������1��������ͬ����
		//�źŵ�������ʵ��i��˳��
	{
		if (i > 0 && stu[i].score != stu[i - 1].score)
			totalRank = i + 1;
		cout << stu[i].id <<" "<< totalRank <<" "<< stu[i].location_number+1
			<<" "<< stu[i].local_rank << endl;
	}
	system("pause");


}
