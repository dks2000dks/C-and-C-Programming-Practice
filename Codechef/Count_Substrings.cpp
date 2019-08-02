#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
	long long int T;
	cin >> T;

	while (T--)
	{
		long long int n,p = 0;
		cin >> n;

		std::string check ("1");
		char c = check[0];

		/*

		for (int i = 0;i < n;i++)
		{
			char a = input.at(i);

			for (int j = i;j < n;j++)
			{
				char b = input.at(j);
				if ( a == c && b == c)
				{
					p = p + 1;
				}
			}
		}
		*/

		for (int i=0;i < n;i++)
		{
			char a;
			cin >> a;
			if (a == c)
			{
				p++;
			}
		}

		cout << p*(p+1)/2 << endl;
	}

	return 0;
}
