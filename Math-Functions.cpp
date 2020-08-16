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

int nCr(int n,int r){
    int output = 1;
    if (n - r < r) 
        r = n - r; 
  
    for(int i=n-r+1;i<=n;i++){
        output = output*(i)/(i-n+r);
    }
    return output;
}

int nPr(int n,int r){
    int output = 1;
    if (n - r < r) 
        r = n - r; 
  
    for(int i=n-r+1;i<=n;i++){
        output = output*(i);
    }
    return output;
}

int isvalid(int x, int y, int r, int c){
    return (x>=0 && x<r && y>=0 && y<c);
}

bool isPrime(int n) {  
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

int gcd(int a, int b) {
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 

    if (a == b) 
        return a; 

    if (a > b) 
        return gcd(a%b, b); 

    return gcd(a, b%a); 
} 

char XOR(char a,char b){
	if ((a == '0' && b == '0') || (a == '1' && b == '1'))
		return '0';
	else
		return '1';
}