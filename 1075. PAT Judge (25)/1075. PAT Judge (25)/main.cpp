#include<cstdio>
#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

//struct submit
//{
//	int user_id, problem_id, partial_score_obtained;
//}sub[100000];

struct User
{
	int id;
	//int rank = 0;
	int perScore[6] = { -1,-1,-1,-1,-1,-1 };//初始化每题的得分,题目要么得分，要么不得分,
											//此处若数据量大可用memset()函数
	bool flag = false;//是否有未通过编译的标志
	int score_total = 0;//总分
	int solve = 0;//完美解题数
} usr[10000];
vector<int> p;//每题的总分

bool cmp(User a, User b)
{
	if (a.score_total != b.score_total)
		return a.score_total > b.score_total;
	if (a.solve != b.solve)
		return a.solve > b.solve;
	else
		return a.id < b.id;
}

//bool cmpId(submit a, submit b)
//{
//	return a.user_id < b.user_id;
//}

int main()
{
	int n, k, m;//总用户，总题数，总提交数
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < k; i++)
	{
		int pTemp;
		scanf("%d", &pTemp);
		p.push_back(pTemp);
	}
	//思想:边输入边处理数据
	int user_id, problem_id, partial_score_obtained;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &user_id, &problem_id, &partial_score_obtained);
		usr[user_id].id = user_id;
		if (partial_score_obtained != -1)//没有编译不通过的
		{
			usr[user_id].flag = true;
		}
		if (partial_score_obtained == -1 && usr[user_id].perScore[problem_id-1] == -1)
			//第一次编译未通过，前者表示该次没通过，后者表示之前没碰到过，因此是第一次未通过
		{
			usr[user_id].perScore[problem_id-1] = 0;//记为未得分，便于计算该题最终成绩和总分
		}
		if (partial_score_obtained == p[problem_id-1] && usr[user_id].perScore[problem_id-1] < p[problem_id-1])
			//表示第一次获得满分，前者表示该次得到满分，后者表示之前从来没有满分过
			//只用第一次表示防止后续再增加完美解题数
		{
			usr[user_id].solve++;//完美解除的题数+1
		}
		if (partial_score_obtained > usr[user_id].perScore[problem_id-1])
			//表示该次该题分数大于之前该题的得分
		{
			usr[user_id].perScore[problem_id-1] = partial_score_obtained;
		}
	}

	for (int i = 0; i < n+1; i++)//对于每一个用户，注意由于范围不超过n的数字
								//但是必须用n+1作为边界，否则会漏掉最后一个用户
	{ 
		for (int j = 0; j < k; j++)//计算所有题的总分
		{
			if (usr[i].perScore[j] != -1)
				usr[i].score_total += usr[i].perScore[j];
		}
	}

	sort(usr+1, usr + m+1, cmp);//第一个不参与排名
	/*usr[0].rank = 1;
	for (int i = 1; i < n; i++)
	{
		if (usr[i].score_total == usr[i - 1].score_total)
			usr[i].rank = usr[i-1].rank;
		else
			usr[i].rank = i+1;
	}*/
	/*for (int i = 0; i < n; i++)
	{
		if(usr[i].score_total > 0)
		{
			printf("%d %05d %d", usr[i].rank, usr[i].id,usr[i].score_total);
			for (int j = 0; j < k; j++)
			{
				if (usr[i].perScore[j] == -1)
					printf(" -");
				else
					printf(" %d", usr[i].perScore[j]);
			}
			cout << endl;
		}
	}*/
	int r = 1;
	for (int i = 1; i <= n && usr[i].flag == true; i++)
	{
		if (i > 1 && usr[i].score_total != usr[i - 1].score_total)
			r = i;
		printf("%d %05d %d", r, usr[i].id, usr[i].score_total);
		for (int j = 1; j <= k; j++)
		{
			if (usr[i].perScore[j] == -1)
			{
				printf(" -");
			}
			else
				printf(" %d", usr[i].perScore[j]);
		}
		printf("\n");
	}
	
	system("pause");
}