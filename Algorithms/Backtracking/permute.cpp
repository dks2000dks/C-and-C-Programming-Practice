#include<iostream>
#include<cmath>
#include <cassert>
#include<algorithm>
#include <cstdlib>
#include<vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include<string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FR(i, a, b) for (int i=a; i<=b; i++)

void Input_Vector(vector<string> &array, int size)
{
	int x;
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

void Print_Vector(vector<string> &array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void permute(std::vector<string> &v, std::vector<string> output)
{
	if (v.size() == 0)
		Print_Vector(output,output.size());
	else
	{
		FR(i,0,v.size()-1)
		{
			string s = v[i];
			v.erase(v.begin()+i,v.begin()+i+1);
			output.push_back(s);

			permute(v,output);

			output.pop_back();
			v.insert(v.begin()+i,s);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	std::vector<string> v(n);
	Input_Vector(v,n);

	std::vector<string> output;

	permute(v,output);
}