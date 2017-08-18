#include<cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100010;
int n, p, a[maxn];

//[i+1,n-1]范围内查找第一个大于x的数的位置,左闭右开写法
//注：常规的二分查找在找不到该数的情况下返回-1，本题必须做出修改，只要求找到返回大于等于目标数字的位置即可
int binarySearch(int i, long long x)
{
	if (a[n - 1] <= x)
		return n;//所有的数都不大于x，返回n
	int l = i + 1, r = n - 1, mid;
	while (l < r)//如果左闭右闭，那么这里应该为l<=r,应为两边都能取到
	{
		mid = (l + r) / 2;
		if (a[mid] <= x)//这里是最重要的修改，表明不需要等于，只需要大于等于就可以
			l = mid + 1;
		else
			r = mid;
		//常规的二分查找这里应该返回mid，表示找到该数
	}
	return l;
}

int main()
{
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		int j = binarySearch(i, (long long)a[i] * p);
		ans = max(ans, j - i);
	}
	cout << ans << endl;
	system("pause");
}
