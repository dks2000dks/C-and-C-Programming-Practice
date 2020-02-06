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
		int n,m;
		int p;
		cin >> n >> m;
		int turn[m];
		Input_Array(turn,m);
		int cats[n] = {0};

		for (int i=0;i<m;i++)
		{
			p = 0;
			int x = turn[i];
			int t = cats[x-1];
			cats[x-1] = t+1;

			int* max;
			int* min; 
    		max = std::max_element(cats, cats + n);
    		min = std::min_element(cats, cats + n);
    		
    		int d = *max - *min;
    		
    		if (d == 2)
    		{
    			p = 1;
    			break;
    		}

    	}

    	if (p==1)
		{
			cout << "NO" << endl;
		}

		else
		{
			cout << "YES" << endl;
		}

	}
}
