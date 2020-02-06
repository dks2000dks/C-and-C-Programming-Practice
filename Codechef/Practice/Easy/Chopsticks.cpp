#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void Input_Array(long long int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	long long N,D;
	cin >> N >> D;

	long long L[N];
	Input_Array(L,N);

	std::sort(L,L+N);
	int o=0;

	for (int i=0;i<N;i++)
	{
		if ((L[i+1] - L[i]) < D+1)
		{
			i = i+1;
			o = o+1;
		}

		else
		{
			i = i;
		}
	}

	cout << o << endl;


}