#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000], n;
vector<int> colors(1000);
int csum(int i, int k)
{
    int ans = 0;
    for (int j = i; j <= k; j++)
    {
        ans += colors[j];
        ans = ans % 100;
    }
    return ans;
}
int smoke(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i >= j)
        return 0;
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j],
                       smoke(i, k) + smoke(k + 1, j) + csum(i, k) * csum(k + 1, j));
    }
    return dp[i][j];
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            cin >> colors[i];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << smoke(0, n - 1) << endl;
    }
    return 0;
}