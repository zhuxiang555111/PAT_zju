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
	sta[n].distance = d;//终点看作距离为d
	sta[n].price = 0;//终点看作油价为0
	sort(sta, sta + n, cmpDistance);
	if (sta[0].distance > 0)
		cout << "The maximum travel distance = 0.00\n";
	else
	{	int now = 0;
		while(now<n)
		{
			double maxDistance = c*davg, minPrice = INF,nowTank = 0,totalPrice  = 0;
			int k;//需要到达的下一个加油站编号
			for (int i = now + 1; (sta[i].distance - sta[now].distance) < maxDistance&&i <= n; i++)
			{
				if (sta[i].price < minPrice)
				{
					minPrice = sta[i].price;
					k = i;
					if (sta[i].price < sta[now].price)
						break;
				}
			}

			if (k == -1)
				break;
			
			double need = (sta[k].distance - sta[now].distance) / davg;
			
			if (sta[k].price < sta[now].price)
			{
				if (nowTank < need)
				{
					totalPrice += (need - nowTank)*sta[now].price;
					nowTank = 0;
				}
				else
				{
					nowTank -= need;
				}
			}
			else
			{
				totalPrice += (c - nowTank)*sta[k].price;
				nowTank = c - need;
			}
			now = k;
		}
	}
}