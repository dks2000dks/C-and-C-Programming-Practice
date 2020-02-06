#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

/*
Check the input "aabbaa"
*/

string getString(char x) 
{
	string s(1, x); 
    return s;    
}

void Print_Array(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		string input;
		cin >> input;

		char c = input[0]; 
		string output = "";

		int count=0;

		for (int i = 0; i < input.length(); ++i)
		{
			int x = int(input[i]);
			x = x-97;

			if (input[i] == c)
			{
				count++;
			}

			else
			{

				string y = getString(c);
				string z = to_string(count);
				output.append(y);
				output.append(z);
				count = 1;
			}

			c = input[i];
		}

		string y = getString(c);
		string z = to_string(count);
		output.append(y);
		output.append(z);

		if (output.length() < input.length())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}