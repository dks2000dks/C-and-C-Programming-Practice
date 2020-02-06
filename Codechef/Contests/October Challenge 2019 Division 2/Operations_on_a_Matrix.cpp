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
		long long int n,m,q,r,s,o=0;
		cin >> n >> m >> q;

		long long int row[m] = {};
		long long int column[n] = {};

		for(int i=0;i<q;i++)
		{
			cin >> s >> r;

			long long int a = row[r-1];
			long long int b = column[s-1];

			row[r-1] = a+1;
			column[s-1] = b+1;
		}

		long long int e1=0,o1=0,e2=0,o2=0;

		if (n > m)
		{
			for (int i=0;i<n;i++)
			{
				if (column[i] % 2 == 0)
					e2++;
				else
					o2++;
				
				if (i<m)
				{
					if (row[i] % 2 == 0)
						e1++;
					else
						o1++;
				}
			}
		}

		else
		{
			for (int i=0;i<m;i++)
			{
				if (row[i] % 2 == 0)
					e1++;
				else
					o1++;

				if (i<n)
				{
					if (column[i] % 2 == 0)
						e2++;
					else
						o2++;
				}
			}
		}

		cout << e1*o2 + e2*o1 << endl;
	}
}