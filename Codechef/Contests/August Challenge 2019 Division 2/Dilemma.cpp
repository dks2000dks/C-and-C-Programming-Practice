#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


int Count_Find(string str,char find)
{
	int size = str.length();
	int o = 0;
	for (int i = 0;i < size; i++)
	{
		if (find == str[i])
		{
			o++;
		}
	}

	return o;
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		string input;
		cin >> input;
		char c = '1';

		int o = Count_Find(input,c);

		if (o%2 == 0)
		{
			cout << "LOSE" << endl;
		}

		else
		{
			cout << "WIN" << endl;
		}
	}
} 