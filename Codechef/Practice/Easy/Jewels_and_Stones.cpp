#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int t=0,T;
	cin >> T;

	while (t < T)
	{
		std::string j,s;
		cin >> j;
		cin >> s;
		int p = j.length();
		int q = s.length();
		int o = 0;

		for (int i = 0;i < q;i++)
		{
			char c = s[i];
			for (int l = 0;l < p;l++)
			{
				if (c == j[l])
				{
					o++;
					break;
				}
			}
		}

		cout << o << endl;
		t++;
	}

}