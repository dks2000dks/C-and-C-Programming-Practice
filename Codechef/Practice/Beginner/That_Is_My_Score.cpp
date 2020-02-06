#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int n,sum=0;
		cin >> n;

		int marks[8]={};

		for (int i=0;i<n;i++)
		{
			int p=0,q=0;
			cin >> p >> q;

			p = p-1;

			if (p < 8)
			{
				int m = marks[p];
				int x = max(q,m);
				marks[p] = x;
			}
		}

		for (int i=0;i<8;i++)
		{
			sum  += marks[i];
		}

		cout << sum << endl;
	}
}