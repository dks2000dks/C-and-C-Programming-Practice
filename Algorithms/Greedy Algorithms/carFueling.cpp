#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<bitset>
#include<bits/stdc++.h>
using namespace std;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    stops.insert(stops.begin(),0);
    stops.insert(stops.end(),dist);
    int count = 0;
    int currentrefill = 0;
    int lastrefill = 0;
    int n = stops.size();
    while (currentrefill < n)
    {
        lastrefill = currentrefill;
        while(currentrefill<n && (stops[currentrefill+1]-stops[lastrefill])<=tank)
        {
            currentrefill++;
        }

        if (currentrefill==lastrefill)
            return -1;

        else if (currentrefill<n)
            count++;
    }

    return count;
}


int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << endl;

    return 0;
}
