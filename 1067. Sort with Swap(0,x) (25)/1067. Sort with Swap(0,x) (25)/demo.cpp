#include <iostream>
#include<algorithm>

using namespace std;
const int maxn = 100010;
int pos[maxn];//�����ֵ�ǰ����λ�õ������±�

int main()
{
	int n, ans=0;
	scanf("%d", &n);
	int left = n - 1, num;//left��ų�0���ⲻ�ڱ�λ�ϵ����ĸ���,numΪҪ�������
	for (int i = 0; i < n; i++)//��һ��λ�ã���һ����
	{
		scanf("%d", &num);
		pos[num] = i; //num����������λ��Ϊi
		if (num == i&&num != 0)//num���Լ���λ�����Ҳ���0
			left--;
	}
	int k = 1;//��ų�0�ⲻ���Լ�λ������С����,����Ϊ1
	while (left > 0)
	{
		if (pos[0] == 0)//���0���Լ���λ����
		{
			while (k < n)
			{
				if (pos[k] != k)//�ҵ�һ�������Լ�λ���ϵ���
				{
					swap(pos[0], pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while (pos[0] != 0)//0�����Լ���λ����
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
