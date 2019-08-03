#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void Multiply_Input_Array(int *array, int size, int m)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		cin >> k;
		array[i] =  m*k;
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

		int goals[n];
		int fouls[n];
		int points[n];

		Multiply_Input_Array(goals,n,20);
		Multiply_Input_Array(fouls,n,10);

		std::transform(goals, goals + n, fouls, points, std::minus<int>());

		for(int i=0;i < n;i++)
		{
			if (points[i] < 0)
			{
				points[i] = 0;
			}
		}

		int o = *max_element(points,points+n);
		cout << o << endl;

	}
}