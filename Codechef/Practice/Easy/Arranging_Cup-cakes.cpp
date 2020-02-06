#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int IsPrime(int n) 
{
	int o=1;

	if (n%2 == 0 && n!= 2) 
		o = 0;
  
	for (int i = 3; i < sqrt(n) + 1; i = i+2) 
		if (n % i == 0) 
			o = 0; 
  
    return o; 
} 

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int N;
		cin >> N;
		
		int m=N;
		int p = IsPrime(N);

		if (p==1)
		{
			cout << N-1 << endl;
		}

		else
		{
			for (int i=2;i < sqrt(N) + 1;i++)
			{
				int x = abs(i - N/i);

				if(N%i == 0 && x < m)
				{				
					m = x;
				}
			}

			cout << m << endl;
		}
	}
}