#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int hashTable[80] = { 0 };
int miss = 0;

int change(char c)//将字符转换为hash下标，也可以看作是一种hash映射
{
	if (c > '0'&&c < '9')
		return c - '0';
	if (c > 'A'&&c < 'Z')
		return c - 'A' + 10;
	if (c > 'a'&&c < 'z')
		return c - 'a' + 36;
}
int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	for (int i = 0; i < str1.length(); i++)
	{
		int id = change(str1[i]);
		hashTable[id]++;
	}
	for (int i = 0; i < str2.length(); i++)
	{
		int id = change(str2[i]);
		if (hashTable[id] == 0)
			miss++;
		else if (hashTable[id] > 0)
			hashTable[id]--;
	}
	if(miss > 0)
	{
		printf("No %d\n", miss);
	}
	else
	{
		printf("Yes ");
		cout << str1.length()-str2.length()<<endl;
	}
	system("pause");
	return 0;
}