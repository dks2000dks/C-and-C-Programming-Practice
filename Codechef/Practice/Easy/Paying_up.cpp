#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

void Input_Array(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

void Print_Vector(const vector<int> &array)
{
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << endl;
	}
}


void distSumRec(int *arr, int n, int sum, int currindex, unordered_set<int> &s) 
{ 
    if (currindex > n) 
        return; 
  
    if (currindex == n) 
    { 
        s.insert(sum); 
        return; 
    } 
  
    distSumRec(arr, n, sum + arr[currindex], currindex+1, s); 
    distSumRec(arr, n, sum, currindex+1, s); 
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int n,m;
		cin >> n >> m;
		int notes[n];
		Input_Array(notes,n);
		unordered_set<int> s;

		distSumRec(notes,n,0,0,s);

		std::vector<int> o(s.begin(), s.end());
		
		sort(o.begin(), o.end());
		int p=0;
		// Print_Vector(o);

		for(int i=0;i<o.size();i++)
		{
			if (m == o[i])
			{
				p = 1;
				break;
			}
		}

		if (p==1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}