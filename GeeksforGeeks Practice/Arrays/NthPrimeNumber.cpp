#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

string Compute(int n){

	int rem; 
	string num;

	while (n) { 
		rem = n % 4; 

		switch (rem){ 
		case 1: 
			num.push_back('2'); 
			break; 

		case 2: 
			num.push_back('3'); 
			break; 

		case 3: 
			num.push_back('5'); 
			break; 

		case 0: 
			num.push_back('7'); 
			break; 
		} 

		if (n % 4 == 0) 
		    n--; 

		n = n/4; 
	}

	reverse(num.begin(), num.end()); 
	return num; 
} 

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        cout << Compute(n) << endl;
    }
}