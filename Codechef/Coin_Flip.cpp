#include<iostream>
using namespace std;

int main()
{
	int t=0,T;
	cin >> T;

	while (t < T)
	{
		int g=0,G;
		cin >> G;

		while (g < G)
		{
			int c,n,d;
			cin >> c;
			cin >> n;
			cin >> d;

			if (n % 2 == 0 || c == d)
    			cout << n/2 << endl;
			else
    			cout << (n/2 + 1) << endl;
			g++;
		}
		t++;
	}
}