#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int Check_Prime(int n)
{

}


int Print_Primes(int a,int b)
{
	for (int n = a; n < b + 1;n++)
	{
		if (!(n%2 == 0 && n != 2))
		{
			int p = 1;
			for(int f = 3;f < sqrt(n) + 1;f = f+2)
			{
				if(n%f == 0)
				{
				p = 0;
				break;
				}
			}

			if (p == 1)
				cout << n << endl;
		}
	}
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int a,b;
		cin >> a >> b;
		if (a == 2 || a == 1 || a == 0)
			Print_Primes(2,b);
		else 
			Print_Primes(a,b);
	}
}