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
		int N;
		cin >> N;

		if (N%4 == 1)
		{
			cout << "ALICE" << endl;
		}

		else
		{
			cout << "BOB" << endl;
		}
	}
}