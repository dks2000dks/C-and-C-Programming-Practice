#include<iostream> 
using namespace std;

int fct(int t)
{
	int e = 1,p = 1,o = 0,f;

	while(e)
	{
		p = p * 5;
		f = t/p;
		o = o + t/p;

		if (f == 0)
		{
			e = 0;
		}
	
	}
	
	return o;
}

int main()
{
	int n,i,a;

	cin >> n;
	int o[n];

	for (i = 0;i < n;i++)
	{
		cin >> a;
		o[i] = fct(a);
	}

	for (i = 0;i < n;i++)
	{
		cout << o[i] << endl;
	}

	return 0;
}
