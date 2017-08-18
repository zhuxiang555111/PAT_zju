#include<cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100010;
int n, p, a[maxn];

//[i+1,n-1]��Χ�ڲ��ҵ�һ������x������λ��,����ҿ�д��
//ע������Ķ��ֲ������Ҳ�������������·���-1��������������޸ģ�ֻҪ���ҵ����ش��ڵ���Ŀ�����ֵ�λ�ü���
int binarySearch(int i, long long x)
{
	if (a[n - 1] <= x)
		return n;//���е�����������x������n
	int l = i + 1, r = n - 1, mid;
	while (l < r)//�������ұգ���ô����Ӧ��Ϊl<=r,ӦΪ���߶���ȡ��
	{
		mid = (l + r) / 2;
		if (a[mid] <= x)//����������Ҫ���޸ģ���������Ҫ���ڣ�ֻ��Ҫ���ڵ��ھͿ���
			l = mid + 1;
		else
			r = mid;
		//����Ķ��ֲ�������Ӧ�÷���mid����ʾ�ҵ�����
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
