/*
The longest common subsequence (LCS) problem is the problem of finding the longest subsequence common to all sequences in a set of sequences (often just two sequences).
It differs from the longest common substring problem: unlike substrings, subsequences are not required to occupy consecutive positions within the original sequences.

For Example:
consider the sequences (ABCD) and (ACBAD).
They have 5 length-2 common subsequences: (AB), (AC), (AD), (BD), and (CD); 2 length-3 common subsequences: (ABD) and (ACD); and no longer common subsequences.
So (ABD) and (ACD) are their longest common subsequences.
*/

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

void Input_Vector(vector<int> &array, int size)
{
	int x;
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

int LCS(char *X, char *Y, int m, int n)
{
	int table[m+1][n+1];

	FR(i,0,m)
	{
		FR(j,0,n)
		{
			if (i==0 || j==0)
				table[i][j] = 0;
			else if (X[i-1] == Y[j-1])
				table[i][j] = table[i-1][j-1] + 1;
			else
				table[i][j] = max(table[i-1][j],table[i][j-1]);
		}
	}

	return table[m][n];
}

int main()
{
	int m,n;
	cin >> m >> n;
	char X[m],Y[n];
	cin >> X;
	cin >> Y;

	cout << LCS(X,Y,m,n) << endl;
}