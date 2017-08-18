#include <iostream>
#include<algorithm>
#include <string>

using namespace std;

bool cmp(string a, string b)
{
	return a + b < b + a;
}
int main()
{
	int n;
	string str[1010],ans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	sort(str, str + n, cmp);
	for (int i = 0; i < n; i++)
	{
		ans += str[i];
	}
	while (ans.size() != 0 && ans[0] == '0')
	{
		ans.erase(ans.begin());
	}
	if (ans.size() == 0)
		cout << 0 << endl;
	else
		cout << ans<<endl;
	system("pause");
}