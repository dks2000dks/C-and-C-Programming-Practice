#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

char XOR(char a,char b)
{
	if ((a == '0' && b == '0') || (a == '1' && b == '1'))
		return '0';
	else
		return '1';

}

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
		int n;
		cin >> n;
		std::string a,b;

		for(int i=0;i<n;i++)
		{
			cin >> a;

			if (i==0)
				b = a;
			
			else
			{
				for (int j=0;j<10;j++)
				{
					char p = a[j];
					char q = b[j];
					char r = XOR(p,q);
					b[j] = r;
				}
			}
		
		}

		int o = Count_Find(b,'1');
		cout << o << endl;
		
	}
}