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

int HashFunction(string s, int m){
    ll p = 1000000007;
    int x = 263;
    int length = s.length();
    ll sum = 0;

    fr(i,0,length-1){
        ll v = pow(x,i);
        int si = (int)s[i];
        ll net = (v*si);

        sum = (sum+net)%p;
    }

    return (int)(sum%m);
}

int main(){
    int m,q;
    cin >> m;
    vector<list<string>> Hash(m);

    cin >> q;

    while(q--){
        string op;
        cin >> op;

        if (op == "add"){
            string word;
            cin >> word;
            int p = HashFunction(word,m);

            Hash[p].push_front(word);
        }

        else if(op == "del"){
            string word;
            cin >> word;
            int p = HashFunction(word,m);

            Hash[p].remove(word);
        }

        else if(op == "find"){
            string word;
            cin >> word;
            int p = HashFunction(word,m);

            list<string>::iterator it;
            it = find(Hash[p].begin(), Hash[p].end(), word);

            if(it != Hash[p].end()){
                cout << "yes" << endl;
            }
            
            else{
                cout << "no" << endl;
            }    
        }

        else{
            int p;
            cin >> p;

            string out = "";

            for(auto it = Hash[p].begin(); it != Hash[p].end(); ++it){
                out = out + *it + " ";
            }

            cout << out << endl;
        }
    }
}