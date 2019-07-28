#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		string input;
		cin >> input;
		int c = 0;

		std::string check ("333");

		for (int i = 0; i < input.length(); i++)
		{
			check.replace(0,3,input,i,3);

			if (check == "010" || check == "101")
			{
				c = 1;
				break;
			}
		}

		if (c == 1)
		{
			cout << "Good" << endl;
		}

		else
		{
			cout << "Bad" << endl;
		}
	}

}