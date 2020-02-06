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
		int n,p = 0,q = 0;
		cin >> n;

		int A[n];
		Input_Array(A,n);

		for (int i = 0; i < n - 1; i++)
		{
			if(A[i] > A[i+1])
			{
				p++;
			}

			for (int j = i + 1;j < n;j++)
			{
				if (A[i] > A[j])
				{
					q++;
				}
			}

		}

		if (p == q)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}