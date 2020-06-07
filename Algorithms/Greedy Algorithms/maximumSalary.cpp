#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

int Compare(string a, string b)
{
    if (stoi(a+b) >= stoi(b+a))
        return 1;
    else
        return 0;
}

string maximumSalary(vector<string> a)
{
    // Similar to Bubble Sort
    int rep = 1;
    while(rep>0)
    {
        rep=0;

        for (int i=0;i<a.size()-1;i++)
        {
            int res = Compare(a[i],a[i+1]);
            if (res==0)
            {
                string c = a[i];
                a[i] = a[i+1];
                a[i+1] = c;
                rep = 1;
            }
        }
    }

    std::stringstream ret;
    for (size_t i = 0; i < a.size(); i++)
    {
        ret << a[i];
    }
    string result;
    ret >> result;
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    std::cout << maximumSalary(a) << endl;;
}
