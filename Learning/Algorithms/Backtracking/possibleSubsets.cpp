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
#define fr(i, a, b) for (int i=a; i<=b; i++)

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

void possibleSubsets(std::vector<string> v, std::vector<string> output)
{
	if (v.size() == 0)
	{
		Print_Vector(output,output.size());
	}

	else
	{
		string s = v.back();

		v.pop_back();
		possibleSubsets(v,output);

		output.push_back(s);
		possibleSubsets(v,output);

		//v.push_back(s);
		//output.pop_back();
	}
}

void possibleSubsets1(std::vector<string> &v, std::vector<string> &output)
{
	if (v.size() == 0)
	{
		Print_Vector(output,output.size());
	}

	else
	{
		string s = v.back();

		std::vector<string> v1,output1;

		v1.assign(v.begin(),v.end());
		output1.assign(output.begin(),output.end());

		v1.pop_back();
		possibleSubsets(v1,output1);

		output1.push_back(s);
		possibleSubsets(v1,output1);
	}
}

int main()
{
	int n;
	cin >> n;
	std::vector<string> v(n);
	Input_Vector(v,n);

	std::vector<string> output;

	possibleSubsets(v,output);
}