#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (1)
    {
        int n;
        cin >> n;
        int i;
        if (n == 0)
            break;
        stack<int> s;
        int tp;
        ll area, max_area = 0;
        vector<ll> a(n);
        for (i = 0; i < n; i++)
            cin >> a[i];
        i = 0;
        while (i < n)
        {
            if (s.empty() || a[s.top()] <= a[i])
                s.push(i++);
            else
            {
                tp = s.top();
                s.pop();
                area = a[tp] * (s.empty() ? i : i - s.top() - 1);
                if (max_area < area)
                    max_area = area;
            }
        }
        while (s.empty() == false)
        {
            tp = s.top();
            s.pop();
            area = a[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area)
                max_area = area;
        }
        cout << max_area << endl;
    }
}