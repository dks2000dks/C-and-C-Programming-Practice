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


int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        stack<int> s;
        stack<int> minstack;

        while(n--){
            int x;
            cin >> x;

            if (x==1){
                int y;
                cin >> y;
                s.push(y);
                if (minstack.empty()){
                    minstack.push(y);
                }
                else{
                    minstack.push(min(minstack.top(),y));
                }
            }

            else if (x==2){
                cout << s.top() << " ";
                s.pop();
                minstack.pop();
            }

            else{
                cout << minstack.top() << " ";
            }
        }

        cout << endl;
    }
}