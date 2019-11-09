#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

int compare(string s)
{
	int n,c = 0;
	n = s.size();

	for (int i=0;i<n;i++)
	{
		char t = s[i];
		if(t == 'a'||t == 'e'||t == 'i'||t == 'o'||t == 'u')
			c++;
		else
			c--;
	}

	if(c >= 0)
		return 1;
	else
		return 0;
}

int person(string s)
{
	int o=1;
	int size = s.size();
	if(size==2&&!compare(s.substr(0,2)))
		o=0;
	for(int i=0;i<size-2;i++){
		if(!compare(s.substr(i,3))){
			o=0;
			break;
		}
	}

	return o;
}

int Input_Array(vector <string> &a, vector <string> &b, int size)
{
	string k;

	for (int i = 0; i < size; i++)
	{
		cin >> k;

		int p = person(k);

		if (p == 0)
		{
			b.push_back(k);
		}
		else
		{
			a.push_back(k);
		}
	}
}

void Print_Array(vector <string> &a)
{
	int size = a.size();
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}

long double calculate(vector <string> &a)
{
	int n = a.size();
	int e[26] = {};
	int d[26] = {};
	long double o = 1;

	for(int i=0;i<n;i++)
	{
		int c[26] = {};
		string str = a[i];
		int h = str.size();

		for (int k=0;k<h;k++)
		{
			int l = (int)str[k];
			c[l-97]++;
		}

		for(int j=0;j<26;j++)
		{
			int p = c[j];
			if (p > 0)
			{
				d[j]++;
			}
		}

		for(int j=0;j<26;j++)
		{
			int q = c[j];
			int w = e[j];
			e[j] = q+w;
		}	


	}

	for (int u=0;u<26;u++)
	{
		if(d[u] > 0)
		{
			long double z = (d[u])/(pow(e[u],n));
			o = o * z;

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
		int L;
		cin >> L;

		std::vector<string> alice,bob;
		Input_Array(alice,bob,L);

		long double s1 = calculate(alice);
		long double s2 = calculate(bob);
		long double d = s1/s2;

		if(d > pow(10,7))
			cout << "Infinity" << endl;
		else
			cout << setprecision(16) << d << endl;

	}
}