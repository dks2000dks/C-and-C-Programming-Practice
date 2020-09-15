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

// For Large Calculations
int nCr(int n,int r){
    int p = pow(10,9) + 7;
    vec1d(C,ll,r+1,0);
 
    C[0] = 1;
    for (int i=1; i<=n; i++){
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
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

bool isOperation(char c){
    if (c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%')
        return true;
    return false;
}

int PrimeSieve(int n){
    vec1d(prime,bool,n+1,true);

    for(int p=2; p*p <= n; p++){
        if (prime[p] == true){
            for(int i=p*p; i<=n; i+=p)
                prime[i] = false;
        }
    }

    int count = 0;
    fr(p,2,n){
        if (prime[p])
            count++;
    }
    return count;
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

double Mean(vector<int> v){
    int n = v.size();
    return (accumulate(v.begin(),v.end(),0))/(n*1.0);
}

double Median(vector<int> v){
    int n = v.size();
    sort(v.begin(),v.end());

    if (n%2 == 1)
        return 1.0 * v[n/2];
    else
        return 0.5 * (v[(n/2) - 1]) + 0.5 * (v[n/2]);
}

int Mode(vector<int> &v){
    int n = v.size();
    map<int,int> mp;

    fr(i,0,n-1){
        mp[v[i]]++;
    }

    int maxfreq = 0;
    for(auto i:mp)
        maxfreq = max(maxfreq,i.second);

    int minelement = INT_MAX;
    
    for(auto i:mp){
        if (i.second == maxfreq)
            minelement = min(i.first,minelement);
    }

    return minelement;
}