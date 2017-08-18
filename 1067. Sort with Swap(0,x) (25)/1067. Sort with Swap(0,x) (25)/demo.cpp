#include <iostream>
#include<algorithm>

using namespace std;
const int maxn = 100010;
int pos[maxn];//各数字当前所处位置的数组下标

int main()
{
	int n, ans=0;
	scanf("%d", &n);
	int left = n - 1, num;//left存放除0以外不在本位上的数的个数,num为要输入的数
	for (int i = 0; i < n; i++)//给一个位置，存一个数
	{
		scanf("%d", &num);
		pos[num] = i; //num数字所处的位置为i
		if (num == i&&num != 0)//num在自己的位置上且不是0
			left--;
	}
	int k = 1;//存放除0外不在自己位置上最小的数,假设为1
	while (left > 0)
	{
		if (pos[0] == 0)//如果0在自己的位置上
		{
			while (k < n)
			{
				if (pos[k] != k)//找到一个不在自己位置上的数
				{
					swap(pos[0], pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while (pos[0] != 0)//0不在自己的位置上
		{
			swap(pos[0], pos[pos[0]]);
			ans++;
			left--;
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}
