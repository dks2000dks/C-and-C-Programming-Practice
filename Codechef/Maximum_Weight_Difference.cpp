#include<iostream>
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

int Sum_elements_Array(int *array, int size)
{
	int o = 0;
	for (int i = 0; i < size; i++)
	{
		o += array[i];
	}

	return o;
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int n,k;
		cin >> n >> k;

		int weights[n];

		Input_Array(weights,n);

		std::sort (weights,weights + n);

		int s = Sum_elements_Array(weights,n);
		int p;
		

		if (n/2 >= k)
		{
			p = Sum_elements_Array(weights,k);
			
		}

		else
		{
			p = Sum_elements_Array(weights,n-k);
		}

		cout << s - 2*p << endl;
	}	
}