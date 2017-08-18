#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool hashTable[1010] = {false};

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	//vector<char> result;
	for (int i = 0; i < str2.length(); i++)
	{
		hashTable[str2[i]] = true;
	}
	for (int i = 0; i < str1.length(); i++)
	{
		if (hashTable[str1[i]] == false)
			cout << str1[i];
	}
	system("pause");
	
}