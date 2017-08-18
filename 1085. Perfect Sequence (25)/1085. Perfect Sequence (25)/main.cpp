//#include<iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//vector<long> sequence;
//bool cmp(long a, long b)
//{
//	return a < b;
//}
//
//int binarySearch(long first, long last, long x)//×ó±ÕÓÒ¿ª
//{
//	int mid = 0;
//	while (first < last)
//	{
//		mid = (first + last) / 2;
//		if (x < sequence[mid])
//		{
//			last = mid;
//		}
//		else if (x > sequence[mid])
//		{
//			first = mid + 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//int main()
//{
//	int n, ans = 1;
//	long p;
//	
//	scanf("%d %ld", &n,&p);
//	for (int i = 0; i < n; i++)
//	{
//		long temp;
//		scanf("%ld", &temp);
//		sequence.push_back(temp);
//	}
//	sort(sequence.begin(),sequence.end(), cmp);
//	for (int i = 0; i < n; i++)
//	{
//		int temp = binarySearch(i, n , sequence[i] * p);
//		if (temp == -1)
//			break;
//		ans = max(ans, temp - i+1);
//	}
//	cout << ans;
//	system("pause");
//}