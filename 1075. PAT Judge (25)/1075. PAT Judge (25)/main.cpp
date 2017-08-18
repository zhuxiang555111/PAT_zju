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
	int perScore[6] = { -1,-1,-1,-1,-1,-1 };//��ʼ��ÿ��ĵ÷�,��ĿҪô�÷֣�Ҫô���÷�,
											//�˴��������������memset()����
	bool flag = false;//�Ƿ���δͨ������ı�־
	int score_total = 0;//�ܷ�
	int solve = 0;//����������
} usr[10000];
vector<int> p;//ÿ����ܷ�

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
	int n, k, m;//���û��������������ύ��
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < k; i++)
	{
		int pTemp;
		scanf("%d", &pTemp);
		p.push_back(pTemp);
	}
	//˼��:������ߴ�������
	int user_id, problem_id, partial_score_obtained;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &user_id, &problem_id, &partial_score_obtained);
		usr[user_id].id = user_id;
		if (partial_score_obtained != -1)//û�б��벻ͨ����
		{
			usr[user_id].flag = true;
		}
		if (partial_score_obtained == -1 && usr[user_id].perScore[problem_id-1] == -1)
			//��һ�α���δͨ����ǰ�߱�ʾ�ô�ûͨ�������߱�ʾ֮ǰû������������ǵ�һ��δͨ��
		{
			usr[user_id].perScore[problem_id-1] = 0;//��Ϊδ�÷֣����ڼ���������ճɼ����ܷ�
		}
		if (partial_score_obtained == p[problem_id-1] && usr[user_id].perScore[problem_id-1] < p[problem_id-1])
			//��ʾ��һ�λ�����֣�ǰ�߱�ʾ�ôεõ����֣����߱�ʾ֮ǰ����û�����ֹ�
			//ֻ�õ�һ�α�ʾ��ֹ��������������������
		{
			usr[user_id].solve++;//�������������+1
		}
		if (partial_score_obtained > usr[user_id].perScore[problem_id-1])
			//��ʾ�ôθ����������֮ǰ����ĵ÷�
		{
			usr[user_id].perScore[problem_id-1] = partial_score_obtained;
		}
	}

	for (int i = 0; i < n+1; i++)//����ÿһ���û���ע�����ڷ�Χ������n������
								//���Ǳ�����n+1��Ϊ�߽磬�����©�����һ���û�
	{ 
		for (int j = 0; j < k; j++)//������������ܷ�
		{
			if (usr[i].perScore[j] != -1)
				usr[i].score_total += usr[i].perScore[j];
		}
	}

	sort(usr+1, usr + m+1, cmp);//��һ������������
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