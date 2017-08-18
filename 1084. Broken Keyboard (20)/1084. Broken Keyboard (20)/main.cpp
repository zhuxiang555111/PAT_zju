#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool hashTable[128] = {false};

int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	int i, j;
	for (i = 0; i < str1.length(); i++)
	{
		for (j = 0; j < str2.length(); j++)
		{
			if (str1[i] > 'a' && str1[i] < 'z')
				str1[i] -= 32;
			if (str2[j] > 'a'&&str2[j] < 'z')
				str2[j] -= 32;
			if(str1[i] == str2[j])
				break;//找到则跳出不再寻找
		}
		if (j == str2.size() && hashTable[str1[i]] == false)
		{
			cout << str1[i];
			hashTable[str1[i]] = true;
		}

	}
}