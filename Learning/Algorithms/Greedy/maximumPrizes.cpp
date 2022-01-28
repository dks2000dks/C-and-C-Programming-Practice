#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

vector<int> optimalsum(int n)
{
  vector<int> summands;
  int i=0;
  while(n > 0)
  {
    i++;
    if (n-i > i)
    {
      summands.push_back(i);
      n = n-i;
    }

    else
    {
      summands.push_back(n);
      n = 0;
    }
  }
  return summands;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands = optimalsum(n);
  std::cout << summands.size() << '\n';

  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }

  cout << endl;
}
