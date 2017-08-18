//#include <iostream>
//#include<algorithm>
//#include <vector>
//
//using namespace std;
//
//
//struct Number
//{
//	int number;
//	bool transfer = false;
//};
//
//bool cmp(Number a, Number b)
//{
//	return a.number < b.number;
//}
//
//void myswap(Number& a, Number& b)
//{
//	Number temp = a;
//	a.number = b.number;
//	b.number = temp.number;
//	a.transfer = true;
//	b.transfer = true;
//}
//
//int main()
//{
//	int n;
//	int swapTime = 0;
//	vector<Number> permutation;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		Number numberTemp;
//		scanf("%d", &numberTemp.number);
//		numberTemp.transfer = false;
//		permutation.push_back(numberTemp);
//	}
//	while(true)
//	{
//	loop:
//		if (permutation[0].number != 0)
//		{
//			int x,y;
//			for (x = 0; x < n; x++)
//			{
//				if (permutation[x].number == 0)
//					break;
//			}
//			for (y = 0; y < n; y++)
//			{
//				if (permutation[y].number == x)
//					break;
//			}
//			
//			myswap(permutation[x], permutation[y]);
//			swapTime++;
//		
//		}
//		else
//		{
//			int x;
//			for (x = 1; x < n; x++)
//			{
//				if (!permutation[x].transfer)
//				{
//					myswap(permutation[0], permutation[x]);
//					swapTime++;
//					break;
//				}
//			}
//			
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (permutation[i].number != i)
//				goto loop;
//		}
//		break;
//	}
//	cout << swapTime;
//	system("pause");
//	return 0;
//}