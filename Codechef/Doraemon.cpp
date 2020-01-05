#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

int Input_Matrix(vector< vector<int> > &mat, int n, int m)
{
	int x;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cin >> x;
			mat[i][j] = x;
		}
	}
}

int Output_Matrix(vector< vector<int> > &mat, int n, int m)
{
	int x;
	for (int i=0;i<n;i++)
	{
		for (int j =0;j<m;j++)
		{
			cout << mat[i][j] << " ";
		}

		cout << endl;
	}
}


int Compute(vector< vector<int> > &matrix, int n, int m)
{
	int pairs=n*m;

	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			int t=1;
			while(t)
			{
				if (i-t>=0 && i+t<=n-1 && j-t>=0 && j+t<=m-1)
				{
					int left = matrix[i][j-t];
					int right = matrix[i][j+t];
					int top = matrix[i-t][j];
					int bottom = matrix[i+t][j];

					if (top == bottom && left == right)
					{
						pairs++;
						t++;
					}

					else
					{
						break;
					}
				}

				else
					break;
			}
		}
	}

	return pairs;
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int n,m;
		cin >> n >> m;

		vector<vector<int> > M(n,vector<int> (m));

		Input_Matrix(M,n,m);
		int o = Compute(M,n,m);
		//Output_Matrix(MO,n,m);
		//Output_Matrix(MT,m,n);
		cout << o << endl;
	}
}