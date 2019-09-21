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

int Sum_Square_Array(int *array, int size)
{
	int o;

	for (int i = 0; i < size; i++)
	{
		int a = array[i];
		o = a*a;
	}

	return o;
}

void Square_Array(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = array[i]*array[i];
	}
}


int main()
{
	int T,output=0;
	cin >> T;

	while(T--)
	{
		int x1,x2,x3,y1,y2,y3;

	    cin >> x1 >> y1 >> x2 >> y2 >> x3 >>y3;

	    int a = pow((x1-x2),2) + pow((y1-y2),2);
	    int b = pow((x2-x3),2) + pow((y2-y3),2);
	    int c = pow((x1-x3),2) + pow((y1-y3),2);
	    
	    int s[3] = {a,b,c};
	    sort(s,s+3);

	    if(s[0] + s[1] == s[2])
	    {
	    	output++;
	    }
	}

	cout << output << endl;	

}