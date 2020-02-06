#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void Input_Two_Array(int *array, int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
		cin >> arr[i];
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int x,y,k,n;
		cin >> x >> y;
		cin >> k >> n;

		int r = x - y;

		int pages[n];
		int cost[n];
		int o=0;

		Input_Two_Array(pages,cost,n);

		for ( int i=0; i < n;i++)
		{
			if (pages[i] >= r && cost[i] <= k)
			{
				o = 1;
				break;
			}
		}

		if (o == 1)
		{
			cout << "LuckyChef" << endl;
		}

		else 
		{
			cout << "UnluckyChef" << endl;
		}
	}
}