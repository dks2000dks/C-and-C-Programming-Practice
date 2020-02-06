#include<iostream>
#include<cmath>
#include <queue>
#include <climits>
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

struct Node
{
	// value stores the element,
	// list_num stores list number of the element
	// index stores column number of the list from which element was taken
	int value, list_num, index;
};

// Comparison object to be used to order the heap
struct comp
{
	bool operator()(const Node lhs, const Node rhs) const
	{
		return lhs.value > rhs.value;
	}
};

pair <int, int> findMinimumRange(vector<vector<int>> list, int M)
{
	// high will be maximum element in the heap
	int high = INT_MIN;

	// stores minimum and maximum element found so
	// far in heap
	pair<int,int> p = {0, INT_MAX};

	// create an empty min-heap
	priority_queue<Node, std::vector<Node>, comp> pq;

	// push first element of each list into the min-heap
	// along with list number and their index in the list
	for (int i = 0; i < M; i++)
	{
		pq.push({list[i][0], i, 0});
		high = max(high, list[i][0]);
	}

	// run till end of any list is not reached
	for (;;)
	{
		// get root node information from the min-heap
		int low = pq.top().value;
		int i = pq.top().list_num;
		int j = pq.top().index;

		// remove root node
		pq.pop();

		// update low, high if new min is found
		if (high - low < p.second - p.first) {
			p = {low, high};
		}

		// return on reaching the end of any list
		if (j == list[i].size() - 1) {
			return p;
		}

		// take next element from "same" list and
		// insert it into the min-heap
		pq.push({list[i][j + 1], i, j + 1});

		// update high if new element is greater
		high = max(high, list[i][j + 1]);
	}
}


int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int n,m;
		cin >> n >> m;

		int input[n];
		Input_Array(input,n);
		vector<vector<int>> list(m,vector<int>(1));

		for (int i=0;i<n;i++)
		{
			if (i<m)
			{
				int k = input[i];
				list[i][0] = k;
			}

			else
			{
				list[i%m].push_back(input[i]);
			}
		}

		for (int i=0;i<list.size();i++)
		{
			sort(list[i].begin(),list[i].end());
		}


		pair<int, int> p = findMinimumRange(list, m);
		cout << p.second - p.first << endl;

	}
}