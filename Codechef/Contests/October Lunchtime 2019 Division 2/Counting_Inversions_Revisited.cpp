#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void Input_Array(long long int *array1, long long int *array2, long long int size)
{
	long long int u;
	for (long long int i = 0; i < size; i++)
	{
		cin >> u;
		array1[i] = u;
		array2[i] = u;
	}
}

long long int Find_Index(long long int *array, long long int size,long long int find)
{
	long long int o;
	for (long long int i = 0;i < size; i++)
	{
		if (find == array[i])
		{
			o = i;
			i = size;
		}
	}

	return o;
}

long long int Less(long long int *array, long long int size,long long int t)
{
	long long int o = 0;

	long long int c = array[t];

	for(long long int i=t+1;i<size;i++)
	{
		if (c > array[i])
		{
			o++;
		}
	}
	
	return o;
}

int main()
{
	long long int T;
	cin >> T;

	while (T--)
	{
		long long int n,k,sum=0;
		cin >> n >> k;
		long long int a[n],b[n];
		Input_Array(a,b,n);
		sort(b,b+n);

		long long int m = k*(k-1)/2;

		for (long long int l=0;l<n;l++)
		{
			long long int r = a[l];
			long long int p = Find_Index(b,n,r);
			long long int q = Less(a,n,l);
		
			sum += p*m + q*k;

		}

		cout << sum << endl;
	}
}
