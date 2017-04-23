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
		m, //number of non-leaf nodes   非叶节点
		k; //非叶的儿子个数
	int id[100][100];
	//100*100 vector二维数组
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
		id[temp_id][0] = 1;//表示该节点是非叶节点
		for (int j = 0; j < childNum; j++)
		{
			int temp_child;
			cin >> temp_child;
			//child.push_back(temp_child);
			id[temp_id][temp_child] = 1;//表示该节点是儿子
		}
	}

	
	system("pause");
}