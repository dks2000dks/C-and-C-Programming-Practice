#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int a,n,k,p;
	cin >> a;
	cin >> n;
	cin >> k;

	int b = n + 1;

	int output[k];

	for (int j = 0;j < k;j++)
	{
		output[j] = a%b;
		cout << output[j] << " ";
		a = a/b;
	}

	cout << endl;
}