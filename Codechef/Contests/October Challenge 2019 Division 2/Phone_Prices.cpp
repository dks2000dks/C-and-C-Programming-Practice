#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>
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
		int n;
		cin >> n;
		int dollars[n];

		Input_Array(dollars,n);
		int o = 1;

		for (int i=1;i<n;i++)
		{
			int j = i-1;
			int g = 0;

			while (j>-1 && j>i-6)
			{
				if(dollars[j] > dollars[i])
				{
					g++;
					j--;
				}

				else
				{
					g = 0;
					break;					
				}
			}

			if (g<6 && g>0)
			{
				o++;
			}
		}

		cout << o << endl;
	}
}