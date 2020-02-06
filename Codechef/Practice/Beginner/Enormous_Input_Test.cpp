#include<iostream> 
using namespace std;

int main()
{
	int n,k,o = 0,t;

	cin >> n;
	cin >> k;

	for(int i = 0;i < n;i++)
	{
		cin >> t;

		if (t % k == 0)
		{
			o = o + 1;
		}
	}

	cout << o << endl;
	
	return 0;
}