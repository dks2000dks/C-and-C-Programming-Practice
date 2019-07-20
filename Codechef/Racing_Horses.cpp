#include<iostream>
using namespace std;

void swapping(int &a, int &b)
{ 
	int x;
	x = a;
	a = b;
	b = x;
}

void SelectionSort(int *array, int size)
{

	int i, j, imin;
	
	for(i = 0; i<size-1; i++)
	{
		imin = i;

		for(j = i+1; j<size; j++)
        {
        	if(array[j] < array[imin])
            	imin = j;
		}
		swap(array[i], array[imin]);
	}
}


int main()
{
   int t,n,d,j = 0;
   cin >> t;

   while (j < t)
   {
   cin >> n;
   int arr[n];           
   
   for(int i = 0; i<n; i++)
   {
      cin >> arr[i];
   }

   	SelectionSort(arr, n);
   
	d = arr[1] - arr[0];

   for (int i = 1 ;i < n-1;i++)
   {
   		if(abs(arr[i+1] - arr[i]) < d)
   		{
   			d = arr[i+1] - arr[i];
   		}
   }

   cout << d << endl;
   j++;
   }

   return 0;
}