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
		long long int n,k;
		cin >> n >> k;

		if (k!=0)
		{
			cout << n/k << " " << n%k << endl;
		}

		else
		{
			cout << 0 << " " << n << endl;
		}
		
	}

	return 0;
}