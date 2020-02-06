#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int p,s;
		cin >> p >> s;

		float k = (p - sqrt(p*p - 24*s))/12;
		float V = k*(s/2.0 - k*(p/4.0 - k));

		cout << V << endl;
	}
}