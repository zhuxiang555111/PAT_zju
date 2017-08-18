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
	{
		int now = 0;//当前所处的加油站的编号
		double totalPrice = 0, nowTank = 0, maxDistance = c*davg;
		//累计总价，当前油量，满油续航里程
		while (now < n)//每次循环选出下一个要到达的加油站
		{
			int k = -1;//最低油价的加油站
			double priceMin = INF;//初始化最低价格

			//接下来找油价最低的,也就是说，不管存不存在油价比本站油价低的，都先去找，如果找到比本站低的，直接去到那个站点，并跳出循环，如果找不到，那就找到油价最低（比本站油价高）的那个
			for (int i = now + 1; i <= n&&sta[i].distance - sta[now].distance <= maxDistance; i++)
				//在续航里程范围内的
			{
				if (sta[i].price < priceMin)//找到比当前油价低的
				{
					priceMin = sta[i].price;//更新最低油价
					k = i;
					if (priceMin < sta[now].price)//找到比本站还低的，直接跳出循环
						break;
				}
			}


			if(k == -1)//满油状态下无法找到下一个能够到达的加油站，即最近的加油站都比最大续航里程要大，则直接跳出循环
				break;


			//下面开始为找到的加油站k,计算转移花费
			double need = (sta[k].distance - sta[now].distance) / davg;
			//need为转移需要加的油量


			if(priceMin < sta[now].price)//计算第一种情况，即油价比本站油价还低的，则只需要加能到达那个加油站的油量
			{
				if (nowTank < need)//当前的油量不够到达
				{
					totalPrice += (need - nowTank) *(sta[now].price);//在本站需要加的油的费用
					nowTank = 0;//到达加油站k后油箱为空
				}
				else//当前的油量大于到达下一个加油站需要的油量
				{
					nowTank -= need;//无需加油，直接到达，并且减去消耗的油量
				}
			}
			else//计算第二种情况，即后面的加油站最低价都比本站高,因此需要在本站直接加满
			{
				totalPrice += (c - nowTank)*sta[now].price;//加满
				nowTank = c - need;
			}
			now = k;//到达站点，进入下一层循环
		}


		if (now == n)//能到达
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