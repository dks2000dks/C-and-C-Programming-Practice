#include <bits/stdc++.h>
using namespace std;
int main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        stack<int> s;
        vector<int> res;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            while (!s.empty() && s.top() < x)
            {
                res.push_back(s.top());
                s.pop();
            }
            s.push(x);
        }
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (res[i] != i + 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}