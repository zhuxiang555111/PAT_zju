#include <iostream>
#include <vector>

using namespace std;

int hashTable[10010] = { 0 };
vector<int> input;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		input.push_back(temp);
		hashTable[input[i]]++;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		if (hashTable[input[i]] == 1)
		{
			cout << input[i];
			break;
		}
	}
	if (i == n )
	{
		cout << "None";
	}
	system("pause");
}