#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define vec1d(v, T, n, init) vector<T> v(n, init)
#define vec2d(v, T, n, m, init) vector<vector<T>> v(n, vector<T>(m, init))

int nCr(int n, int r)
{
    int p = pow(10, 9);
    vec1d(C, ll, r + 1, 0);

    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % p;
    }
    return C[r];
}

void Compute(string s)
{
    bool check = true;
    if (s.length() < 3)
        exit(100);

    fr(i, 0, s.length() - 1)
    {
        if (s[i] == ' ')
            continue;
        else if (isdigit(s[i]))
            continue;
        else
            check = false;
    }

    if (check == true)
    {
        int ind;
        fr(i, 0, s.length() - 1)
        {
            if (s[i] == ' ')
            {
                ind = i;
                break;
            }
        }

        int m = stoi(s.substr(0, ind));
        int n = stoi(s.substr(ind + 1, s.length() - 1 - ind));

        if (m % 2 == 0 || n % 2 == 0)
        {
            int N = m * n;
            int R = m * n / 2;

            string o = to_string(nCr(N, R));

            int t = 9 - o.length();

            while (t--)
            {
                o = "0" + o;
            }
            cout << o;
            exit(0);
        }
        else
        {
            cout << "000000000";
            exit(0);
        }
    }
    else
    {
        exit(100);
    }
}

int main(int argc, char *argv[])
{
    string line;
    int index = 1;
    while (!cin.eof())
    {
        getline(cin, line);
        Compute(line);
    }
    return 0;
}
