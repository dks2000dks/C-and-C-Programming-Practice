#include<iostream> 
using namespace std;

int main()
{
	int x;
	double y;

	cin >> x;
	cin >> y;

	if(x + 0.5 < y)
	{
		if (x % 5 == 0)
		{
			y = y - x - 0.5;
			cout << y << endl;
		}

		else
		{
			cout << y << endl;
		}
	}

	else
	{
		cout << y << endl;
	}

	return 0;
}