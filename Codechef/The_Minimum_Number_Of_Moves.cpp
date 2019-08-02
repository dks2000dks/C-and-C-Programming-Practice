#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void Input_Array(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int n,o=0;
		cin >> n;

		int workers[n];
		Input_Array(workers,n);
		int m  = *min_element(workers,workers+n);

		for (int i = 0;i < n;i++)
		{
			o = o + (workers[i] - m);
		}

		cout << o << endl;
	}
}