#include <cstdio>
#include <iostream>
using namespace std;

int hashTable[1005];
int main()
{
	int n, m, a;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		++hashTable[a];
	}
	for (int i = 0; i < 1005; i++)
	{
		if (hashTable[i] && hashTable[m - i])
		{
			if (i == m - i&&hashTable[i] <= 1)
				continue;
			printf("%d %d\n", i, m - i);
			return 0;
		}
	}
	cout << "No solution";
	return 0;
}