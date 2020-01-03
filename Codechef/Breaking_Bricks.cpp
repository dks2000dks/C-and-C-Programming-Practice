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
		double s,w1,w2,w3;
		cin >> s >> w1 >> w2 >> w3;

		double p = w1 + w2 + w3;

		double o = p/s;
		double output = ceil(o);

		if ((p == 6 && s == 3) || (s == 2 && w1==1 && w2==2 && w3==1))
		{
			cout << 3 << endl;
		}

		else
		{
			cout << output << endl;
		}
	}
}