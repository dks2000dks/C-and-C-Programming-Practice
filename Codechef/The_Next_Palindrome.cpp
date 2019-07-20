#include <iostream>
#include <string>
using namespace std;

int max(int a,int b)
{
	if (a > b)
		return a;
	else
		return b;
}


int main()
{
	int n,l,j = 0;
	cin >> n;
	while (int i = 0 < n)
	{
		string s;
		cin >> s;
		l = s.length();
		s[0] = s[n-1];

		if (l % 2 = 0)
		{
			for (j = 1;j <= (l/2);j++)
			{
				s[j] =  (s[j] , s[l-1-j]);
				s[l-1-j] = s[j];
			}
		}

		else
		{
			0
		}
	}
}