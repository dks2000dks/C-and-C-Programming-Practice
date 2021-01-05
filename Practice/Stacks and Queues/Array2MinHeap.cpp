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
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

vector<int> MinHeapify(vector<int> &array, int n, int i)
{
	// n --- Heap Size
	// i --- Heap Index

    vector<int> o1;

	int l = 2*i + 1;
	int r = 2*i + 2;

	int smallest = i;

	if (l<n && array[l] < array[i])
		smallest = l;

	if (r<n && array[r]  < array[smallest])
		smallest = r;

	if (smallest != i)
	{
        o1.push_back(i);
        o1.push_back(smallest);
        swap(array[i],array[smallest]);
		vector<int> o2 = MinHeapify(array,n,smallest);
        o1.insert(o1.end(),o2.begin(),o2.end());
	}

    return o1;
}

vector<int> BuildMinHeap(vector<int> &array, int n)
{
	// n = Size of Input

	int heapsize = n;

    vector<int> o;

	for (int i=(n/2); i>=0; i--)
	{
		vector<int> o2 = MinHeapify(array,heapsize,i);
        o.insert(o.end(),o2.begin(),o2.end());
	}

    return o;
}

int main(){
    int n;
    cin >> n;
    vec1d(v,int,n,0);
    Input_Vector(v,n);

    vector<int> output = BuildMinHeap(v,n);
    int o = output.size();
    cout << o/2 << endl;
    for(int i=0; i<o/2; i++){
        cout << output[2*i] << " " << output[2*i+1] << endl;
    }
}