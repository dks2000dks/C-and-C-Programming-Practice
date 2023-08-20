// Source: https://www.geeksforgeeks.org/generate-all-the-binary-strings-of-n-bits/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)

void printAllBinary(int digitsleft, string soFar){
	if (digitsleft==0)
		cout << soFar << endl;
	else
	{
		printAllBinary(digitsleft-1,soFar+'0');
		printAllBinary(digitsleft-1,soFar+'1');
	}
}

int main()
{
	int n;
	cin >> n;

	printAllBinary(n, "");
}