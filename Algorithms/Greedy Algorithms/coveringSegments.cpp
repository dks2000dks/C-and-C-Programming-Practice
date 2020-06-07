// http://dm.compsciclub.ru/app/quiz-touch-all-segments
// For Simulation
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

struct Segment
{
  long long int start, end;
};

vector<int> optimal_points(vector<Segment> &segments)
{
    vector<int> points;
    while(segments.size() > 0)
    {
        vector<int> stop;
      
        for (size_t i = 0; i < segments.size(); ++i)
        {
            stop.push_back(segments[i].end);
        }

        sort(stop.begin(),stop.end());

        int ind = stop[0];
        points.push_back(ind);

        for (int i=0;i<segments.size();i++)
        {
            if (ind>=segments[i].start && ind<=segments[i].end)
            {
                segments.erase(segments.begin()+i);
                i--;
            }
        }
    }


  return points;
}

int main()
{
  int n;
  std::cin >> n;

  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }

  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";

  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
  cout << endl;
}
