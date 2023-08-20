// Source: https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)

void Input_Vector(vector<int> &array, int size){
	int x;
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int LIS_recursion(vector<int> &elements, int start, int end, int *maxlength){
	if (end == start)
		return 1;

	int maxindexlength=1;
	int result = 1;

	fr(i,start,end-1){
		result = LIS_recursion(elements,start,i,maxlength);
		if (elements[i] < elements[end] && result+1> maxindexlength){
			maxindexlength  = result+1;
		}
	}

	if (*maxlength < maxindexlength)
		*maxlength = maxindexlength;

	return maxindexlength;
}

int LIS(vector<int> &elements, int start, int end){
	int n = end-start+1;
	std::vector<int> f(n,-1);
	f[0] = 1;

	fr(i,1,n-1){
		f[i] = 1;
		fr(j,0,i){
			if (elements[start+j] < elements[start+i] && f[i] < f[j] + 1)
				f[i] = f[j] + 1;
		}
	}

	return *max_element(f.begin(),f.end());
}

int main(){
	int n;
	cin >> n;
	std::vector<int> elements(n);
	Input_Vector(elements,n);

	cout << "Recursion:" << endl;
	int maxlength = 1;
	cout <<  LIS_recursion(elements,0,n-1,&maxlength) << endl;
	cout << endl;
	cout << "DP:" << endl;
	cout <<  LIS(elements,0,n-1) << endl;
}