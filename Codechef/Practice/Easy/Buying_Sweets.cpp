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
	int t = 0,T;
	cin >> T;

	while (t < T)
	{
		int n,x;
		cin >> n >> x;

		int value[n];
		Input_Array(value,n);
		int s,s1,p = 1;
		s = Sum_elements_Array(value,n);

		if (s%x == 0)
		{
			cout << s/x << endl;
		}

		if (s%x != 0)
		{
			for (int i=0;i < n;i++)
			{
				s1 = s - value[i];

				if (s1/x == s/x)
				{
					i = n;
					p = 0;
					cout << -1 << endl;
				}
			}

			if (p == 1)
			{
				cout << s/x << endl;
			}
		}
		t++;
	}
}