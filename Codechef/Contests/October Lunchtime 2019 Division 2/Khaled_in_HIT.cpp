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

void Print_Array(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}


int main()
{
	int T;
	cin >> T;
	
	while(T--)
	{
		int n,o;
		cin >> n;
		int a[n] = {};

		Input_Array(a,n);
		sort(a,a+n);
				
		int k = n/4;

		for(int i=k-1;i<n;i++)
		{
			if(a[i] == a[i+1])
			{
				o = -1;
				break;
			}

			else
			{
				i += k-1;
				o = 0;
			}
		}

		if (o != -1)
		{
			for (int j=k;j<n;j++)
			{
				cout << a[j] << " ";
				j += k-1;
			}
		}

		else
		{
			cout << o << endl;
		}
	}
}
