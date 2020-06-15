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

// Version-1 for Input_Vector
void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> x;
		array.push_back(x);
	}
}

// Version-2 for Input_Vector
void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

void Input_Matrix(vector<vector<int>> &v, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

void Print_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

int Transpose_Matrix(vector< vector<int> > &mato, vector< vector<int> > &matt, int n, int m){
	int x;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			x = mato[j][i];
			matt[i][j] = x;
		}
	}
}

int Output_Matrix(vector< vector<int> > &mat, int n, int m){
	for (int i=0;i<n;i++){
		for (int j =0;j<m;j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
vector<int> SubVector(vector<int> const &v, int m, int n){
	auto first = v.begin() + m;
	auto last = v.begin() + n + 1;
	vector<int> vector(first, last);
	return vector;
}

void Input_Array(int *array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

void Print_Array(int *array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

int Count_Find(string str,char find){
	int size = str.length();
	int o = 0;
	for (int i = 0;i < size; i++){
		if (find == str[i]){
			o++;
		}
	}
	return o;
}

char XOR(char a,char b){
	if ((a == '0' && b == '0') || (a == '1' && b == '1'))
		return '0';
	else
		return '1';
}

void Multiply_Element_Array(int *array, int size, int m){
	for (int i = 0; i < size; i++){
		array[i] =  m*array[i];
	}
}

void Input_Two_Array(int *array, int *arr, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
		cin >> arr[i];
	}
}

int Sum_elements_Array(int *array, int size){
	int o = 0;
	for (int i = 0; i < size; i++){
		o += array[i];
	}
	return o;
}

int factorial(int t){
	int e = 1,p = 1,o = 0,f;

	while(e){
		p = p * 5;
		f = t/p;
		o = o + t/p;

		if (f == 0){
			e = 0;
		}
	}
	return o;
}

int Print_Primes(int a,int b){
	for (int n = a; n < b + 1;n++){
		if (!(n%2 == 0 && n != 2))		{
			int p = 1;
			for(int f = 3;f < sqrt(n) + 1;f = f+2){
				if(n%f == 0){
				p = 0;
				break;
				}
			}

			if (p == 1)
				cout << n << endl;
		}
	}
}

void swapping_elements_array(int &a, int &b){ 
	int x;
	x = a;
	a = b;
	b = x;
}

void SelectionSort(int *array, int size){

	int i, j, imin;
	
	for(i = 0; i<size-1; i++){
		imin = i;

		for(j = i+1; j<size; j++){
        	if(array[j] < array[imin])
            	imin = j;
		}
		swap(array[i], array[imin]);
	}
}

int Find_Index(int *array, int size,int find){
	int o;
	for (int i = 0;i < size; i++){
		if (find == array[i]){
			o = i;
			i = size;
		}
	}
	return o;
}

int Fibonacci(int N){
	int o[N];

	o[0] = 0;
	o[1] = 1;

	for(int i=2;i<N;i++){
		o[i] = o[i-1] + o[i-2];
	}
	return o;
}

int IsPrime(int n){
	int o=1;

	if (n%2 == 0 && n!= 2) 
		o = 0;
  
	for (int i = 3; i < sqrt(n) + 1; i = i+2) 
		if (n % i == 0) 
			o = 0; 
  
    return o; 
}

int Sum_elements_Vector(vector<int> array, int size){
	int o = 0;
	for (int i = 0; i < size; i++){
		o += array[i];
	}
	return o;
}

int Elemental_Multiply_Sum_Vector(vector<int> array1, vector<int> array2){
	int size1 = array1.size();
	int size2 = array2.size();
	int size;

	if (size1 == size2)
		size = size1;
	else{
		cout << "Sizes Clash" << endl;
		cout << array1.size() << ", " << array2.size() << endl;
	}

	int o = 0;
	for (int i = 0; i < size; i++){
		o += array1[i] * array2[i];
	}
	return o;
}

vector<int> MergeSort(vector<int> const &v, int n){
	int mid = n/2;
	int x;
	vector<int> output;

	if (n > 1){
		vector<int> input1 = SubVector(v,0,mid-1);
		vector<int> input2 = SubVector(v,mid,n-1);
		
		int n1 = input1.size();
		int n2 = input2.size();
		
		vector<int> output1 = MergeSort(input1,n1);
		vector<int> output2 = MergeSort(input2,n2);
		
		int i=0,j=0;
		while (i<n1 && j<n2){
			if (output1[i] < output2[j]){
				x = output1[i];
				i++;
			}
			
			else{
				x = output2[j];
				j++;
			}

			output.push_back(x);
		}

		while(i<n1 && j>=n2){
			output.push_back(output1[i]);
			i++;
		}

		while (i>=n1 && j<n2){
			output.push_back(output2[j]);
			j++;
		}
		
	}

	else{
		output = v;
	}

	return output;
}

vector<int> Max_Crossing_SubArray(vector<int> const &v, int l, int m, int h){
	int sum;
	vector<int> output;

	int leftsum = INT_MIN;
	int ml;
	sum=0;
	for (int i=m;i>=l;i--){
		sum += v[i];
		if (sum > leftsum){
			leftsum = sum;
			ml = i;
		}
	}

	int rightsum = INT_MIN;
	int mr;
	sum=0;
	for (int i=m+1;i<=h;i++){
		sum += v[i];
		if (sum > rightsum){
			rightsum = sum;
			mr = i;
		}
	}

	output.push_back(ml);
	output.push_back(mr);
	output.push_back(leftsum + rightsum);

	return output;
}

vector<int> Max_SubArray(vector<int> const &v, int l, int h){
	vector<int> output;
	if (h==l){
		output.push_back(l);
		output.push_back(h);
		output.push_back(v[l]);
	}

	else{
		int m = (l+h)/2;
		
		vector<int> left = Max_SubArray(v,l,m);
		vector<int> right = Max_SubArray(v,m+1,h);
		vector<int> cross = Max_Crossing_SubArray(v,l,m,h);

		if (left[2] >= right[2] && left[2] >= cross[2]){
			output =  left;
		}

		else if (right[2] >= left[2] && right[2] >= cross[2]){
			output =  right;
		}

		else{
			output =  cross;
		}
	}
	return output;
}