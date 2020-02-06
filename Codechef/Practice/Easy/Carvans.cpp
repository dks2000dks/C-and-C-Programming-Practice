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

int main()
{
	int t=0,T;
	cin >> T;

	while(t < T)
	{
		int n,o;
		cin >> n;
		int speed[n];
		Input_Array(speed,n);

		o = 0;
		int m = speed[0];				//First Car is always at Maximum Speed

		for (int i = 0;i < n;i++)
		{
			if(speed[i] > m)
			{
				speed[i] = m;
			}
			else
			{
				m = speed[i];
				o++;
			}

		}
		cout << o << endl;

		t++;
	}
}