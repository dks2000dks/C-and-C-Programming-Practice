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

string Common(string str1, string str2){
    string result = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
  
    for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) { 
        if (str1[i] != str2[j]) 
            break;
        result += str1[i]; 
    } 
  
    return result; 
}

string CommonPrefix(vector<string> &v){

    string result = Common(v[0],v[1]);

    if (result == "")
        return result;

    fr(i,2,v.size()-1){
        result = Common(result,v[i]);
        
        if (result == "")
            return result;
    }

    return result;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,string,n,"a");
        fr(i,0,n-1) cin >> v[i];
        
        if (n==1)
            cout << v[0] << endl;
        else{
            string output = CommonPrefix(v);
            if (output.length() > 0)
                cout << output << endl;
            else
                cout << "-1" << endl;   
        }
    }
}