#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct store
{
	int number;
	bool use = false;
};
bool cmpSmaller(store a, store b)
{
	return a.number > b.number;
}

bool cmpBigger(store a, store b)
{
	return a.number < b.number;
}


int main()
{
	int nc, np;
	int sum = 0;
	vector<store> coupons, products;
	scanf("%d", &nc);
	for (int i = 0; i < nc; i++)
	{
		store couponsTemp;
		scanf("%d", &couponsTemp.number);
		couponsTemp.use = false;
		coupons.push_back(couponsTemp);
	}
	scanf("%d", &np);
	for (int i = 0; i < np; i++)
	{
		store productsTemp;
		scanf("%d", &productsTemp.number);
		productsTemp.use = false;
		products.push_back(productsTemp);
	}
	sort(coupons.begin(), coupons.end(), cmpSmaller);
	sort(products.begin(), products.end(), cmpSmaller);
	for (int i = 0; i < coupons.size() && i < products.size(); i++)
	{
		if ((!coupons[i].use) && (!products[i].use))
		{
			if (coupons[i].number > 0 && products[i].number > 0)
				sum += coupons[i].number*products[i].number;
			else
				break;
		}
	}
	sort(coupons.begin(), coupons.end(), cmpBigger);
	sort(products.begin(), products.end(), cmpBigger);
	for (int i = 0; i < coupons.size() && i < products.size(); i++)
	{
		if ((!coupons[i].use) && (!products[i].use))
		{
			if (coupons[i].number < 0 && products[i].number < 0)
				sum += coupons[i].number*products[i].number;
			else
				break;
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}