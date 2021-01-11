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
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

struct Point{
    int x,y;
};

vector<Point> Impacts(Point start, int N){
    vector<Point> o;
    Point p,s;

    if (start.x > start.y){
        // First Impact
        s.x = start.x + min(N-start.x, N-start.y);
        s.y = start.y + min(N-start.x, N-start.y);
        o.push_back(s);
        p = s;

        // Second Impact
        s.x = p.x - min(p.x,N-p.y);
        s.y = p.y + min(p.x,N-p.y);
        o.push_back(s);
        p = s;

        // Third Impact
        s.x = p.x - min(p.x,p.y);
        s.y = p.y - min(p.x,p.y);
        o.push_back(s);
        p = s;

        // Fourth Impact
        s.x = p.x + min(N-p.x,p.y);
        s.y = p.y - min(N-p.x,p.y);
        o.push_back(s);
        s = p;
    }

    else{
        // First Impact
        s.x = start.x + min(N-start.x, N-start.y);
        s.y = start.y + min(N-start.x, N-start.y);
        o.push_back(s);
        p = s;

        // Second Impact
        s.x = p.x + min(N-p.x,p.y);
        s.y = p.y - min(N-p.x,p.y);
        o.push_back(s);
        p = s;

        // Third Impact
        s.x = p.x - min(p.x,p.y);
        s.y = p.y - min(p.x,p.y);
        o.push_back(s);
        p = s;

        // Fourth Impact
        s.x = p.x - min(p.x,N-p.y);
        s.y = p.y + min(p.x,N-p.y);
        o.push_back(s);
        s = p;
    }
    return o;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int N,k,a,b;
        cin >> N >> k >> a >> b;
        Point start;
        start.x = a;
        start.y = b;

        if (a==b)
            cout << N << " " << N << endl;
        else{
            vector<Point> o = Impacts(start, N);
            k = (k-1)%4;
            cout << o[k].x << " " << o[k].y << endl;
        }
    }
}