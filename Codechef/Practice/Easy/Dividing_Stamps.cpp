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
	int n;
	cin >> n;

	int input[n];
	Input_Array(input,n);
	int c = Sum_elements_Array(input,n);

	int p = (n*(n+1))/2;

	if (c == p)
	{
		cout << "YES" << endl;
	}

	else
	{
		cout << "NO" << endl;
	}
}
