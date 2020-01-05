#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;


int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		long long int n,a,s,b,c,d,e,o;

		cin >> n;
		cin >> a;

		s = (2 * (long long int)(pow(10,n))) + a;

		cout << s << endl;
		fflush(stdout);
		s = s-a;

		cin >> b;
		s=s-b;

		c = (long long int)pow(10,n) - b;
		cout << c << endl;
		fflush(stdout);
		s = s-c;

		cin >> d;
		s=s-d;

		e = s;
		cout << e << endl;
		fflush(stdout);

		cin >> o;

		if (o == -1)
		{
			T=0;
			break;
		}

	}
}