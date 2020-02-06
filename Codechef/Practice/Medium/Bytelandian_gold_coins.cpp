#include <iostream>
using namespace std;

long long int max(long long int a,long long int b)
{
	if (a > b)
		return a;
	else
		return b;
}

long long int BA (long long int m)
{
	 
	 if (m <= 8)
	 {
	 	return m;
	 }

	 else
	 {
	 	return max(m,BA(m/2) + BA(m/3) + BA(m/4));
	 }
}

int main()
{
	int i = 0;
	while (i < 10)
	{
		long long int m;
		if (cin >> m)
		{
			cout << BA(m) << endl;
		}
		else
		{
			break;
		}
	}

	return 0;
}