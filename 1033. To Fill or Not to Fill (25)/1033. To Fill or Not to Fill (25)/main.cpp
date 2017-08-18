#include <iostream>
#include<algorithm>
using namespace std;

const int INF = 1000000000;

struct Station 
{
	double price;
	double distance;
}sta[510];

bool cmpDistance(Station a, Station b)
{
	if (a.distance != b.distance)
		return a.distance < b.distance;
	else
		return a.price < b.price;
}

bool cmpPrice(Station a, Station b)
{
	return a.price < b.price;
}

int main()
{
	double c, d, davg;
	int n;
	scanf("%lf%lf%lf%d", &c, &d, &davg, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf", &sta[i].price, &sta[i].distance);
	}
	sta[n].distance = d;//�յ㿴������Ϊd
	sta[n].price = 0;//�յ㿴���ͼ�Ϊ0
	sort(sta, sta + n, cmpDistance);
	if (sta[0].distance > 0)
		cout << "The maximum travel distance = 0.00\n";
	else
	{
		int now = 0;//��ǰ�����ļ���վ�ı��
		double totalPrice = 0, nowTank = 0, maxDistance = c*davg;
		//�ۼ��ܼۣ���ǰ�����������������
		while (now < n)//ÿ��ѭ��ѡ����һ��Ҫ����ļ���վ
		{
			int k = -1;//����ͼ۵ļ���վ
			double priceMin = INF;//��ʼ����ͼ۸�

			//���������ͼ���͵�,Ҳ����˵�����ܴ治�����ͼ۱ȱ�վ�ͼ۵͵ģ�����ȥ�ң�����ҵ��ȱ�վ�͵ģ�ֱ��ȥ���Ǹ�վ�㣬������ѭ��������Ҳ������Ǿ��ҵ��ͼ���ͣ��ȱ�վ�ͼ۸ߣ����Ǹ�
			for (int i = now + 1; i <= n&&sta[i].distance - sta[now].distance <= maxDistance; i++)
				//��������̷�Χ�ڵ�
			{
				if (sta[i].price < priceMin)//�ҵ��ȵ�ǰ�ͼ۵͵�
				{
					priceMin = sta[i].price;//��������ͼ�
					k = i;
					if (priceMin < sta[now].price)//�ҵ��ȱ�վ���͵ģ�ֱ������ѭ��
						break;
				}
			}


			if(k == -1)//����״̬���޷��ҵ���һ���ܹ�����ļ���վ��������ļ���վ��������������Ҫ����ֱ������ѭ��
				break;


			//���濪ʼΪ�ҵ��ļ���վk,����ת�ƻ���
			double need = (sta[k].distance - sta[now].distance) / davg;
			//needΪת����Ҫ�ӵ�����


			if(priceMin < sta[now].price)//�����һ����������ͼ۱ȱ�վ�ͼۻ��͵ģ���ֻ��Ҫ���ܵ����Ǹ�����վ������
			{
				if (nowTank < need)//��ǰ��������������
				{
					totalPrice += (need - nowTank) *(sta[now].price);//�ڱ�վ��Ҫ�ӵ��͵ķ���
					nowTank = 0;//�������վk������Ϊ��
				}
				else//��ǰ���������ڵ�����һ������վ��Ҫ������
				{
					nowTank -= need;//������ͣ�ֱ�ӵ�����Ҽ�ȥ���ĵ�����
				}
			}
			else//����ڶ��������������ļ���վ��ͼ۶��ȱ�վ��,�����Ҫ�ڱ�վֱ�Ӽ���
			{
				totalPrice += (c - nowTank)*sta[now].price;//����
				nowTank = c - need;
			}
			now = k;//����վ�㣬������һ��ѭ��
		}


		if (now == n)//�ܵ���
		{
			printf("%.2f\n", totalPrice);
		}
		else
		{
			printf("The maximum travel distance = %.2f\n", sta[now].distance + maxDistance);
		}
	}
	system("pause");
	return 0;
}