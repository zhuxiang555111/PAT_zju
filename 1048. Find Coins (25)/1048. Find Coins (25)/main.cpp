	//#include <iostream>

	//using namespace std;


	//int coins[10010] = { 0 };
	//int hashTable[10010];
	//int main()
	//{
	//	int n, m;
	//	int maxCoin;
	//	scanf("%d%d", &n, &m);
	//	for (int i = 0; i < n; i++)
	//	{
	//		scanf("%d", &coins[i]);
	//		hashTable[coins[i]]++;
	//	}
	//	maxCoin = coins[0];
	//	for (int i = 0; i < n; i++)
	//	{
	//		if (coins[i] > maxCoin && coins[i] != m)
	//			maxCoin = coins[i];
	//	}
	//	int remain = m - maxCoin;
	//	if (hashTable[remain] > 0)
	//		cout << remain << " " << maxCoin;
	//	else
	//		cout << "No solution";
	//	system("pause");
	//}