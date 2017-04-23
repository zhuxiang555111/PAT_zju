#pragma once
#include <iostream>
#include <vector>
#include<stack>

using namespace std;

stack<int> sta; //empty stack

void dfs(int array[][100])
{
	int i, j;
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (array[i][j] == 1)
			{
				sta.push(i);

			}
		}
	}
}

int main()
{
	int n, //number of nodes
		m, //number of non-leaf nodes   ��Ҷ�ڵ�
		k; //��Ҷ�Ķ��Ӹ���
	int id[100][100];
	//100*100 vector��ά����
	for (int a = 0; a < 100; a++)  //initial
	{
		for (int b = 0; b < 100; b++)
		{
			id[a][b] = 0;
		}
	}
	scanf_s("%d %d", &m, &m);
	for (int i = 0; i < m; i++)
	{
		int temp_id;
		int childNum;
		scanf_s("%d %d", &temp_id, &childNum);
		id[temp_id][0] = 1;//��ʾ�ýڵ��Ƿ�Ҷ�ڵ�
		for (int j = 0; j < childNum; j++)
		{
			int temp_child;
			cin >> temp_child;
			//child.push_back(temp_child);
			id[temp_id][temp_child] = 1;//��ʾ�ýڵ��Ƕ���
		}
	}

	
	system("pause");
}