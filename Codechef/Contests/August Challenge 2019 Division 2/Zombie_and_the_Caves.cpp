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

void add(int arr[], int N, int lo, int hi, int val) 
{ 
    arr[lo] += val; 
    if (hi != N - 1) 
       arr[hi + 1] -= val; 
} 
  
void updateArray(int arr[], int N) 
{ 
    for (int i = 1; i < N; i++) 
        arr[i] += arr[i - 1]; 
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int n;
		cin >> n;
		int k;
		int Health[n];
		int Radiation[n] = { 0 };


		for (int i=0;i < n;i++)
		{
			cin >> k;
			int a = i - k;
			int b = i + k;

			if (a > 0)
				a = a;
			else
				a = 0;

			if (b < n)
				b = b;
			else
				b = n-1;

			add(Radiation,n,a,b,1);			
		}

		updateArray(Radiation,n);

		Input_Array(Health,n);

		std::sort(Radiation,Radiation+n);
		std::sort(Health,Health+n);

		int o = 1;

		for (int i=0;i < n;i++)
		{
			if (Health[i] != Radiation[i])
			{
				o = 0;
				break;
			}
		}
		

		if (o == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
}