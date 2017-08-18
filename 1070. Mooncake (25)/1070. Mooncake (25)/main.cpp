#include <iostream>
#include<algorithm>

using namespace std;


struct Mooncake
{
	double tons;
	double price;
	double unitPrice;
}moo[1010];


bool cmp(Mooncake a,Mooncake b)
{
	return a.unitPrice>b.unitPrice;
}

int main()
{
	int n;//number of kinds
	double d;			//demands
	scanf("%d%lf", &n, &d);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &moo[i].tons);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &moo[i].price);
		moo[i].unitPrice = moo[i].price / moo[i].tons;
	}
	sort(moo, moo + n, cmp);
	double remain = d;//一旦用完就跳出循环
	double totalPrice = 0;
	for (int i = 0; i < n; i++)
	{
		if (remain >= moo[i].tons)
		{
			totalPrice += moo[i].price;
			remain -= moo[i].tons;
		}
		else
		{
			totalPrice += remain*moo[i].unitPrice;
				/*/ moo[i].tons*moo[i].price*/
			break;
		}
	}
	printf("%.2f",totalPrice);
	system("pause");
	return 0;

}