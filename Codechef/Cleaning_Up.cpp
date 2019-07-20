#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int t=0,T;
	cin >> T;

	while(t < T)
	{
		int n,r;
		cin >> n;
		cin >> r;

		int input[n];
		int remove[r];

		for (int i = 0;i < n;i++)
		{
			input[i] = i + 1;
		}

		for (int i = 0;i < r;i++)
		{
			cin >> remove[i];
		}

		std::sort(remove,remove + r);

		std::vector<int> output(n - r);
		std::vector<int>::iterator it; 

		it=std::set_difference (input, input+n, remove, remove+r, output.begin());
		output.resize(it-output.begin());
		
		int s = output.size();
		int c = s/2;
		int assistant[c];
		int chef[s-c];

		for (int i = 0; i < s; ++i)
    	{
			if (i%2 == 0)
				chef[i/2] = output[i];
			else
				assistant[i/2] = output[i];
    	}
  		
  		for (int i = 0;i < s-c; i++)
  			cout << chef[i] << " ";

  		cout << '\n';

  		for (int i = 0;i < c; i++)
  			cout << assistant[i] << " ";

  		cout << endl;
  		t++;
	}
}