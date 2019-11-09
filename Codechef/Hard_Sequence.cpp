#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

int Find_Index(vector<int> &array, int size,int find)
{
	int o = -1;

	for (int i = (size-1);i >=0; i--)
	{
		if (array[i] == find)
		{
			o = i;
			break;
		}
	}

	return o;
}

int main()
{
	int T;
	cin >> T;
	vector <int> a,b;

	int r = 126;
	a.push_back(0);
	a.push_back(0);

	while(r--)
	{
		b = a;
		b.pop_back();

		int s = b.size();
		int f = a.back();
		
		int l = Find_Index(b,s,f);

		if(l==-1)
		{
			a.push_back(0);
		}

		else
		{
			a.push_back(s-l);
		}

	}
	
	while(T--)
	{
		int n;
		cin >> n;

		int o = 0;
		for (int i = 0;i < n; i++)
		{
			if (a[n-1] == a[i])
			{
				o++;
			}
		}

		cout << o << endl;
	}
}