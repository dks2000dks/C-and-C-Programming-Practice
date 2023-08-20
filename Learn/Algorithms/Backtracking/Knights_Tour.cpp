//https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
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

#define N 8

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

bool isSafe(int x, int y, vector<vector<int>> &output)
{
	return (x >= 0 and x < N and y >= 0 and y < N and output[x][y]==-1);
}

bool KTExplore(int x, int y, int movecount, vector<vector<int>> &output, const vector<int> xMove, const vector<int> yMove)
{
	int nextx,nexty;
	if (movecount == N*N)
		return true;

	fr(i,0,7)
	{
		nextx = x + xMove[i];
		nexty = y + yMove[i];
		if (isSafe(nextx,nexty,output))
		{
			output[nextx][nexty] = movecount;
			
			if (KTExplore(nextx,nexty,movecount+1,output,xMove,yMove))
			{
				return true;
			}

			else
			{
				output[nextx][nexty] = -1;
			}
		}
	}
	return false;
}

int KT()
{
	vector<vector<int>> output(N,vector<int> (N,-1));
	output[0][0] = 0;

	// Assuming current position of (0,0)
	std::vector<int> xMove = {2, 1, -1, -2, -2, -1, 1, 2};
	std::vector<int> yMove = {1, 2, 2, 1, -1, -2, -2, -1};

	if (KTExplore(0, 0, 1, output, xMove, yMove) == false)
	{
		cout << "Solution does not exist" << endl;
		return 0;
	}
	else
		Output_Matrix(output,N,N);

	return 1;
}

int main()
{
	KT();
}